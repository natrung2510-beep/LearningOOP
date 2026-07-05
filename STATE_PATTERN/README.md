# THIẾT KẾ BỘ NÃO KẺ ĐỊCH (MULTILAYER-FSM) CHO GAME TOWER DEFENSE

## 1. Mô tả dự án
Hãy thiết kế bộ não của thực thể Kẻ địch (Enemy/Creep) trong một game Tower Defense. Thay vì sử dụng FSM phẳng, cậu sẽ chia bộ não của nó thành 2 tầng trạng thái hoạt động song song:
* **Tầng Hành động (Action Layer):** Chịu trách nhiệm điều khiển hành vi vật lý của thực thể (MOVE - đang đi, ATTACK - đang phá cổng thành, DEAD - đã chết).
* **Tầng Hiệu ứng (Status Layer):** Chịu trách nhiệm điều khiển trạng thái thuộc tính và chỉ số vật lý (NORMAL - bình thường, FROZEN - làm chậm, STUNNED - bất động hoàn toàn).

---

## 2. Các yêu cầu kiến trúc bắt buộc

### A. Cơ chế Quản lý Bộ nhớ (State Caching)
* **Cấp phát một lần:** Để triệt tiêu hoàn toàn hiện tượng rác RAM (Data Churn) ở runtime, cậu tuyệt đối không được dùng từ khóa `new` hay `delete` khi đang chạy game loop.
* **Mảng con trỏ Cache:** Lớp `Enemy` phải tự khởi tạo sẵn toàn bộ các Concrete State con (`MoveState`, `FrozenStatus`, v.v.) ngay trong Constructor của nó và quản lý chúng bằng hai mảng con trỏ thuộc lớp cha trừu tượng.
* **Dọn dẹp tự động:** Viết Destructor cho `Enemy` để tự động duyệt mảng và giải phóng an toàn 100% vùng nhớ của các State đã được cache.

### B. Cơ chế Chuyển pha Trực tiếp (Mutation-Based)
Lớp `Enemy` phải cung cấp hai phương thức thay đổi trạng thái trực tiếp:
* `void changeAction(ActionType nextType);`
* `void changeStatus(StatusType nextType);`

* **Sử dụng Enum làm Index:** Tham số truyền vào bắt buộc là một kiểu `enum class` đại diện cho ID của trạng thái. Hàm chuyển pha sẽ dùng chính ID này để truy xuất trực tiếp vào mảng Cache tương ứng nhằm gán lại con trỏ hiện tại ($O(1)$ complexity).
* **Vòng đời an toàn (Lifecycle Hooks):** Khi chuyển pha, hệ thống bắt buộc phải chạy tuần tự: gọi hàm `exit()` của trạng thái cũ $\rightarrow$ gán con trỏ hiện tại sang trạng thái mới $\rightarrow$ gọi hàm `enter()` của trạng thái mới.
* **State gõ đầu Context:** Các lớp Concrete State được phép cầm con trỏ `Enemy*` và chủ động gọi hai hàm `changeAction` hoặc `changeStatus` trên đối tượng `Enemy` để kích hoạt chuyển đổi trạng thái.

### C. Quy tắc Thiết lập 2 Tầng não bộ (Multilayer-FSM)

#### Tầng 1: Action Layer
* Interface `ActionState` chứa các phương thức ảo: `enter()`, `exit()`, và `update(Enemy* enemy) = 0;`.
* `MoveState`: Mỗi khung hình tiến hành di chuyển kẻ địch lại gần cổng thành. Khi khoảng cách $\le 0$, nó chủ động gọi `enemy->changeAction(ActionType::ATTACK)`.
* `AttackGateState`: Gây sát thương liên tục lên cổng thành.
* `DeadState`: Vô hiệu hóa mọi cập nhật của kẻ địch khi $\text{HP} \le 0$.

#### Tầng 2: Status Layer
* Interface `EffectState` chứa phương thức ảo `getSpeedModifier() const = 0;` trả về hệ số tốc độ (`float`).
* `NormalStatus`: Trả về hệ số tốc độ là `1.0f` (giữ nguyên 100% tốc độ gốc).
* `FrozenStatus`: Khiến kẻ địch đi chậm lại (hệ số tốc độ là `0.3f`). Trạng thái này giữ một biến đếm số lượt (ticks). Mỗi khung hình giảm đi 1 lượt. Khi bộ đếm về 0, nó tự động gọi `enemy->changeStatus(StatusType::NORMAL)` để giải băng.
* `StunnedStatus`: Khiến kẻ địch bất động hoàn toàn (hệ số tốc độ là `0.0f`). Tự giải trừ sau 1 lượt.

---

## 3. Quy trình Kiểm thử (Game Loop Simulation)
Để chứng minh code hoạt động hoàn hảo, cậu hãy thiết lập hàm `main` giả lập chính xác kịch bản chạy thử sau:
* **Khởi tạo:** Sinh ra một `Enemy` (mặc định xuất phát ở `MoveState` và `NormalStatus`).
* **Khung hình 1 (Di chuyển bình thường):** Gọi `enemy.update()`. Kẻ địch phải di chuyển với tốc độ gốc là `10.0`.
* **Khung hình 2 (Trúng đạn băng):** Gọi `enemy.changeStatus(StatusType::FROZEN)`. Gọi tiếp `enemy.update()`. Kẻ địch phải tự động đi chậm lại chỉ còn tốc độ `3.0`.
* **Khung hình 3 (Hiệu ứng băng tiếp diễn):** Gọi `enemy.update()`. Kẻ địch vẫn đi chậm.
* **Khung hình 4 (Tự động rã băng):** Gọi `enemy.update()`. Hiệu ứng đóng băng tự động hết hạn, kẻ địch tự chuyển về `NormalStatus` và đi với tốc độ `10.0` ban đầu.
* **Khung hình 5 (Bị tiêu diệt):** Gọi `enemy.takeDamage(120)`. Kẻ địch nhận sát thương chí mạng, $\text{HP} \le 0$ và tự động chuyển sang `DeadState`.

---

## 4. Gợi ý từ Architect để tránh lỗi biên dịch (Pro-Tips)
* Để giải quyết triệt để lỗi biên dịch chéo (*Circular Dependency*), hãy sử dụng **Forward Declaration** bằng cách đặt dòng `class Enemy;` lên đầu file trước khi khai báo các Interface State.
* Chỉ khai báo nguyên mẫu hàm (prototype) bên trong các lớp State con. Phần thân hàm xử lý logic (đặc biệt là các chỗ gọi hàm của `Enemy`) chỉ được viết ở phía dưới cùng của file, sau khi cấu trúc của lớp `Enemy` đã được compiler nhận diện đầy đủ.

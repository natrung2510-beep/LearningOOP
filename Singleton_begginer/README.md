# HƯỚNG DẪN THIẾT KẾ VÀ CÀI ĐẶT SINGLETON PATTERN (CRTP)

## PHẦN 1: Thiết kế Lớp Template Cha `Singleton<T>`
Lớp này đóng vai trò là "khung xương" để đúc ra bất kỳ lớp Singleton nào khác trong tương lai.

* **Tính chất Template:** Định nghĩa lớp dưới dạng template: `template <typename T> class Singleton`.
* **Chặn khởi tạo tự do:** Chuyển *Constructor* và *Destructor* của lớp cha về phạm vi `protected` để ngăn chặn việc tạo trực tiếp đối tượng lớp cha, nhưng vẫn cho phép các lớp con kế thừa.
* **Chặn sao chép:** Sử dụng từ khóa `= delete` để xóa hoàn toàn *Copy Constructor* và *Assignment Operator* ở phạm vi `public`.
* **Cung cấp điểm truy cập tĩnh:** Viết hàm `static public getInstance()` trả về tham chiếu (`T&`) của lớp con.
    * *Yêu cầu:* Bên trong hàm này, khai báo một biến `static` cục bộ kiểu `T` (áp dụng mô hình **Meyers' Singleton**) và trả về nó.

---

## PHẦN 2: Cài đặt 2 Lớp Manager Con (Kế thừa từ Singleton)

### 1. Lớp `WaveManager`
Lớp này chịu trách nhiệm quản lý tiến trình các đợt tấn công của quái vật.

* **Kế thừa CRTP:** Cho `WaveManager` kế thừa từ `Singleton<WaveManager>`.
* **Đóng gói và Cấp quyền:**
    * Ẩn constructor và destructor của `WaveManager` trong phạm vi `private`.
    * Khai báo `friend class Singleton<WaveManager>;` để lớp cha có quyền khởi tạo đối tượng lớp con.
* **Thuộc tính (`private`):**
    * `currentWave` (kiểu `int`, khởi tạo mặc định bằng `1`): Lưu chỉ số đợt quái hiện tại.
    * `monstersAlive` (kiểu `int`, khởi tạo mặc định bằng `0`): Số lượng quái vật hiện đang còn sống trên bản đồ.
* **Phương thức (`public`):**
    * `startNextWave(int spawnCount)`: Đặt số lượng quái sống bằng `spawnCount`, in ra màn hình thông báo bắt đầu wave mới (ví dụ: *"Wave 1 bắt đầu với 3 quái"*), sau đó tăng biến `currentWave` lên 1 đơn vị.
    * `monsterDefeated()`: Nếu `monstersAlive` lớn hơn `0` thì trừ đi `1` và in ra số lượng quái còn lại.
    * `getMonstersAlive()`: Hàm getter trả về số lượng quái còn sống.

### 2. Lớp `EconomyManager`
Lớp này quản lý tài chính và tài nguyên mua tháp phòng thủ của người chơi.

* **Kế thừa CRTP:** Cho `EconomyManager` kế thừa từ `Singleton<EconomyManager>`.
* **Đóng gói và Cấp quyền:**
    * Ẩn constructor và destructor trong phạm vi `private`.
    * Khai báo `friend class Singleton<EconomyManager>;`.
* **Thuộc tính (`private`):**
    * `playerGold` (kiểu `int`, khởi tạo mặc định bằng `100` vàng).
* **Phương thức (`public`):**
    * `earnGold(int amount)`: Cộng thêm tiền cho người chơi và in ra màn hình tổng số vàng hiện có.
    * `buyTower(int cost)`: Kiểm tra xem `playerGold` có đủ mua tháp không.
        * *Nếu đủ:* Trừ tiền, in ra thông báo mua thành công và lượng tiền còn lại, trả về `true`.
        * *Nếu không đủ:* In ra cảnh báo không đủ tiền và trả về `false`.

---

## PHẦN 3: Viết kịch bản kiểm thử trong hàm `main()`

Em hãy viết các lệnh trong hàm `main()` để mô phỏng chính xác kịch bản chơi game sau đây thông qua việc gọi các hàm `getInstance()` của hai Manager:

* **Hành động 1 (Xây tháp ban đầu):** Người chơi yêu cầu xây tháp phòng thủ đầu tiên với giá 70 vàng. Gọi `EconomyManager` để xử lý giao dịch này.
* **Hành động 2 (Quái xuất hiện):** Trận đấu bắt đầu! Gọi `WaveManager` để kích hoạt Wave 1 với số lượng quái xuất hiện là 3 con.
* **Hành động 3 (Mô phỏng diệt quái kiếm tiền):**
    * *Tiêu diệt con quái thứ nhất:* Gọi `WaveManager` báo quái giảm, đồng thời gọi `EconomyManager` cộng thưởng 30 vàng cho người chơi.
    * *Tiêu diệt con quái thứ hai:* Thực hiện tương tự (báo giảm quái và cộng thêm 30 vàng).
* **Hành động 4 (Cố gắng xây thêm tháp):** Người chơi muốn xây thêm một chiếc tháp thứ hai đắt đỏ hơn với giá 80 vàng. Hãy gọi `EconomyManager` để thực hiện mua tháp này và xem hệ thống xử lý thế nào (có đủ tiền hay không).
* **Hành động 5 (Dọn dẹp tự động):** Chương trình kết thúc (hàm `main` kết thúc). Quan sát xem trình biên dịch có tự động kích hoạt Destructor của cả hai lớp Manager để giải phóng bộ nhớ hay không.

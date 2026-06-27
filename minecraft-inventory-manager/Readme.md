# ĐỀ BÀI: HỆ THỐNG QUẢN LÝ VẬT PHẨM (GAME INVENTORY)

## 📌 YÊU CẦU 1: HỆ SINH THÁI VẬT PHẨM (Kế thừa & Đa hình)
Thiết kế một **Lớp cha trừu tượng (Abstract Base Class)** tên là `Item`.

### 🔹 Thuộc tính cơ bản (protected):
- `Tên vật phẩm` (string)
- `Độ hiếm` (`Rarity` - số nguyên từ 1 đến 5)
- `Số lượng` (`Quantity`)

### 🔹 Các hàm thành viên:
- **Hàm thuần ảo (Pure Virtual):** `useItem()` - Định nghĩa cách vật phẩm này được sử dụng.
- **Hàm nhân bản:** `clone()` - Hàm đặc biệt dùng để trả về một bản sao (nằm trên vùng nhớ động mới) của chính vật phẩm đó. *(Rất quan trọng cho việc Deep Copy sau này)*.

### 🔹 Tạo 3 Lớp con kế thừa từ Item:
1. **Weapon (Vũ khí):** 
   - Có thêm thuộc tính `Sát thương`.
   - Khi `useItem()` được gọi, in ra: `"Vung vũ khí gây ra X sát thương!"`.
2. **Block (Khối xây dựng):** 
   - Khi `useItem()` được gọi, in ra: `"Đặt một khối xuống đất!"`.
3. **Potion (Thuốc):** 
   - Khi `useItem()` được gọi, in ra: `"Uống thuốc ực ực, hồi phục năng lượng!"`.

---

## 📌 YÊU CẦU 2: TOÁN TỬ VẠN NĂNG (Nạp chồng toán tử - Operator Overloading)
Bên trong lớp `Item`, hãy nạp chồng các toán tử sau để giúp code trở nên "thanh lịch":

* **Toán tử `==` (So sánh bằng):** Trả về `true` nếu hai Item có cùng tên và cùng loại. Dùng để kiểm tra xem có gộp đồ được không.
* **Toán tử `+` (Cộng gộp):** Nếu 2 Item giống nhau, khi cộng lại sẽ tạo ra một Item cùng loại có số lượng bằng tổng 2 số lượng cũ.
  > **Ví dụ:** 10 Khối Đất + 15 Khối Đất = 25 Khối Đất.
* **Toán tử `<<` (Xuất luồng - friend function):** Dùng để in thông tin Item ra màn hình theo định dạng chuẩn.
  > **Ví dụ định dạng:** `[Kiếm Kim Cương | Hiếm: 5 | SL: 1 | ST: 7]`

---

## 📌 YÊU CẦU 3: TRÁI TIM BỘ NHỚ (Quy tắc 3 - The Big Three)
Thiết kế Lớp `Inventory` (Túi đồ). Đây là nơi cạm bẫy bộ nhớ chực chờ.

* **Cấu trúc dữ liệu:** Thay vì mảng string tĩnh, túi đồ phải dùng một **Mảng con trỏ động chứa Lớp cha (`Item** slots`)** để chứa được mọi loại Lớp con (Áp dụng tính chất Đa hình).
* **Thuộc tính:** `capacity` (sức chứa tối đa), `count` (số lượng slot đang dùng).
* **Nhiệm vụ sinh tử:** Phải tự tay cài đặt hoàn chỉnh **Bộ ba thánh kỷ (The Big Three)**:
  1. **Hàm hủy (`~Inventory()`):** Giải phóng từng món đồ trong mảng, sau đó giải phóng luôn mảng con trỏ.
  2. **Hàm dựng sao chép (`Inventory(const Inventory& other)`):** Sao chép sâu (Deep copy). 
     > *Chú ý:* Vì mảng chứa con trỏ lớp cha `Item*`, bạn phải dùng tính năng đa hình (gọi hàm `clone()` của từng món đồ) để copy chính xác nó là Vũ khí hay Thuốc, không thể copy mù quáng.
  3. **Toán tử gán (`operator=`):** Đừng quên kiểm tra bẫy tự gán (Self-assignment) và dọn sạch túi cũ trước khi nhận đồ mới!

---

## 📌 YÊU CẦU 4: THỬ THÁCH THUẬT TOÁN (Cấu trúc dữ liệu & Giải thuật)
Bổ sung 2 tính năng nâng cao sau vào lớp `Inventory`:

### 1. Tính năng Thêm đồ (Add & Merge)
Khi gọi `inventory.addItem(Item* newItem)`, thuật toán phải duyệt qua túi đồ:
- **Nếu thấy món đồ đã tồn tại** (sử dụng `operator==`), nó không chiếm slot mới mà tự động cộng gộp số lượng vào món cũ (sử dụng `operator+`).
- **Nếu chưa có**, mới tiến hành nhét vào slot trống tiếp theo.

### 2. Tính năng Sắp xếp (Sort Inventory)
Viết hàm `sortInventory()` để sắp xếp mảng `slots`. **Không được dùng thư viện có sẵn (như std::sort)**. Hãy tự cài đặt thuật toán *Insertion Sort* hoặc *Selection Sort* theo tiêu chí:
- **Ưu tiên 1:** Độ hiếm (`Rarity`) giảm dần (Đồ VIP lên đầu).
- **Ưu tiên 2:** Nếu cùng độ hiếm, sắp xếp theo Số lượng (`Quantity`) giảm dần.

---

## 🛠️ CÁCH THỰC HIỆN
Dự án này hội tụ đủ 100% tinh hoa của nửa đầu môn Lập trình hướng đối tượng (OOP). Bạn chưa cần viết hàm `main` vội, hãy đi theo các bước:

* **Bước 1:** Tự tạo các file `.h` và `.cpp` (hoặc nháp trên 1 file đơn lẻ).
* **Bước 2:** Suy nghĩ thiết kế Lớp `Item` và mối quan hệ Kế thừa trước.
* **Bước 3:** Lên khung lớp `Inventory` với mảng động và Quy tắc 3.
* **Bước 4:** Áp dụng thuật toán vào các hàm thêm/sắp xếp.

# 📝 ĐỀ BÀI: CHIẾC RƯƠNG KHO BÁU (TREASURE BOX)

## 📌 Yêu cầu 1: Khởi tạo Lớp cơ sở (Class Template)
Hãy tạo một lớp khuôn mẫu tên là `Box<T>`.

* **Thuộc tính (protected):** `item` mang kiểu dữ liệu `T`.
* **Constructor:** Nhận vào 1 tham số kiểu `T` để gán giá trị cho `item`.
* **Hàm thành viên:** `T getItem()` dùng để lấy vật phẩm ra.

---

## 📌 Yêu cầu 2: Kế thừa (Template Inheritance) - Vượt qua cạm bẫy
Tạo một lớp khuôn mẫu `MagicBox<T>` kế thừa từ lớp `Box<T>`.

* Inside `MagicBox<T>`, viết một hàm `void showItem()`. 
* Hàm này sẽ in ra màn hình dòng chữ theo mẫu: 
  > `"Kho bau ben trong la: " + [giá trị của item]`

---

## 📌 Yêu cầu 3: Lớp bạn (Friend & Operator Overloading)
Thay vì phải gọi hàm `showItem()` dài dòng, hãy nạp chồng toán tử `<<` cho lớp `MagicBox<T>`.

* **Mục đích:** Để trong hàm `main()`, chỉ cần gõ `cout << myMagicBox;` là hệ thống tự động in ra thông tin vật phẩm giống như hàm `showItem()`.

---

## 📌 Yêu cầu 4: Chạy thử trong hàm main()
Hãy khởi tạo **2 rương kho báu** cụ thể trong hàm `main()` để kiểm tra:

1. **Rương chứa tiền (kiểu `int`):** Bỏ vào `5000000` Beli.
2. **Rương chứa trái ác quỷ (kiểu `string`):** Bỏ vào `"Gomu Gomu no Mi"`.
 Sử dụng lệnh `cout <<` để in trực tiếp thông tin của 2 chiếc rương này ra màn hình.

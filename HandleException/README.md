# 🏦 BÀI TẬP: HỆ THỐNG QUẢN LÝ GIAO DỊCH VÍ ĐIỆN TỬ (SECURE E-WALLET)

## 📌 1. Bối cảnh dự án (Scenario)
Trong các hệ thống tài chính (Fintech/Banking), sự bảo toàn dữ liệu là yếu tố sống còn. Một giao dịch rút tiền hoặc chuyển tiền không hợp lệ tuyệt đối không được phép làm thay đổi trạng thái số dư của người dùng. Hệ thống không được phép "crash" đột ngột khi người dùng nhập sai, mà phải ghi nhận lại chính xác nguyên nhân lỗi để báo cáo.

Nhiệm vụ của bạn là xây dựng core logic cho class `Wallet` (Ví điện tử) với cơ chế phòng vệ nghiêm ngặt bằng **Exception Handling**.

---

## 📌 2. Yêu cầu thiết kế Lớp Ngoại Lệ (Custom Exceptions)
Bạn phải tự định nghĩa một hệ sinh thái lỗi của riêng module giao dịch. Tất cả phải tuân thủ chuẩn C++ hiện đại:

* **Lớp `TransactionException`:** 
  - Là lớp cha (Base class) đại diện cho mọi lỗi liên quan đến giao dịch. 
  - Kế thừa từ `std::exception` (hoặc `std::runtime_error`). 
  - Cần ghi đè phương thức trả về chuỗi thông báo lỗi (`what()`).
* **Lớp `InvalidAmountException`:** 
  - Kế thừa từ `TransactionException`. 
  - Ném ra khi người dùng nhập số tiền âm hoặc bằng 0. 
  - *Thông báo:* `"Lỗi: Số tiền giao dịch phải lớn hơn 0!"`
* **Lớp `InsufficientFundsException`:** 
  - Kế thừa từ `TransactionException`. 
  - Ném ra khi số dư trong ví không đủ để thực hiện giao dịch rút tiền. 
  - *Thông báo:* `"Lỗi: Số dư không đủ để thực hiện giao dịch!"`

---

## 📌 3. Yêu cầu Lớp Nghiệp vụ (Wallet)
Thiết kế lớp `Wallet` với các đặc tả sau:

* **Thuộc tính:** 
  - `std::string ownerName` (Tên chủ ví)
  - `double balance` (Số dư)
* **Constructor:** Khởi tạo ví với tên và số dư ban đầu. *(Nếu số dư ban đầu < 0, ném ra ngoại lệ chuẩn `std::invalid_argument`)*.
* **Phương thức `get_balance()`:** Trả về số dư hiện tại. 
  > **💡 Gợi ý tối ưu:** Hãy dùng từ khóa phù hợp (`const` / `noexcept`) để báo cho Trình biên dịch biết hàm này tuyệt đối an toàn, giúp tăng tốc độ thực thi.
* **Phương thức `deposit(double amount)`:** Nạp tiền. Nếu `amount <= 0`, ném ra `InvalidAmountException`. Nếu hợp lệ, cộng tiền vào `balance`.
* **Phương thức `withdraw(double amount)`:** Rút tiền quy trình kiểm duyệt:
  - Nếu `amount <= 0` \(\rightarrow\) Ném `InvalidAmountException`.
  - Nếu `amount > balance` \(\rightarrow\) Ném `InsufficientFundsException`.
  - Nếu `amount > 20000000` (Hạn mức 20 triệu/lần) \(\rightarrow\) Ném `TransactionException` với lời nhắn: `"Lỗi giao dịch chung: Giao dịch vượt quá hạn mức cho phép!"`.
  - Nếu vượt qua hết các khâu kiểm duyệt trên \(\rightarrow\) Tiến hành trừ tiền trong `balance`.

---

## 📌 4. Nhiệm vụ tại hàm main() & ⚠️ Cạm bẫy tư duy
Trong hàm `main()`, hãy tạo một `Wallet` có số dư ban đầu là **5.000.000 VNĐ**. Thực hiện một kịch bản gọi liên tiếp các giao dịch trong chỉ **MỘT khối `try` duy nhất** (Nếu lỗi ở đâu, chương trình sẽ văng ra `catch` tương ứng).

Bạn cần viết các khối `catch` để bắt:
1. `InsufficientFundsException`
2. `InvalidAmountException`
3. `TransactionException`
4. `std::exception` (Bắt các lỗi hệ thống hoặc lỗi khi khởi tạo ví âm tiền).

### 🔴 Cạm bẫy số 1: Thứ tự kế thừa (Catch Order)
Hãy sắp xếp các khối `catch` thật logic. Nếu sắp xếp sai, các lỗi con (như Thiếu tiền, Sai số tiền) sẽ bị "nuốt chửng" bởi khối bắt lỗi cha, dẫn đến việc không thể xác định chính xác người dùng đã vi phạm quy tắc gì.

### 🔴 Cạm bẫy số 2: Vật thể bị cắt cụt (Object Slicing)
Đảm bảo cú pháp nhận tham số trong ngoặc đơn của `catch` không làm mất đi tính đa hình của ngoại lệ (nhớ nguyên tắc **Catch by Reference**: `const Exception& e`). Các câu thông báo lỗi phải được in ra bằng luồng dữ liệu dành riêng cho lỗi (sử dụng `std::cerr` thay vì `std::cout`).

---

## 🖥️ 5. Output mong đợi (Expected Output)
Dưới đây là mô phỏng khi bạn cố tình chạy các giao dịch sai quy tắc. Hãy đối chiếu xem chương trình của bạn có in ra đúng luồng và đúng chuyên khoa "bắt bệnh" không:

```text
--- KHOI TAO HE THONG ---
[Hệ thống] Tao vi dien tu thanh cong cho khach hang: Nguyen Van A. So du: 5,000,000 VND

--- BAT DAU GIAO DICH ---
[Giao dich 1] Nap 1,000,000 VND...
Thanh cong! So du hien tai: 6,000,000 VND

[Giao dich 2] Rut -500,000 VND...
[LOG LOI - INVALID AMOUNT] Loi: So tien giao dich phai lon hon 0!

[Giao dich 3] Rut 10,000,000 VND...
[LOG LOI - INSUFFICIENT] Loi: So du khong du de thuc hien giao dich!

[Giao dich 4] Rut 25,000,000 VND...
[LOG LOI - TRANSACTION] Lỗi giao dịch chung: Giao dich vuot qua han muc 20 trieu/lan!

--- TONG KET ---
Chuong trinh ket thuc an toan. So du cuoi cung an toan: 6,000,000 VND
```

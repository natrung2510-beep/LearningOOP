# BÀI TẬP THỰC HÀNH - TUẦN 5: NẠP CHỒNG TOÁN TỬ (OPERATOR OVERLOADING)

## Bài tập 1: Nạp chồng toán tử cho lớp Phân Số (Sử dụng con trỏ)

Hãy viết chương trình C++ cài đặt lại lớp Phân Số, trong đó các thuộc tính được định nghĩa bằng biến con trỏ như sau:

```cpp
class PhanSo
{
private:
    int *tuso;
    int *mauso;
};
```

### Yêu cầu thực hiện:
Cài đặt nạp chồng các toán tử cho lớp `PhanSo` với cả 2 ngôi đều có chung kiểu đối tượng `PhanSo` (lưu ý cần cài đặt đầy đủ tất cả các phương thức tạo lập và hủy có liên quan để quản lý vùng nhớ động, tránh gây lỗi chương trình):

*   **Toán tử gán bằng:** `=` (thực hiện sao chép sâu - Deep Copy).
*   **Toán tử số học cơ bản:** `+`, `-`, `*`, `/`.
*   **Toán tử số học kết hợp gán:** `+=`, `-=`, `*=`, `/=`.
*   **Toán tử so sánh (quan hệ):** `==`, `!=`, `<`, `>`, `<=`, `>=`.
*   **Toán tử tăng/giảm một đơn vị:** `++`, `--` (yêu cầu cài đặt cả hai dạng **tiền tố (prefix)** và **hậu tố (postfix)**).
*   **Toán tử nhập/xuất luồng:** `>>`, `<<` (nhập xuất thông qua Console, hiển thị phân số theo định dạng `tử số / mẫu số`).

---

## Bài tập 2: Nạp chồng toán tử cho lớp Mảng Số Nguyên Động

Hãy viết chương trình C++ cài đặt lớp Mảng số nguyên để quản lý một mảng động và định nghĩa các toán tử hỗ trợ xử lý mảng. Các thuộc tính của lớp được khai báo như sau:

```cpp
class MangSoNguyen
{
private:
    int* dulieu;     // Con trỏ trỏ đến một mảng động kiểu số nguyên
    int kichthuoc;   // Biến lưu trữ kích thước thực tế của mảng
};
```

### Yêu cầu thực hiện:
Cài đặt nạp chồng các toán tử cho lớp `MangSoNguyen`. Lưu ý cần cài đặt tất cả các phương thức tạo lập (Constructor), tạo lập sao chép (Copy Constructor) và phương thức hủy (Destructor) để chương trình hoạt động an toàn:

*   **Toán tử gán bằng (`=`):** Cho phép gán và sao chép từng giá trị số nguyên từ một mảng số nguyên này sang một mảng số nguyên khác.
*   **Toán tử cộng (`+`):** Cho phép cộng 2 mảng số nguyên theo cơ chế cộng từng giá trị phần tử tại các vị trí tương ứng.
    *   *Quy tắc cộng khi lệch kích thước:* Nếu hai mảng có kích thước khác nhau, chỉ thực hiện cộng các phần tử có chỉ số trùng nhau, các phần tử thừa ra ở mảng dài hơn sẽ được giữ nguyên giá trị ban đầu.
    *   *Ví dụ minh họa:*

| Mảng | Phần tử index 0 | Phần tử index 1 | Phần tử index 2 |
| :--- | :---: | :---: | :---: |
| **Mảng a** | 1 | 2 | 3 |
| **Mảng b** | 4 | 5 | 6 |
| **Mảng $a + b$** | **5** | **7** | **9** |

*   **Toán tử tiền tố và hậu tố (`++`):** Cho phép tăng đồng loạt tất cả các phần tử có trong mảng số nguyên lên 1 đơn vị.
*   **Toán tử nhập/xuất luồng (`>>`, `<<`):** Cho phép nhập kích thước, giá trị và xuất toàn bộ các phần tử của mảng số nguyên ra màn hình.

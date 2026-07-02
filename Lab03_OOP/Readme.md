# 4. Bài tập thực hành

**Bài tập:** Viết chương trình C++ cài đặt đối tượng Nhân viên, trong đó nhân viên được miêu tả có các thông tin sau:
* **Họ tên** của nhân viên, kiểu chuỗi (`string`).
* **Số ngày làm việc** của nhân viên, kiểu số nguyên dương (`int`).
* **Tên gọi** của nhân viên, kiểu chuỗi, được tạo bằng một chuỗi chứa thông tin chức danh kết hợp với họ tên.
    * *Ví dụ:* Nhân viên có tên là “Thanh”, có chức danh là “Quản lý”, vậy tên gọi của nhân viên được chương trình tạo sẽ là chuỗi “Quản lý Thanh”.
* **Chức danh** của nhân viên, kiểu chuỗi, được chương trình tự tạo dựa trên thông tin số ngày làm việc cụ thể như sau:

| Số ngày làm việc | Chức danh |
| :--- | :--- |
| Từ 0 đến 365 ngày | Nhân viên |
| Từ 365 ngày đến 730 ngày | Quản lý |
| Từ 730 ngày đến 1460 ngày | Trưởng phòng |
| Trên 1460 ngày | Trưởng ban quản lý |

* **Hệ số lương** của nhân viên, kiểu số thực dương (`float`/`double`), được chương trình tính dựa trên thông tin chức danh cụ thể như sau:

| Chức danh | Hệ số lương |
| :--- | :--- |
| Nhân viên | 1.0 |
| Quản lý | 1.5 |
| Trưởng phòng | 2.25 |
| Trưởng ban quản lý | 4.0 |

---

### Yêu cầu thực hiện:

**a.** Hãy viết các phương thức Getter, Setter cho toàn bộ thuộc tính cần thiết của lớp `NhanVien`.

**b.** Sinh viên hãy viết các phương thức khởi tạo và hủy như sau:
* Phương thức tạo lập mặc định (Default constructor) với giá trị mặc định tùy chọn.
* Phương thức tạo lập với 5 tham số, ứng với 5 thông tin mô tả.
* Phương thức tạo lập với 2 tham số gồm **họ tên** và **số ngày làm việc** (các thông tin khác sinh viên tự xử lý theo yêu cầu mô tả, không sử dụng tham số mặc định).
* Phương thức tạo lập sao chép (Copy constructor), chỉ sao chép *chức danh*, *hệ số lương* và *số ngày làm việc*, ngoài ra các thông tin còn lại được tạo lập mặc định.
* Phương thức hủy (Destructor) cho lớp `NhanVien`.

**c.** Sinh viên hãy viết phương thức để nhập và xuất thông tin lớp `NhanVien`.

**d.** Cho biết thứ tự gọi phương thức tạo lập và phương thức hủy của đoạn chương trình sau (phân biệt dựa theo thông tin họ tên):

```cpp
void main()
{
    NhanVien a("Dat Thanh", 800);
    NhanVien b(a);
    b.SetHoTen("Hai Dang");
    
    for (int i = 0; i < 5; i++)
    {
        NhanVien clone = b;
        clone.SetHoTen("De tu thu " + to_string(i) + " cua " + b.GetChucDanh() + " " + b.GetHoTen());
    }
}

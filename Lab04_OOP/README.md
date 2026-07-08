

```text
# BÀI TẬP THỰC HÀNH - TUẦN 4: CON TRỎ VÀ VÙNG NHỚ ĐỘNG TRONG OOP

## Bài tập 1: Cài đặt lớp Phân Số sử dụng con trỏ

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

* **Xây dựng các phương thức khởi tạo và hủy:** * Phương thức tạo lập mặc định (Default constructor).
* Phương thức tạo lập 1 tham số.
* Phương thức tạo lập 2 tham số.
* Phương thức tạo lập sao chép (Copy constructor - thực hiện *Deep Copy*).
* Phương thức hủy (Destructor) để giải phóng vùng nhớ động một cách an toàn.


* **Xây dựng các phương thức bổ trợ:**
* Cài đặt đầy đủ các hàm Getter và Setter cho toàn bộ thuộc tính của lớp.
* Phương thức cho phép nhập và xuất thông tin của lớp Phân Số:
* Xuất theo định dạng: `tử số / mẫu số`.
* Xuất theo định dạng kết quả phép chia của tử số và mẫu số (hiển thị dưới dạng số thập phân).




* **Xây dựng các phương thức toán học:**
* Viết các phương thức cộng, trừ, nhân, chia 2 phân số.
* *Lưu ý:* Các phép tính toán này tuyệt đối không được làm thay đổi giá trị thuộc tính gốc của cả 2 phân số đầu vào.



---

## Bài tập 2: Quản lý Hệ thống Tướng và Chiêu thức (Game RTS)

Bạn đang tập xây dựng một trò chơi chiến thuật thời gian thực (RTS). Trong đó, bạn phụ trách phần xây dựng kiến trúc và hệ thống quản lý cho lớp các tướng chỉ huy của các binh đoàn tộc hệ có trong trò chơi. Sau khi thống nhất ý tưởng, cấu trúc thông tin của một vị tướng (`Hero`) và một chiêu thức (`Skill`) được thiết kế như sau:

### 1. Cấu trúc các Lớp đối tượng

```cpp
class Skill 
{
private:
    string skillName;
    unsigned int skillLevel; // Cấp cần thiết để mở chiêu thức
};

class Hero 
{
private:
    string heroName;
    unsigned int heroHealth;
    unsigned int heroMana;
    unsigned int heroLevel;
    vector<Skill*> skillList; // Danh sách các con trỏ quản lý chiêu thức
};

```

### 2. Yêu cầu thực hiện:

* **Phương thức cơ bản:** Sinh viên hãy cài đặt đầy đủ các phương thức khởi tạo (bao gồm cả khởi tạo mặc định, tham số và khởi tạo sao chép), phương thức hủy (giải phóng vùng nhớ động trong vector), cùng các hàm Getter, Setter, phương thức nhập và xuất thông tin cho cả 2 lớp `Hero` và `Skill`.
* **Phương thức nâng cao (Tầm vực `public`):**
* **Kiểm tra khả năng học kỹ năng:** Thực hiện kiểm tra và xuất ra danh sách tất cả các `Skill` mà `Hero` có khả năng học được tại thời điểm hiện tại (dựa trên việc so sánh cấp độ hiện tại của Hero với cấp độ cần thiết của chiêu thức).
* **Cắt bớt kỹ năng:** Viết hàm cắt bớt $n$ phần tử `Skill` ở cuối danh sách, với số lượng $n$ được nhập trực tiếp từ Console:
* Xóa và giải phóng bộ nhớ của $n$ kỹ năng cuối cùng.
* *Trường hợp đặc biệt:* Nếu số lượng $n$ do người dùng nhập vào lớn hơn hoặc bằng tổng số lượng `Skill` hiện có trong danh sách, hệ thống sẽ tiến hành xóa và giải phóng toàn bộ danh sách chiêu thức của vị tướng.





```

```

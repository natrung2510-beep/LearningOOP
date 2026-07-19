# Đề Thi Thử Giữa Kỳ - Môn Lập Trình Hướng Đối Tượng (Thực Hành)

* **Thời gian làm bài:** 120 phút
* **Hình thức:** Thực hành trên máy, không sử dụng Internet
* **Quy định tài liệu:** Được sử dụng mã nguồn và tài liệu đã chuẩn bị sẵn dưới dạng offline trên máy cục bộ.

---

## Yêu Cầu Chung

1. Sinh viên tự quản lý bộ nhớ động bằng con trỏ, **không sử dụng** `std::vector` hoặc các container có sẵn của thư viện chuẩn STL.
2. Sinh viên áp dụng kiến thức Kế thừa cơ bản (**KHÔNG** sử dụng từ khóa `virtual` hoặc cơ chế hàm ảo/đa hình động).
3. Mã nguồn phải được tổ chức tối ưu, viết đúng cú pháp và không để xảy ra hiện tượng rò rỉ bộ nhớ (memory leak).

---

## Bài Toán: Hệ Thống Xử Lý Ma Trận Phân Tầng

Một kỹ sư cần xây dựng một thư viện toán học nhỏ để xử lý các loại ma trận khác nhau phục vụ cho đồ họa máy tính. Hãy giúp kỹ sư này thiết kế và cài đặt hệ thống lớp bằng C++ theo các yêu cầu chi tiết dưới đây.

### Câu 1: Thiết kế Lớp Cơ Sở `Matrix` (2.5 điểm)

Xây dựng lớp `Matrix` mô tả một ma trận tổng quát có kích thước bất kỳ (M dòng, N cột).

* Khai báo các thuộc tính với phạm vi truy cập `protected`: số dòng (`rows`), số cột (`cols`) và con trỏ cấp hai (`int** data`) để quản lý mảng hai chiều được cấp phát động trên vùng nhớ Heap.
* Cài đặt Constructor mặc định (khởi tạo các giá trị kích thước bằng 0 và con trỏ bằng `nullptr`).
* Cài đặt Parameterized Constructor `Matrix(int r, int c)` thực hiện cấp phát động vùng nhớ tương ứng cho ma trận kích thước `r x c` và khởi tạo toàn bộ các phần tử bên trong bằng 0.

### Câu 2: Quản Lý Bộ Nhớ Động - Quy Tắc Bộ Ba (Rule of Three) (3.0 điểm)

Để đảm bảo lớp `Matrix` hoạt động an toàn khi truyền tham trị, nạp chồng toán tử và ngăn ngừa lỗi xung đột vùng nhớ, hãy cài đặt trọn vẹn Quy tắc bộ ba:

* Cài đặt **Destructor** (`~Matrix()`) thực hiện giải phóng hoàn toàn vùng nhớ Heap đã cấp phát cho ma trận theo đúng thứ tự (giải phóng các mảng dòng trước khi giải phóng mảng con trỏ chính).
* Cài đặt **Copy Constructor** (`Matrix(const Matrix& other)`) để thực hiện sao chép sâu (Deep Copy) toàn bộ cấu trúc kích thước và dữ liệu phần tử từ ma trận này sang ma trận khác khi khởi tạo đối tượng mới.
* Nạp chồng **Toán tử gán sao chép** (`Matrix& operator=(const Matrix& other)`) đảm bảo cơ chế chống tự gán (self-assignment), dọn dẹp vùng nhớ cũ của đối tượng hiện tại trước khi thực hiện cấp phát mới và sao chép sâu dữ liệu từ đối tượng `other`.

### Câu 3: Nạp Chồng Toán Tử - Operator Overloading (2.5 điểm)

Cài đặt các toán tử thành phần hoặc hàm bạn phù hợp cho lớp `Matrix`:

* Nạp chồng toán tử nhập (`>>`) và xuất (`<<`) dưới dạng hàm `friend` để thực hiện nhập dữ liệu trực tiếp từ `cin` và hiển thị cấu trúc ma trận ra màn hình qua `cout` dưới dạng bảng (ngay hàng thẳng lối, sử dụng `std::setw` nếu cần).
* Nạp chồng phép cộng (`operator+`): Cộng hai ma trận có cùng kích thước. Nếu kích thước không tương thích, thông báo lỗi và trả về một ma trận rỗng.
* Nạp chồng phép nhân (`operator*`): Nhân hai ma trận hợp lệ (số cột ma trận trước bằng số dòng ma trận sau). Nếu kích thước không hợp lệ, thông báo lỗi và trả về một ma trận rỗng.
* Nạp chồng toán tử truy xuất phần tử `operator()` nhận vào hai tham số là chỉ số dòng `r` và chỉ số cột `c`, trả về tham chiếu (`int&`) đến phần tử tại vị trí đó để có thể hỗ trợ cả tác vụ đọc lẫn ghi dữ liệu (ví dụ: `A(i, j) = 10;`).

### Câu 4: Kế Thừa Tĩnh - Lớp `SquareMatrix` (2.0 điểm)

Ma trận vuông là một trường hợp đặc biệt của ma trận tổng quát khi số dòng bằng số cột. Xây dựng lớp `SquareMatrix` kế thừa công khai (`public`) từ lớp `Matrix`.

* Cài đặt Constructor `SquareMatrix(int n)` nhận vào kích thước của ma trận vuông và gọi Constructor lớp cha một cách hợp lý để định hình cấu trúc ma trận kích thước `n x n`.
* Tận dụng lại toàn bộ các toán tử và phương thức đã viết ở lớp cha mà không tiến hành định nghĩa lại (không viết lại toán tử toán học và toán tử nhập xuất).
* Cài đặt phương thức `int TinhVetMaTran()`: Tính và trả về tổng của tất cả các phần tử nằm trên đường chéo chính của ma trận vuông.
* Cài đặt phương thức `bool KiemTraDoiXuong()`: Kiểm tra và trả về `true` nếu ma trận vuông này đối xứng qua đường chéo chính (tức là phần tử tại vị trí `(i, j)` bằng phần tử tại vị trí `(j, i)` với mọi cặp chỉ số dòng và cột), ngược lại trả về `false`.

---

## Yêu Cầu Cài Đặt Hàm Main

Viết hàm `main` để kiểm thử toàn bộ các chức năng hệ thống theo kịch bản sau:

1. Khởi tạo và nhập dữ liệu cho hai ma trận tổng quát `A` (kích thước dòng x cột bất kỳ) và `B` (kích thước tương thích để thực hiện phép nhân).
2. Thực hiện tính toán và in ra màn hình kết quả của phép toán `A * B` thông qua toán tử xuất.
3. Khởi tạo và nhập dữ liệu cho một ma trận vuông `S` thông qua lớp `SquareMatrix`.
4. In ma trận vuông `S` ra màn hình, đồng thời gọi các hàm thành phần để hiển thị tổng giá trị trên đường chéo chính và kết luận ma trận vừa nhập có đối xứng hay không.
5. Đảm bảo toàn bộ bộ nhớ được giải phóng tự động hoàn toàn khi thoát chương trình mà không cần gọi hàm hủy thủ công ở hàm `main`.

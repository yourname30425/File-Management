# Quản Lý Tập Tin

## Giới Thiệu
Dự án này là một chương trình quản lý tập tin đơn giản được viết bằng C++. Chương trình cho phép người dùng tạo, xóa, và duyệt qua các thư mục và tập tin trong một hệ thống tập tin ảo.

## Cấu Trúc Thư Mục

## Các Tệp Tin Chính

- `main.cpp`: Tệp tin chính chứa hàm `main` để khởi động chương trình.
- `file_management.h` và `file_management.cpp`: Định nghĩa và triển khai các hàm quản lý tập tin và thư mục.
- `command_process.h` và `command_process.cpp`: Định nghĩa và triển khai các hàm xử lý lệnh từ người dùng.

## Hướng Dẫn Sử Dụng

1. **Khởi Động Chương Trình**:
   Chạy tệp tin thực thi `file_management.exe` để khởi động chương trình.

2. **Các Lệnh Hỗ Trợ**:
   - `ls`: Liệt kê các thư mục và tập tin trong thư mục hiện tại.
   - `pwd`: In đường dẫn của thư mục hiện tại.
   - `cd <tên_thư_mục>`: Di chuyển đến thư mục con có tên `<tên_thư_mục>`.
   - `cd ..`: Di chuyển đến thư mục cha.
   - `mkdir <tên_thư_mục>`: Tạo thư mục mới có tên `<tên_thư_mục>`.
   - `touch <tên_tập_tin>`: Tạo tập tin mới có tên `<tên_tập_tin>`.
   - `rm <tên_tập_tin>`: Xóa tập tin có tên `<tên_tập_tin>`.
   - `rmdir <tên_thư_mục>`: Xóa thư mục có tên `<tên_thư_mục>` và tất cả các tập tin, thư mục con bên trong.
   - `exit`: Thoát khỏi chương trình.

## Cài Đặt và Biên Dịch

1. **Cài Đặt Trình Biên Dịch**:
   - Đảm bảo rằng bạn đã cài đặt GCC hoặc trình biên dịch tương tự.

2. **Biên Dịch Chương Trình**:
   - Sử dụng lệnh sau để biên dịch chương trình:
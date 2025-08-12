# GNU's Not Unix
(một câu đùa đệ quy – tên viết tắt tự chứa chính nó).

## GNU Core Utilities (hay gọi tắt là coreutils) là một gói phần mềm trong dự án GNU.
Nó chứa những lệnh cơ bản nhất để làm việc với hệ điều hành kiểu Unix/Linux.
Ba nhóm chính:
- File utilities (làm việc với tệp/thư mục): ls, cp, mv, rm, mkdir, touch...
- Text utilities (xử lý văn bản): cat, echo, wc, cut, sort, tr...
- Shell utilities (quản lý môi trường, hệ thống): pwd, date, who, uname, test...

Nếu không có coreutils, bạn gần như không thể thao tác với terminal ở Linux/Unix, vì thiếu các lệnh cơ bản.

         +-----------------------------+
         |     Phần mềm ứng dụng        |
         |  (Firefox, LibreOffice, ...) |
         +-----------------------------+
                      ↑
         +-----------------------------+
         |   Công cụ & tiện ích GNU     |
         | (coreutils, bash, gcc, gdb..)|
         +-----------------------------+
                      ↑
         +-----------------------------+
         |      Thư viện GNU (glibc)    |
         |   glibc (GNU C Library)      |
         +-----------------------------+
                      ↑
         +-----------------------------+
         |        Nhân Linux            |
         | (Linux Kernel - quản lý CPU, |
         |  RAM, thiết bị phần cứng)    |
         +-----------------------------+
                      ↑
         +-----------------------------+
         |        Phần cứng máy tính    |
         +-----------------------------+

## Linux
Linux is just the kernel, not a completed OS.
It is officially known as GNU/Linux
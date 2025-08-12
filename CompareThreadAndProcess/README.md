
Chạy multi-threading => các thread dùng chung tài nguyên (CPU, bộ nhớ,...). Chạy multi-processing => các process tách biệt về tài nguyên (giả sử máy có 2 CPU thì 2 thread sẽ chạy song song. trên 2 CPU). => Multi-thread có thể chạy trên cùng 1 process.
Do tạo ra 1 process thì phải setup tài nguyên đọc lập => thời gian tạo process thường lâu hơn tạo thread => đối với những tác vụ nhẹ, cần cân nhắc có nên dùng process không vì có thể sẽ chậm hơn dùng thread hay chạy thông thường (không dùng thread/process).

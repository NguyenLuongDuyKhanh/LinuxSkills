pid_t pid = fork();
if (pid == 0) {
    // Child process
    int fd = open("child_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd, STDOUT_FILENO);   // redirect stdout
    close(fd);

    printf("This goes to the file, not the terminal!\n");
    _exit(0);
}

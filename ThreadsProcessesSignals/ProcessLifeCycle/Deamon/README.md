## Give me an example of deamon process in C which redirect output and error to file, also add signal handling

Perfect 👍 — here’s an **extended version** of the daemon program with **signal handling**.
This version supports graceful shutdown when it receives signals like `SIGTERM` or `SIGINT`.

---

### ✅ Full Example: Daemon with Signal Handling and Logging

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <time.h>

volatile sig_atomic_t keep_running = 1;

void handle_signal(int sig)
{
    switch (sig) {
        case SIGTERM:
        case SIGINT:
            keep_running = 0;
            break;
        default:
            // ignore other signals
            break;
    }
}

void log_message(const char *msg)
{
    time_t now = time(NULL);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("[%s] %s\n", buf, msg);
    fflush(stdout);
}

void create_daemon()
{
    pid_t pid, sid;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        printf("Daemon PID: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    sid = setsid();
    if (sid < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }

    if (chdir("/") < 0) {
        perror("chdir failed");
        exit(EXIT_FAILURE);
    }

    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int out_fd = open("/tmp/daemon_output.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    int err_fd = open("/tmp/daemon_error.log",  O_WRONLY | O_CREAT | O_APPEND, 0644);

    dup2(out_fd, STDOUT_FILENO);
    dup2(err_fd, STDERR_FILENO);

    close(out_fd);
    close(err_fd);
}

int main(void)
{
    create_daemon();

    // Register signal handlers
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);
    signal(SIGHUP, SIG_IGN);  // ignore hangup signal

    log_message("Daemon started.");

    while (keep_running) {
        log_message("Daemon is running...");
        fprintf(stderr, "This is an error log example.\n");
        fflush(stderr);
        sleep(5);
    }

    log_message("Daemon shutting down gracefully.");
    return 0;
}
```

---

### 🧠 Key Additions

| Feature                              | Description                                                         |
| ------------------------------------ | ------------------------------------------------------------------- |
| `volatile sig_atomic_t keep_running` | Safe flag to control main loop exit on signal.                      |
| `signal(SIGTERM, handle_signal)`     | Allows the daemon to gracefully stop on `kill`.                     |
| `log_message()`                      | Adds timestamps to the logs.                                        |
| `fprintf(stderr, ...)`               | Shows how errors are written separately to `/tmp/daemon_error.log`. |

Other utilities may be helpful

| Step                                              | Purpose                                                                           |
| ------------------------------------------------- | --------------------------------------------------------------------------------- |
| `fork()`                                          | Detach from the parent process.                                                   |
| `setsid()`                                        | Start a new session and become session leader (detach from controlling terminal). |
| `chdir("/")`                                      | Change working directory to root so the daemon doesn’t block unmounting.          |
| `umask(0)`                                        | Ensure full access to created files if needed.                                    |
| `close(STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO)` | Close inherited terminal I/O.                                                     |
| `dup2()`                                          | Redirect output to log files.                                                     |

---

### 🧩 How to Use

Compile and run:

```bash
gcc -o mydaemon daemon.c
./mydaemon
```

It will print the daemon’s PID and detach.

Then you can control it:

```bash
# Show running daemon
ps aux | grep mydaemon

# Stop the daemon gracefully
kill -TERM <daemon_pid>
```

Check logs:

```bash
tail -f /tmp/daemon_output.log
tail -f /tmp/daemon_error.log
```

---

Would you like me to modify this version so it **writes its PID to a file** (for easier service management, like `/run/mydaemon.pid`)?

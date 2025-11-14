## What are interruptible and uninterruptible process in linux. Give me example in C.

In Linux, **process states** describe what a process is currently doing — running, sleeping, waiting, etc. Two important sleep states are:

* 💤 **Interruptible sleep** — shown as **`S`** in `ps` or `top`
* 😴 **Uninterruptible sleep** — shown as **`D`** in `ps`

---

## 🧩 1. Interruptible Sleep (`TASK_INTERRUPTIBLE`)

A process in **interruptible sleep** is waiting for an event (like I/O, user input, etc.) **and can be woken up** by:

* The event it’s waiting for, **or**
* A signal (like `SIGINT`, `SIGTERM`, etc.)

➡️ Example: waiting for user input from keyboard or socket data.
➡️ If you press **Ctrl+C**, it will exit because it’s interruptible.

### **Example in C: interruptible sleep**

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process PID = %d\n", getpid());
    printf("Sleeping (interruptible)... Press Ctrl+C to interrupt.\n");
    sleep(100); // interruptible sleep
    printf("Woke up!\n");
    return 0;
}
```

**How it works:**

* When you run this program, it calls `sleep()`, which puts it in an **interruptible sleep** state.
* You can see this by running in another terminal:

  ```bash
  ps -o pid,stat,cmd -p <pid>
  ```

  You’ll see something like:

  ```
  PID  STAT CMD
  1234 S    ./a.out
  ```
* Press **Ctrl+C**, and it will wake up and terminate.

---

## ⚙️ 2. Uninterruptible Sleep (`TASK_UNINTERRUPTIBLE`)

A process in **uninterruptible sleep** is waiting for a **non-interruptible event**, typically a **hardware I/O** operation (like disk read/write).
It **cannot** be killed or woken up even if you send signals — it wakes up only when the I/O completes.

➡️ Example: waiting for disk or network driver response.
➡️ Even `kill -9` won’t stop it until the kernel finishes that I/O.

You can see such processes as `D` in `ps`, often called **"D-state" processes**.

### **Example in C (simulate uninterruptible sleep)**

In user space, you **can’t directly create `TASK_UNINTERRUPTIBLE`** — that’s kernel-only.
However, you can **simulate it** using a system call that blocks in kernel space (e.g. a slow disk read).

Example using `/dev/sda` (may require root privileges):

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    printf("Process PID = %d\n", getpid());
    int fd = open("/dev/sda", O_RDONLY); // Raw disk device
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buf[4096];
    printf("Reading from disk (might block, uninterruptible)...\n");
    read(fd, buf, sizeof(buf)); // Can enter D state if disk is busy
    close(fd);
    printf("Read done.\n");
    return 0;
}
```

**Note:**
If `/dev/sda` or storage is slow, the process may show as `D` in `ps`:

```bash
ps -o pid,stat,cmd -p <pid>
```

Output example:

```
PID  STAT CMD
5678 D    ./a.out
```

You can’t kill it with `kill -9` while it’s in `D` state — it must finish I/O first.

---

## 🧠 Summary Table

| State                     | Symbol | Description                           | Can Signal Wake It? | Example                                |
| ------------------------- | ------ | ------------------------------------- | ------------------- | -------------------------------------- |
| **Interruptible Sleep**   | `S`    | Waiting for event; can be interrupted | ✅ Yes               | `sleep(100)`                           |
| **Uninterruptible Sleep** | `D`    | Waiting for I/O completion            | ❌ No                | Disk I/O wait (`read()` on `/dev/sda`) |

---

Would you like me to show a **kernel module example** (in C) that actually puts a process in `TASK_UNINTERRUPTIBLE` using `set_current_state()` and `schedule()`? That’s how it’s really done in kernel code.

To inspect the **memory usage of a program** on Linux, you can use several commands depending on what exactly you want (live usage, detailed mapping, peak usage, etc.). Here are the most common ones:

---

## ✅ **1. `ps` — quick check**

Shows memory usage (RSS, VSZ):

```bash
ps aux | grep <programname>
```

Key columns:

* **RSS**: actual RAM used (kB)
* **VSZ**: virtual memory size

Or for a specific PID:

```bash
ps -p <PID> -o pid,comm,rss,vsz
```

---

## ✅ **2. `top` or `htop` — live usage**

### Live interactive view:

```bash
top
```

Or prettier:

```bash
htop
```

Press `Shift + M` in `top` to sort by memory.

---

## ✅ **3. `pmap` — detailed memory map**

Shows memory segments of a process:

```bash
pmap <PID>
```

Add summary:

```bash
pmap -x <PID>
```

---

## ✅ **4. `smem` — more accurate PSS accounting**

If installed:

```bash
smem -p <PID>
```

Useful when shared memory is important.

---

## ✅ **5. `/proc/<PID>/status` — exact memory stats**

This file contains all memory numbers:

```bash
cat /proc/<PID>/status
```

Important fields:

* **VmRSS** – RAM in use
* **VmSize** – virtual memory
* **VmPeak** – peak virtual memory
* **VmHWM** – peak RSS (High Water Mark)

---

## ✅ **6. For a running command:**

```bash
/usr/bin/time -v ./yourprogram
```

It will show:

* Maximum resident set size (max RAM program used)
* Page faults
* CPU time
  … and more.

---

## ⭐ Recommended depending on your goal

| Goal                              | Best command               |
| --------------------------------- | -------------------------- |
| Quick memory check                | `ps -p PID -o rss,vsz`     |
| Live memory usage                 | `top` / `htop`             |
| Detailed breakdown                | `pmap -x PID`              |
| Accurate shared memory accounting | `smem`                     |
| Peak memory usage of a run        | `/usr/bin/time -v program` |

---

If you want, tell me your **program name or PID**, and I can show you exactly which command fits best.

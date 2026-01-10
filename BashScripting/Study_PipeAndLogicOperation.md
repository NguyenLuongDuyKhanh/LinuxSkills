Great question — these look similar but mean very different things in **bash scripting**. Let’s go one by one:

---

## 1. **Single pipe (`|`)**

* **Purpose**: Pipe the **stdout** of the command on the left into the **stdin** of the command on the right.
* Example:

  ```bash
  ls | grep ".txt"
  ```

  * `ls` output is sent into `grep` to filter `.txt` files.

---

## 2. **Double pipe (`||`)**

* **Purpose**: Logical OR (short-circuit). Run the right command **only if** the left one **fails** (non-zero exit code).
* Example:

  ```bash
  mkdir mydir || echo "Failed to create directory"
  ```

  * If `mkdir mydir` fails, then `echo` runs.

---

## 3. **Single ampersand (`&`)**

* **Purpose**: Run the command in the **background** (asynchronously).
* Example:

  ```bash
  firefox &
  echo "Firefox started"
  ```

  * `firefox` launches in the background, shell continues immediately.

---

## 4. **Double ampersand (`&&`)**

* **Purpose**: Logical AND (short-circuit). Run the right command **only if** the left one **succeeds** (exit code = 0).
* Example:

  ```bash
  gcc program.c -o program && ./program
  ```

  * `./program` only runs if compilation succeeds.

---

### 🔑 Quick Summary Table

| Operator | Meaning                        | Example                              |                             |                            |
| -------- | ------------------------------ | ------------------------------------ | --------------------------- | -------------------------- |
| \`       | \`                             | Pipe stdout of left → stdin of right | `echo hello \| wc -c`       |                            |
| \`       |                                | \`                                   | Run right if left **fails** | `false \|\| echo "failed"` |
| `&`      | Run in background              | `sleep 5 &`                          |                             |                            |
| `&&`     | Run right if left **succeeds** | `true && echo "ok"`                  |                             |                            |

---

👉 Do you want me to also cover **combinations** (like `cmd1 && cmd2 || cmd3`), since those can be tricky in bash?

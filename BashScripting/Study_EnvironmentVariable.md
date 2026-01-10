| System Variable | Meaning | To view variable value type |
|-----------------|---------|-----------------------------|
| `BASH_VERSION`  | Holds the version of this instance of bash. | `echo $BASH_VERSION` |
| `HOSTNAME`      | The name of your computer. | `echo $HOSTNAME` |
| `CDPATH`        | The search path for the `cd` command. | `echo $CDPATH` |
| `HISTFILE`      | The name of the file in which command history is saved. | `echo $HISTFILE` |
| `HISTFILESIZE`  | The maximum number of lines contained in the history file. | `echo $HISTFILESIZE` |
| `HISTSIZE`      | The number of commands to remember in the history (default: 500). | `echo $HISTSIZE` |
| `HOME`          | The home directory of the current user. | `echo $HOME` |
| `IFS`           | Internal Field Separator (used for word splitting in expansions and `read`). Default: `<space><tab><newline>`. | `echo $IFS` |
| `LANG`          | Determines locale category (if no specific `LC_*` is set). | `echo $LANG` |
| `PATH`          | Colon-separated list of directories to search for commands. | `echo $PATH` |
| `PS1`           | Prompt settings. | `echo $PS1` |
| `TMOUT`         | Default timeout for `read`. In interactive shell, it logs out after timeout if no input. | `echo $TMOUT` |
| `TERM`          | Login terminal type. | `echo $TERM` / `export TERM=vt100` |
| `SHELL`         | Path to the login shell. | `echo $SHELL` |
| `DISPLAY`       | X display name. | `echo $DISPLAY` / `export DISPLAY=:0.1` |
| `EDITOR`        | Default text editor. | `export EDITOR=/usr/bin/vim` |

Yes — there **is a difference** between a **shell variable** and an **environment variable** in Bash, though they often look the same when you `echo` them. Let’s break it down:

---

## 1. **Shell Variable**

* A variable that exists **only inside the current shell process**.
* Defined like this:

  ```bash
  MYVAR="hello"
  echo $MYVAR   # works here
  ```
* Not automatically passed to child processes (subshells or commands you run).
* Example:

  ```bash
  MYVAR="hello"
  bash -c 'echo $MYVAR'   # prints nothing, because MYVAR isn’t exported
  ```

---

## 2. **Environment Variable**

* A variable that is **exported** from the shell and inherited by child processes.
* Created using `export`:

  ```bash
  export MYENV="hello"
  bash -c 'echo $MYENV'   # prints hello, because MYENV was exported
  ```
* Used by programs, libraries, and the OS (e.g., `PATH`, `LANG`, `EDITOR`, `HOME`).

---

## 3. **Key Difference**

* **Scope**:

  * Shell variable → available **only in the current shell**.
  * Environment variable → available in **current shell and all child processes**.
* **Creation**:

  * Shell variable: `VAR=value`
  * Environment variable: `export VAR=value` (or `VAR=value; export VAR`).

---

## 4. ✅ Quick Demo

```bash
# Shell variable
FOO="bar"
bash -c 'echo $FOO'    # (prints nothing)

# Environment variable
export BAZ="qux"
bash -c 'echo $BAZ'    # prints qux
```

---

## 5. Analogy

* **Shell variable** = local note for yourself.
* **Environment variable** = pinned note on the wall that everyone (including guests = child processes) can see.

---

👉 Do you want me to make a **diagram** showing how variables flow between **parent shell → child shell → program**? It can make this distinction crystal clear.

## Learn more about Command: export and Command: source
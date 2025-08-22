## 🔑 **Special Variables in Bash**

| Variable  | Meaning                                                               | Example                                          |
| --------- | --------------------------------------------------------------------- | ------------------------------------------------ |
| `$0`      | Name of the script (or shell) being executed                          | `echo $0` → `./myscript.sh`                      |
| `$1 … $9` | First to ninth **positional parameters** (arguments)                  | Run `./myscript.sh foo bar` → `$1=foo`, `$2=bar` |
| `$#`      | Number of positional parameters                                       | If script called with 3 args → `$# = 3`          |
| `$@`      | All positional parameters (as separate quoted strings)                | `"arg1" "arg2" "arg3"`                           |
| `$*`      | All positional parameters (as a single string)                        | `"arg1 arg2 arg3"`                               |
| `"$@"`    | Preserves arguments as separate words                                 | Loop safe: `for arg in "$@"; do ...; done`       |
| `"$*"`    | Treats all args as one word                                           | `"arg1 arg2 arg3"`                               |
| `$$`      | PID of the current shell                                              | `echo $$` → `12345`                              |
| `$!`      | PID of the **last background command**                                | `sleep 60 & echo $!`                             |
| `$?`      | Exit status of the **last command** (0 = success, non-zero = failure) | `ls /notfound; echo $?` → `2`                    |
| `$_`      | Last argument of the previous command                                 | `echo hello; echo $_` → `hello`                  |
| `$-`      | Current shell options/flags                                           | Shows active options like `himBH`                |
| `$PS1`    | Primary prompt string (the shell prompt)                              | Usually `[\u@\h \W]\$`                           |
| `$PS2`    | Secondary prompt (used when command spans multiple lines)             | Default is `>`                                   |

---
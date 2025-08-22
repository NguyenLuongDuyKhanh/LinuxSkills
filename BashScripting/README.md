## Debugging techniques
Trick to debug bash: set -x hoặc bash -x <script>
Set -noeror để thoát scrPt khi lỗi

## 
Bash itself does not have built-in support for transactions like you might find in databases or programming languages with transactional APIs. However, you can implement a transaction-like mechanism in your bash scripts to ensure that actions either complete fully or roll back on failure.

Step 1: Backup (Start of "Transaction") 
    Copy the workspace to a a backup dir
Step 2: Perform Actions (Core Transaction Logic)
    if Error occur
        Restore from backup (Rollback)
    else
        Move to step 3
Step 3: Commit (End of "Transaction")
    Remove backupdir

## Tab-completion
Suppose your command is mycommand and you want tab-completion to suggest specific arguments (e.g., "start", "stop", "restart") or file paths.

1. Create a script (e.g., mycommand-completion.sh):
"""
_mycommand_completions() {
    local cur prev opts
    COMPREPLY=()
    cur="${COMP_WORDS[COMP_CWORD]}"
    prev="${COMP_WORDS[COMP_CWORD-1]}"
    opts="start stop restart"

    if [[ ${cur} == -* ]]; then
        COMPREPLY=( $(compgen -W "${opts}" -- ${cur}) )
    else
        COMPREPLY=( $(compgen -f -- ${cur}) )
    fi
}
complete -F _mycommand_completions mycommand
"""
source mycommand-completion.sh

Now, typing mycommand <Tab> will suggest options like "start", "stop", and "restart", and typing mycommand <path><Tab> will suggest file paths.

## 
pip install argcomplete
"""
import argparse
import argcomplete

parser = argparse.ArgumentParser()
parser.add_argument("command", choices=["start", "stop", "restart"])
parser.add_argument("filepath", nargs="?", help="Path to a file")

Enable tab-completion
argcomplete.autocomplete(parser)
args = parser.parse_args()

print(f"Command: {args.command}")
if args.filepath:
    print(f"Filepath: {args.filepath}")

"""
activate-global-python-argcomplete --user

## Command: source
The source command in Bash is a built-in utility that reads and executes commands from a specified file in the current shell environment. This command is particularly useful for loading functions, variables, and configuration files into shell scripts without spawning a new process.
That mean, if we run "source abc.sh" the variable that are exported in abc.sh are applied to the terminal where it is called. It can be checked by checking environment variable.
Function are also extended to the terminal.
It is also used to modify environment variable in 
Note:
    When we run export in a script file, it pawn a new thread and not afect the current shell.


## Command: export
Makes environment variables available to child processes. If you need a variable to be accessible in subshells or scripts executed by the shell.
"""
    export MY_VAR="Hello"
    bash -c 'echo $MY_VAR'  # Output: Hello
"""
Without export, the variable would not be available in the child shell.

## environment variables vs shell variable

## Command: mktemp
The mktemp command is used to create temporary files or directories in a secure and reliable way. Here are the advantages of using mktemp:
Prevents Name Collisions:
Security:
Automation-Friendly:
Customization: 
You can specify a filename template, prefix, or directory in which to create the temporary file.
Error Prevention:
If it fails to create a file or directory, it provides an error message, which is helpful for debugging or handling issues in scripts.

## Command: test
File Checks:
    test -e filename       # Check if the file exists
String Comparisons:
    test "string1" = "string2"   # Check if strings are equal
    test -z string              # Check if the string is empty
Numeric Comparisons:
    test 5 -eq 5     # Check if numbers are equal
Logical Operators:
    test -e file1 -a -e file2    # Check if both files exist
    test -d dir1 -o -d dir2      # Check if either directory exists

Many scripts use [ ... ] as shorthand for the test command. For example:
if [ -e filename ]; then
    echo "File exists!"
fi
if test -e filename; then
    echo "File exists!"
fi

## Command dpkg 
Check which package a command belongs to with different tools depending on your distro:
```
dpkg -S $(which md5sum)
```
Output example
```
coreutils: /usr/bin/md5sum
```

## Command env
Run a command with a modified environment:
```
env VAR=value command
```

Example:
```
env PATH=/tmp ./myscript.sh
```
→ runs myscript.sh with a temporary PATH, without changing your shell’s environment.

Clear environment and run a command in a “clean” environment:
```
env -i command
```

## References
https://tldp.org/LDP/abs/html/

## TODO
- learn more command, packages such as coreutil

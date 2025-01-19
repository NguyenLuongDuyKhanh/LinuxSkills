# Overal
STDIN: reads input from the keyboard (file descriptor 0). 
STDOUT: The normal output from a command/script (file descriptor 1)
STDERR: The error output from a command/script (file descriptor 2)

# Redirect STDOUT or STDERR
ls R* non-existing-file* > my_normal_output.txt 

ls R* non-existing-file* 2> my_error_output.txt

ls R* non-existing-file* > my_normal_output.txt 2> my_error_output.txt:

# Send STDOUT and STDERR to the same file
ls R* non-existing-file* > my_consolidated_output.txt 2>&1

# Using pipe in shell commands
;: commands separated by a ; are executed sequentially. The shell waits for each command to terminate in turn.

&&: command after && is executed if, and only if, command before && returns an exit status of zero. You can think of it as AND operator.

|: a pipe. In expression command1 | command2 The standard output of command1 is connected via a pipe to the standard input of command2.

There are more similar control operators, worth to mention:

||: command after || is executed if, and only if, command before || returns a non-zero exit status. You can think of it as OR operator. Please note, that | and || are completely different animals.

&: the shell executes the command terminated by & in the background, does not wait for the command to finish and immediately returns exit code 0. Once again, & has nothing to do with &&.

|&: a shorthand for 2>&1 | i.e. both standard output and standard error of command1 are connected to command2's standard input through the pipe.

Additionally if you use zsh then you can also start command with &| or &!. In this case job is immediately disowned, after startup it does not have a place in the job table.
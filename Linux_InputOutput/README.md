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
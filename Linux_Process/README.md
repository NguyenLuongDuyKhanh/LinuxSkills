# Usage
ps -ef > psoutput.txt
cat psoutput.txt

# Reference
https://man7.org/linux/man-pages/man1/ps.1.html
https://tldp.org/LDP/abs/html/internalvariables.html
https://www.ibm.com/docs/en/aix/7.3.0?topic=p-ps-command
https://servicenow.iu.edu/kb?id=kb_article_view&sysparm_article=KB0026042

## Q&A and ever encountered problems
### About priority of a process and 'nice' command
    pi@raspberrypi:~/Workplace $ ps -l
    F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
    0 S  1000    6054    2502  0  80   0 -   527 do_wai pts/4    00:00:00 bash
    0 T  1000    7708    6054  0  80   0 -   570 do_sig pts/4    00:00:00 vi
    4 R  1000    7741    6054  0  80   0 -   722 -      pts/4    00:00:00 ps

    pi@raspberrypi:~/Workplace $ sudo renice -10 -p 7708
    7708 (process ID) old priority 0, new priority -10

    pi@raspberrypi:~/Workplace $ ps -l
    F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
    0 S  1000    6054    2502  0  80   0 -   527 do_wai pts/4    00:00:00 bash
    0 T  1000    7708    6054  0  70 -10 -   570 do_sig pts/4    00:00:00 vi
    4 R  1000    7903    6054 99  80   0 -   722 -      pts/4    00:00:00 ps

PRI - Priority of the process
    Priority is 80 at the begining by default

NI - nice value
    Nice value is 0 at the begining by default.
    The highest value is 20. The lowest is -20.
    The higher it is the nicer the process is - The higher the number the lower the priority and the more nice it is to other processes.

### Does a terminal has its own pid
According to (https://stackoverflow.com/questions/2493642/how-can-a-linux-unix-bash-script-get-its-own-pid)
Use $BASHPID 
Use $$
In a subshell, $$ returns PID of parent process.

###
Backgrounding a process by Ctrl+Z
Check for job running background by command 'jobs'
    pi@raspberrypi:~/Workplace $ jobs
    [1]+  Stopped
Foregrounding by fg
    pi@raspberrypi:~/Workplace $ sudo renice -10 -p 7708
    7708 (process ID) old priority 0, new priority -10
    pi@raspberrypi:~/Workplace $ ps -l
    F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
    0 S  1000    6054    2502  0  80   0 -   527 do_wai pts/4    00:00:00 bash
    0 T  1000    7708    6054  0  70 -10 -   570 do_sig pts/4    00:00:00 vi
    4 R  1000    7903    6054 99  80   0 -   722 -      pts/4    00:00:00 ps
### Does a child process inherit (able to access and modify) its parent's attr

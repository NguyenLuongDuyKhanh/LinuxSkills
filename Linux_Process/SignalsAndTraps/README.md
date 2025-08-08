https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
In C++, there’s no built-in alarm() in the standard library, but on POSIX systems (Linux, macOS, etc.) you can use the C function alarm() from <csignal> to schedule a SIGALRM signal after a number of seconds.

How it works
    alarm(seconds) schedules a SIGALRM signal after seconds seconds.
    signal(SIGALRM, handler) assigns a function to run when the signal arrives.
    If you call alarm(0), it cancels any pending alarm.
⚠ Notes
    This works only on POSIX systems (Linux, macOS, BSD…).
    On Windows, you’d need a different approach, like using SetTimer() or a separate thread with Sleep().

#
Use kill to send signal and trap to catch signal 


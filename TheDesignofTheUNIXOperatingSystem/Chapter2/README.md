# Introduction to the kernel 

## 2.1 Architecture of the unix operating system 
The two major components of the kernel:
- The file system has "places" 
- Processes have "lifes"
System calls look  like ordinary function calls in C programs, and libraries map these function calls to the primitives peeded to enter the operating system.
Assembly language programs may invoke system calls directly without a system call library.
System calls can be classified into 2 sets:
- those that interact with the file subsystem: open, close, read, write, stat, chown, chmod
        The file subsystem accesses file data using a buffering mechanism th�t regulates 
    data ftow between the kernel . and secondary storage devices. The buffering 
    mechanism interacts with block 110 device drivers to initiate data transfer to �nd 
    from the kernel.
- those that interact with the process control subsystem: fork, exec, exit, wait, brk, signal
        Responsible for process synchronization, 
    interprocess communication� memory management, and process scheduling
The memory management module controls the allocation of memory: Using swapping and demand paging.
The scheduler module allocates the CPU to processes.

## 2.2 INTRODUCTION TO SYSTEM CONCEPTS 
### 2.2.l An Overview of the File Subsystem 

Because a process in the UNIX system can execute in two modes, kernel or 
user, it uses a separate stack for each mode

How 'make' know a file change 
Make works by inspecting information about files, not their contents.

Make works out dependencies between targets and their dependencies, and then looks to see whether the files exist. If they do, it asks the operating system for the time and date the file was last modified. This is the 'timestamp' for this purpose, although the term can have other meanings.

If a target file either does not exist, or exists and is earlier than its dependent file, then Make rebuilds the target from the dependent by applying a rule.

If the dependent does not exist, Make signals an error.

A consequence of this is that you can force a rebuild by deleting the target, or by 'touching' the dependent to make it later than the target. You can avoid a rebuild by 'touching' the target. Touching simply updates the timestamp to now.

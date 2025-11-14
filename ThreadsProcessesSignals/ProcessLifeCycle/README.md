## Orphan
If the parent process completes while the child is still running, that child process becomes orphan.

In this demo, process 24018 spawn a child with PID 24019 as shown in DemoOrphanProcess_1.png and DemoOrphanProcess_2.png
After 30s, the process 24018 complete hence its child becomes orphan as shown in DemoOrphanProcess_3.png.
The child process then adopted by the process 2134 which is the systemd process as shown in DemoOrphanProcess_4.png.
After 2 times of 30s, the child completes, all resource were retrive.

## Zombie
If the child process completes while the parent still holds its information (but the parent does not call wait() on its PID), that child process becomes zombie process.

In this demo, process 27132 spawn a child with PID 27133 as shown in DemoZombieProcess_1.png and DemoZombieProcess_2.png
After 30s, the child process complete and its becomes a zombie process with a red 'Z'.
After 2 times of 30s, the parent process complete, resource in both 2 process are released.

DemoReadStateZombieProcess.c demonstrate a method to query for a process's state. As shown in DemoZombieProcess_4.png, when the parent reach its completion, the child's state is already zombie.
# Virtual memory

# Check disk space 
df -h
ncdu

# Check block and file system style
## ls 
    pi@raspberrypi:~/workspace $ ls -l 
    total 64
    drwxr-xr-x  7 pi pi 4096 Jan 16 02:04 CPlusHomeworks
    drwxr-xr-x 16 pi pi 4096 Dec  1 03:55 CppLessons
    -rwxr-xr-x  1 pi pi   21 Feb  2 01:59 testexecutable

- A directory reserves 4096 bytes (at minimum) for meta-data about itself and its contents.
- In folders, that 4K is the size of space on the disk that is used to store the meta information for the directory.
- It completely depends on the file system type, not the total size of content inside.

# Check size of a directory
pi@raspberrypi:~/workspace $ du -sh CPlusHomeworks/
1.3M    CPlusHomeworks/
## stat
- Block size is 4K means the minium size of a file on disk is 4K
    pi@raspberrypi:~/workspace $ stat -f /
      File: "/"
        ID: f8358a6f0d3d4eb6 Namelen: 255     Type: ext2/ext3
    Block size: 4096       Fundamental block size: 4096
    Blocks: Total: 3679626    Free: 688738     Available: 496770
    Inodes: Total: 931040     Free: 732885

- stat a directory
    pi@raspberrypi:~/workspace $ stat testexecutable 
    File: testexecutable
    Size: 21              Blocks: 8          IO Block: 4096   regular file
    Device: 179,2   Inode: 390192      Links: 1
    Access: (0755/-rwxr-xr-x)  Uid: ( 1000/      pi)   Gid: ( 1000/      pi)
    Access: 2025-02-02 01:59:35.158131531 +0000
    Modify: 2025-02-02 01:59:35.158131531 +0000
    Change: 2025-02-02 02:00:03.038027579 +0000
    Birth: 2025-02-02 01:59:35.158131531 +0000

# Check type of disk
    NAME        MAJ:MIN RM  SIZE RO TYPE MOUNTPOINTS    FSTYPE
    mmcblk0     179:0    0 14.8G  0 disk                
    ├─mmcblk0p1 179:1    0  512M  0 part /boot/firmware vfat
    └─mmcblk0p2 179:2    0 14.3G  0 part /              ext4

- The output indicate 
    * 1 storage device name mmcblk0
    * 1 partition mmcblk0p1 within mmcblk0 use for boot, vfat format
    * 1 partition mmcblk0p2 within mmcblk0 use for data, ext4 format

# Common commands
1. df (Disk Free):
Purpose: Displays the amount of available disk space on file systems.
Usage: df [options] [file]
Example: df -h (shows disk usage in a human-readable format)
Output: Provides information like total space, used space, available space, and the percentage of disk usage for each mounted file system.

2. du (Disk Usage):
Purpose: Estimates the disk usage of files and directories.
Usage: du [options] [file]
Example: du -sh /home/user (provides the total size of the directory /home/user in a human-readable format)
Output: Displays the size of each file and directory within the specified directory (or current directory if none is specified).

3. dd (Data Duplicator):
Purpose: Copies and converts files, primarily used for low-level data manipulation.
Usage: dd [options]
Example: dd if=/dev/sda of=/dev/sdb bs=4M (clones the contents of the disk /dev/sda to /dev/sdb using a block size of 4MB)
Output: Doesn't produce a specific output like df or du but instead provides a summary of the data transfer upon completion.

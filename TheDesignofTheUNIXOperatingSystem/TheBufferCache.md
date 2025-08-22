# The buffer cache
When a process wants to access data from a file, the kernel brings the data (from mass storage device such as disks) into main memory (RAM) where the process can examine/alter it and request that the data be saved in the file system again.
-   The super block of a file system describes the free space available on the file system. The kernel reads the super block into memory to access its data and writes it back to the file system when it wishes to save its data. 
-   The inodes describe the layout of a file. The kernel reads an inode into memory when it wants to access data in a file and writes the inode back to the file system when it wants to update the file layout.
The kernel could read and write directly to and from the disk fot all file system 
accesses, but system response time and throughput would be poor because of the 
slow disk transfer rate. The kernel therefore 'attempts to minimize the frequency of 
disk access by keeping a pool of internal data buffers, called the buffer cache which contains the data in recently used disk blocks.
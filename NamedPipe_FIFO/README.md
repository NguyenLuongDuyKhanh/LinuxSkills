# ls command
ls -i
-i, --inode                print the index number of each file

# File types
- study files' types (link,pipe,regular,dir,...)
# inode

# Hardlink
- behaviour on edit/remove/call

## Create files and check inode
## test Symbolic links as well
## TODO about links
Difference Between Hard Link and Symbolic Link in Linux
123
A hard link and a symbolic link (symlink) are two different ways to create references to files in Linux. They serve distinct purposes and have unique characteristics.
A hard link is a direct reference to the same inode as the original file. This means that both the original file and the hard link share the same data and metadata. Deleting the original file does not affect the hard link, as the data remains accessible until all hard links to the inode are removed. Hard links cannot span across different file systems and cannot link to directories.
A symbolic link, on the other hand, is a separate file that contains a path to the target file. It acts as a shortcut to the original file. If the original file is deleted or moved, the symbolic link becomes broken and no longer points to valid data. Symbolic links can span across file systems and can link to directories.
Key distinctions include:
Inode Sharing: Hard links share the same inode as the original file, while symbolic links have their own inode pointing to the target file's path.
File System Scope: Hard links are restricted to the same file system, whereas symbolic links can cross file systems.
Behavior on Deletion: Deleting the original file does not affect hard links but breaks symbolic links.
Directories: Hard links cannot link to directories, while symbolic links can.
Commands to create these links:
Hard link: ln original_file hard_link
Symbolic link: ln -s original_file symbolic_link
Understanding these differences helps in choosing the appropriate type of link based on the use case.
https://www.geeksforgeeks.org/linux-unix/soft-hard-links-unixlinux/
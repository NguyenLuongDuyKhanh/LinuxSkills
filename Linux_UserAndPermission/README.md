root and root group , sudo group?

# passwd

# cat /etc/passwd


# cat /etc/group
This file contains information about all local user groups on the system. 
root:x:0:
kvm:x:104:
render:x:105:pi,vnc
pi:x:1000:

# chroot command

# sudoer command
## Traversal permission 
This is a classic Linux filesystem rule:
```
To open a file /a/b/c/file.iso, the process must have execute (x) permission on /a, /a/b, /a/b/c, and read permission on file.iso.
```
Solution
chmod +x /a
chmod +x /a/b
chmod +x /a/b/c
chmod +xr /a/b/c/file.iso


## TODO
/etc/group 
cat /etc/passwd 
less /etc/passwd 
more /etc/passwd 
Usermod
https://www.geeksforgeeks.org/linux-unix/usermod-command-in-linux-with-examples/
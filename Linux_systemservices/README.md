
https://www.freedesktop.org/software/systemd/man/latest/systemd.service.html


## Types of units
Systemd defines multiple types of units, each serving a different purpose in managing resources and processes on a Linux system.

🧩 Main systemd Unit Types
Unit Type	| File Extension	| Purpose
------------|-------------------|---------------------------------------------
service	    | .service	        | Manages daemons (background services) like nginx, sshd
socket	    | .socket	        | Activates services on incoming socket connections
target	    | .target	        | Grouping of units to reach a specific boot state (e.g., multi-user.target)
device	    | .device	        | Represents kernel devices (automatically generated)
mount	    | .mount	        | Manages filesystem mounts
automount	| .automount	    | Auto-mounts filesystems on demand
swap	    | .swap	            | Manages swap partitions/files
timer	    | .timer	        | Triggers services based on time (cron-like)
path	    | .path	            | Activates a service when a file or directory changes
slice	    | .slice	        | Manages groups of system resources (used in cgroups)
scope	    | .scope	        | Manages external processes (e.g., started via DBus or systemd-run)
busname	    | .busname	        | Manages DBus service names
snapshot	| .snapshot	        | Represents the current state of units, for rollbacks (rare)

🧠 Commonly Used in Practice:

.service: for daemons

.timer: for scheduled jobs

.mount: for mounting volumes

.target: for boot stage management

.socket: for on-demand activation of services

## System-provided vs User/system administrator customizations unit files
###  System-provided unit files

Installed by packages (like nginx, ssh, etc.)

You should not manually edit files here — changes may be overwritten on updates.

Path may vary:
- Debian/Ubuntu: /lib/systemd/system/
- Fedora/Arch/RHEL: /usr/lib/systemd/system/

### User/system administrator customizations

Used to override or extend unit files from /lib/systemd/

Contains:
- /etc/systemd/system/ — custom or overridden unit files
- /etc/systemd/user/ — user-level units (not system-wide)
  
### How systemd prioritizes them
When starting a service (e.g., nginx.service), systemd looks in this order:

1. /etc/systemd/system/nginx.service ← your custom unit (highest priority)

2. /lib/systemd/system/nginx.service ← package-provided default

Internal fallback or generated units

### How to override safely
If you want to change a systemd unit:
```
sudo systemctl edit nginx.service
```
This creates a drop-in config under:
```
/etc/systemd/system/nginx.service.d/override.conf
```
Much safer than editing files in /lib/systemd/.
Please note you want this to be in /etc/systemd/system/ and NOT in usr/lib/systemd/ or it could be written over on the next update.
# NTP - Network Time Protocol

# ntpd - ntp daemon, a daemon service to synchonize time in linux

# List of NTP servers
https://www.ntppool.org/fr/

# Redhat NTP docs
https://access.redhat.com/documentation/vi-vn/red_hat_enterprise_linux/7/html/system_administrators_guide/ch-configuring_ntp_using_ntpd

# Sample status
sudo ntpq -p
     remote           refid      st t when poll reach   delay   offset  jitter
==============================================================================
 SHM(0)          .GPS.            0 l    -   16    0    0.000   +0.000   0.000
 SHM(1)          .PPS.            0 l    -   16    0    0.000   +0.000   0.000
 LOCAL(0)        .LOCL.          14 l  62m   64    0    0.000   +0.000   0.000
+203.113.174.44  139.199.214.202  3 u   75  128  277    4.079  +49.021   2.804
*time.cloudflare 10.154.8.7       3 u   21  128  377   25.103  +33.076   3.992
+time.cloudflare 10.119.8.148     3 u   34  128  377   24.895  +33.743   4.877

# Sample service config file
cat /lib/systemd/system/ntpd.service
[Unit]
Description=Network Time Service
After=network.target

[Service]
Type=forking
PIDFile=/run/ntpd.pid
ExecStart=/usr/sbin/ntpd -u ntp:ntp -p /run/ntpd.pid -g

[Install]
WantedBy=multi-user.target

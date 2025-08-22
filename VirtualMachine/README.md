
# sudo systemctl enable --now libvirtd
Libvirt doesn’t run QEMU as your pi user — it runs it as the libvirt-qemu user (or qemu on some distros).
why libvirt-qemu is more secured than pi user
# qemu-kvm

## what inside dump xml

---

## 1. **What a Virtual Machine Is**

A virtual machine is essentially a “computer inside your computer.”
It:

* **Emulates** hardware like CPU, memory, network, and storage
* Runs its own **operating system** (guest OS)
* Is **isolated** from your main OS (host OS)
* Can be started, paused, cloned, and deleted like a file

On Linux, VMs are useful for:

* Testing different OSes (e.g., Ubuntu inside Fedora)
* Running Windows-only apps
* Experimenting with servers without touching your real system
* Snapshots: freeze a VM’s state and restore later

---

## 2. **Tools for Virtualization on Linux**

There are several ways to create VMs on Linux. The big three are:

| Tool                          | Type                     | Pros                                               | Cons                                       |
| ----------------------------- | ------------------------ | -------------------------------------------------- | ------------------------------------------ |
| **VirtualBox**                | Cross-platform, desktop  | Easy to use, GUI available, works everywhere       | Slower than KVM, Oracle licensing concerns |
| **KVM + QEMU + libvirt**      | Native Linux hypervisor  | Very fast (near native), widely used in production | Steeper learning curve                     |
| **VMware Workstation Player** | Proprietary              | Good Windows integration, polished GUI             | Free only for non-commercial use           |
| **GNOME Boxes**               | GUI wrapper for KVM/QEMU | Super simple, integrates with GNOME                | Less advanced features than virt-manager   |

For **learning purposes**, I recommend **KVM with virt-manager** because:

* It’s native to Linux (no extra kernel hacks)
* Runs fast
* Lets you learn both GUI and CLI VM management

---

## 3. **Hands-On: Running Your First VM with KVM on Linux**

### **Step 1 — Check if your CPU supports virtualization**

Run:

```bash
egrep -c '(vmx|svm)' /proc/cpuinfo
```

* If output > 0 → You’re good
* If 0 → You need to enable virtualization in BIOS/UEFI

---

### **Step 2 — Install KVM, QEMU, libvirt, and virt-manager**

On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager
```

On Fedora:

```bash
sudo dnf install @virtualization
sudo systemctl enable --now libvirtd
```

---

### **Step 3 — Add your user to the libvirt group**

```bash
sudo usermod -aG libvirt $(whoami)
```

Then log out and back in.

---

### **Step 4 — Launch virt-manager**

```bash
virt-manager
```

* Click **Create a New Virtual Machine**
* Choose **Local install media (ISO image)**
* Pick your ISO (e.g., Ubuntu ISO from ubuntu.com)
* Set RAM, CPU, and disk size
* Click **Finish** — your VM will boot

---

### **Step 5 — Manage your VM**

* **Start/Stop** from virt-manager
* **Snapshot** from the VM’s right-click menu
* **Access via SSH** if your guest OS has SSH enabled

---

💡 **Pro Tip:** Once you’re comfortable with virt-manager, you can move to **CLI control** using:

```bash
virsh list --all
virsh start <vm-name>
virsh shutdown <vm-name>
```

---

## 7. Start, stop, and manage the VM
wget https://cdimage.ubuntu.com/releases/22.04/release/ubuntu-22.04.5-live-server-arm64.iso
Install 
```
virt-install \
  --name ubuntu-arm-vm \
  --ram 1024 \
  --vcpus 2 \
  --os-variant ubuntu22.04 \
  --disk path=/var/lib/libvirt/images/ubuntu-arm.qcow2,size=10 \
  --cdrom ubuntu-22.04-live-server-arm64.iso \
  --network network=default \
  --graphics none
```
List VMs:
```bash
virsh list --all
```

Start:
```
virsh start ubuntu-arm-vm
```

Connect to console:
```
virsh console ubuntu-arm-vm
```

Shutdown:
```
virsh shutdown ubuntu-arm-vm
```

In libvirt terms:
- A domain = a VM definition (its XML config, name, disk mappings, etc.)
- When you undefine it, you delete that VM’s definition from libvirt.
- But: The VM’s disk images (e.g. .qcow2, .img) are not deleted unless you explicitly ask for it.


When libvirt creates a UEFI-based virtual machines (like Ubuntu ARM images), it generates an NVRAM file (non-volatile RAM, kind of like virtual BIOS/UEFI storage).
Libvirt won’t let you undefine the domain until you also tell it what to do with that NVRAM file.

NVRAM is usually stored in:
```
/var/lib/libvirt/qemu/nvram/<name of the VM, such as ubuntu-arm-vm>_VARS.fd
```
If you want to backup and restore a UEFI VM:

Dump XML:
```
virsh dumpxml ubuntu-arm-vm > ubuntu-arm-vm.xml
```

Copy disk image(s):
```
cp /var/lib/libvirt/images/ubuntu-arm.qcow2 .
```

Copy NVRAM file (important for UEFI settings):
```
cp /var/lib/libvirt/qemu/nvram/ubuntu-arm-vm_VARS.fd .
```

## Reference
https://medium.com/@rodrigodiez/using-qemu-kvm-and-libvirt-to-set-up-a-host-for-virtual-machines-e4e8e1d21128
https://bitgrounds.tech/posts/kvm-qemu-libvirt-virtualization/
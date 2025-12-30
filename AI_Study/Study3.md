In **Ubuntu (and other Linux systems using GNOME or similar desktop environments)**, the **Trash** is not a single “mounted” folder — it’s a **per-user directory** that follows the [FreeDesktop.org Trash Specification](https://specifications.freedesktop.org/trash-spec/trashspec-latest.html).

Here’s where it actually lives on the filesystem:

---

### 🗑️ **1. For local files (your main disk)**

Your Trash is stored in your home directory:

```
~/.local/share/Trash/
```

Inside it, you’ll find:

```
~/.local/share/Trash/
├── files/        # deleted files
└── info/         # metadata (.trashinfo) files with original paths and deletion dates
```

So if you delete a file `mydoc.txt`, you’ll see:

```
~/.local/share/Trash/files/mydoc.txt
~/.local/share/Trash/info/mydoc.txt.trashinfo
```

---

### 💽 **2. For external or other mounted volumes**

If you delete a file from an **external drive**, **network share**, or **other mounted filesystem**, a `.Trash-*` directory is created at the root of that filesystem.

Example:

```
/media/youruser/MyUSB/.Trash-1000/
```

* `1000` is your **user ID (UID)**.
* Inside that folder, it will have the same structure:

  ```
  .Trash-1000/
  ├── files/
  └── info/
  ```

---

### ⚙️ **3. To list all trash folders on the system**

You can use:

```bash
find / -type d -name '.Trash-*' 2>/dev/null
```

or for your own user:

```bash
find /media /mnt ~/.local/share -type d -name 'Trash' 2>/dev/null
```

---

### 🧹 **4. To empty the trash**

Command-line way:

```bash
gio trash --empty
```

or manually:

```bash
rm -rf ~/.local/share/Trash/*
```

---

Would you like me to explain **how Ubuntu decides which trash folder to use** when you delete a file (e.g. via Nautilus or `gio trash`)?


Yes — **if you delete a file from an external disk using the file manager (Nautilus) or `gio trash`, it will still consume space on that external disk**.

Here’s what happens:

---

## ✅ **When deleting from an external drive**

If the filesystem supports it (most do), Ubuntu creates a trash folder on that drive:

```
/media/<user>/<DriveName>/.Trash-<UID>/
```

Example:

```
/media/khanh/USB32GB/.Trash-1000/files/
```

The file you “deleted” is simply **moved into that folder**, not removed.
So **the space on the external disk is still used** until you empty the trash.

---

## ❗ Why this happens

Trash is designed to be reversible.
To restore a file, the system needs it to remain on the **same filesystem** (because moving across filesystems can be slow or impossible without copying).

So it keeps the deleted file *on the original drive*.

---

## 💡 What if the external drive does *not* support trash?

If the disk is:

* **FAT32 / exFAT / NTFS** (common on USB drives) → trash works; `.Trash-UID/` folder is created.
* **Read-only**, **network drive**, or has strict permissions → it may skip the trash and delete permanently.

Also, if `.Trash-1000` can’t be created, Nautilus may give “permission denied to move to trash” and offer **Delete Permanently** instead.

---

## 🧹 **To really free space on the external drive**

Empty the trash:

### Option 1 — GUI

Right-click Trash → **Empty Trash**

### Option 2 — CLI for your user

```bash
gio trash --empty
```

### Option 3 — Manually remove trash folder on the external drive

```bash
sudo rm -rf /media/<user>/<DriveName>/.Trash-1000
```

---

If you want, I can explain how to **disable trash on external drives** or make delete always “permanent” when on removable disks.

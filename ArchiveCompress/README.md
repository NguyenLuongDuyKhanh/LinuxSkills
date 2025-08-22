# Files archiving

A tar file (short for 'tape archive') in Linux is a type of compressed or uncompressed file that consolidates multiple files and directories into a single file for easier storage, backup, or sharing.
Archiving, Not Compression: The tar command itself doesn't compress files; it just bundles them together. For compression, it’s often combined with tools like 
    gzip (resulting in .tar.gz or .tgz files) or 
    bzip2 (yielding .tar.bz2 files).

Got it 👍 Let’s break this down clearly.

There are two related but different concepts:

### 1. **Archive file**

* An **archive** is a collection of files packaged together into a single file (no compression by default).
* Example: `tar`, `cpio`, `zip` (when used only to archive, not compress).
* **Size**:

  * About equal to the **sum of the original files**, plus a small overhead for metadata (file names, permissions, timestamps, etc.).
  * Example: If you archive three files of 1 MB each, the archive will be \~3 MB + a few KB overhead.

---

### 2. **Compressed file**

* A **compressed file** is one where data is encoded to reduce size.
* Tools: `gzip`, `bzip2`, `xz`, `7z`, `zip` (with compression enabled).
* **Size**:

  * Depends on the **compressibility of the data**.
  * Text, logs, source code → compress very well (up to 80–90% smaller).
  * Already compressed data (JPEG, MP4, MP3, ZIP inside ZIP) → compress very little or not at all.
  * Example: A 10 MB log file may compress to \~2 MB with `gzip`.

---

### 3. **Archive + compression**

* Common workflow:

  * `tar` (archive multiple files) + `gzip` (compress) → `.tar.gz`
  * `tar` + `xz` → `.tar.xz`
* This gives you **both**: one file to store/share **and** reduced size.

---

✅ **Quick Comparison Example**
Let’s say you have three files, each 1 MB:

* Original total: **3 MB**
* Archive only (`tar`): \~**3.01 MB** (just metadata added)
* Archive + gzip: maybe **1.2 MB** (depends on content compressibility)

---

👉 Do you want me to show you a **real Linux demo with commands** (`ls -lh` before/after archive + compression) so you can see actual size differences?

# Advanced_keylogger

# 🔐 Advanced Keylogger in C

An advanced keylogger written in C for **educational** and **ethical cybersecurity research** purposes. This project demonstrates how keylogging techniques work at a low level using system APIs, useful for ethical hacking, malware analysis training, and building defensive tools.

> ⚠️ **Disclaimer:** This project is for **educational use only**. Unauthorized use of keyloggers is illegal and unethical. Always get proper consent before testing.

---

## 🚀 Features

- 🖥️ **Stealth Operation** – Runs in the background with minimal visibility.
- ⌨️ **Keystroke Logging** – Captures all keystrokes including alphanumeric and special keys.
- 🕒 **Time-Stamped Logging** – Optionally records the timestamp of each keypress.
- 💾 **File Logging** – Saves keystrokes to a local log file.
- 🔁 **Persistence (Optional)** – Can be configured to start on system boot (for ethical test labs only).
- 💡 **Windows/Linux Support** – Platform-dependent implementations.

---

## 🛠️ Tech Stack

- **Language:** C
- **Libraries (Windows):** `windows.h`, `stdio.h`, `time.h`
- **Libraries (Linux):** `stdio.h`, `fcntl.h`, `unistd.h`, `/dev/input/` APIs

---




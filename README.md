# Student Management System (C-Project)

A menu-driven console application for managing student academic records, including automated grading and persistent file storage.

## 📋 Features
* **Add Student**: Capture Name, ID, and marks for Math, English, and Computer.
* **Auto-Calculate**: Automatically determines Total, Average, and Grade.
* **Search**: Find specific students using their Student Number.
* **File Storage**: Saves all processed results to `students.txt`.

## 📊 Grading Scale
* **80 - 100**: A
* **70 - 79**: B
* **60 - 69**: C
* **50 - 59**: D
* **Below 50**: F

## 🛠️ Compilation & Execution
To run this project in Termux:
```bash
gcc Student-Records.c -o portal
./portal


# Student Record Management System in C

A simple **Student Record Management System** built in **C language** using **structures, functions, and file handling**.  
This project allows users to manage student records through a **menu-driven program** in the terminal.

---

## Features

- Add a new student record
- View all student records
- Search student by roll number
- Update student details
- Delete student record
- Store records in a file using `students.txt`
- Prevent duplicate roll numbers

---

## Technologies Used

- **C Language**
- **File Handling**
- **Structures**
- **Functions**
- **VS Code / GCC Compiler**

---

## Project Structure

```bash
student-record-management-system-c/
│── .gitignore
│── main.c
│── README.md
│── students.txt


Student Data Format

Student records are stored in students.txt using this format:

Roll|Name|Age|Course|Marks

Example:

101|Maharshi Dabgar|21|BSc IT|88.50
102|Rahul Modi|20|Computer Science|76.00
Menu Options

When you run the program, you get these options:

1. Add Student
2. View All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
Concepts Used in This Project

This project helps practice:

Structures in C
File handling (fopen, fclose, fprintf, fscanf)
Functions
Conditional statements
Loops
Searching and updating records
Temporary file handling for delete/update operations

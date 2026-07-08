# Student Record Management System in C

A menu-driven **Student Record Management System** built in **C language** using **structures, functions, and file handling**.  
This project helps manage student records with features like **adding, viewing, searching, updating, deleting, counting students, showing the topper, and displaying grades**.

---

## Features

- Add a new student record
- View all student records
- Search student by roll number
- Update student details
- Delete student record
- Count total students
- Show topper student
- Display grade based on marks
- Store records in a file using `students.txt`
- Prevent duplicate roll numbers

---

## Technologies Used

- **C Language**
- **Structures**
- **Functions**
- **File Handling**
- **VS Code / GCC Compiler**

---

## Project Structure

```bash
student-record-management-system-c/
│── .gitignore
│── main.c
│── README.md
│── students.txt

temp.txt is created temporarily during update/delete operations and should not be pushed to GitHub.

Student Data Format

Student records are stored in students.txt using the following format:

Roll|Name|Age|Course|Marks
Example:
101|Maharshi Dabgar|21|BSc IT|88.50
102|Rahul Modi|20|Computer Science|76.00
Menu Options
1. Add Student
2. View All Students
3. Search Student
4. Update Student
5. Delete Student
6. Count Total Students
7. Show Topper Student
8. Exit
Grade System

The project assigns grades based on student marks:

Marks Range	Grade
90 and above	A
75 – 89	B
60 – 74	C
40 – 59	D
Below 40	F
Concepts Used in This Project

This project helps practice and understand:

Structures in C
File handling (fopen, fclose, fprintf, fscanf)
Functions
Loops and conditional statements
Searching and updating records
Temporary file handling for delete/update operations
Real-world data management logic in C
How It Works

The program stores student data in a text file named students.txt.
Each student record is saved in a single line using the | separator.

The program allows users to:

enter student details,
save them in the file,
search for a student using roll number,
update or delete existing records,
count total students,
and find the student with the highest marks.
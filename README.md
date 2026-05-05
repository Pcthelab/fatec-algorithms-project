# Student Management System | Fatec Mogi Mirim

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Fatec](https://img.shields.io/badge/Course-ADS-red)

A robust academic management system built in C. This project focuses on structured data handling, dynamic memory allocation, and professional terminal interface design for the Algorithms course.

### 🛠 System Features
The software operates through an interactive menu with the following capabilities:

1. **Register Student:** Adds new students to the system using dynamic memory.
2. **Edit Data:** Updates information for existing student records.
3. **Search Student:** Quick lookup using the student's registration ID.
4. **View Details:** Displays comprehensive data for a specific student.
5. **List All Students:** Generates a formatted report of the entire database.
9. **Exit:** Securely closes the application and frees allocated memory.

### 🧠 Logic & Architecture
```text
    ┌──────────────────────────────────────────┐
    │           OPERATIONAL MENU               │
    └──────────────────────────────────────────┘
           │               │               │
    [ MEMORY ]      [ VALIDATION ]   [ INTERFACE ]
    Structs &       Unique ID        Formatted Grid
    Pointers        Verification     Output Design


Project Documentation: Student Management System
​1. Introduction
​The Student Management System is a console-based application developed in C. It is designed to assist educational administrators in capturing, calculating, and storing student academic records. The system addresses the need for accuracy in grade calculations and the necessity of persistent data storage.
​2. System Features
​The application is built with a menu-driven interface, allowing users to navigate through several key functions:
​Student Data Entry: Captures unique student identifiers, names, and marks for three core subjects (Math, English, and Computer).
​Automated Results Calculation: Computes the total marks and average for each student without manual input.
​Grading Logic: Assigns a letter grade based on a predefined academic scale.
​Record Search: Enables quick retrieval of a specific student’s full profile using their Student Number.
​Persistent Storage: Exports all student data into a permanent text file (students.txt) for future reference.
​3. Technical Design
​Data Structure
​The program utilizes a struct (Structure) named Student. This allows the system to group different data types (Strings, Integers, and Floats) into a single record.
​char name[50] – Stores the full name.
​int studentNo – Acts as the primary key for searches.
​int math, english, computer – Stores raw marks.
​float average – Stores the calculated mean.
​char grade – Stores the assigned letter grade.
​Grading Algorithm
​The system applies a conditional if-else logic to determine performance:

Average Mark Grade
80 - 100 A
70 - 79 B
60 - 69 C
50 - 59 D
Below 50 
4. File Handling
​To ensure that data is not lost when the program is closed, the system implements the following C file functions:
​fopen(): Opens (or creates) students.txt in write mode.
​fprintf(): Writes the structured student data into the text file.
​fclose(): Safely closes the file stream to prevent data corruption.
​5. How to Run the Program
​The project is designed to be compiled using the GCC compiler.
​Compile: gcc Student-Records.c -o portal
​Execute: ./portal
​Operation: Follow the on-screen menu by entering numbers 1 through 6.
​6. Conclusion
This system provides a reliable framework for managing student data. By combining structures, loops, and file handling, it demonstrates a complete workflow from data input to permanent storage, ensuring academic records are handled efficiently and accurately.

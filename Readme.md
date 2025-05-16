# Group 1 Title: Student Cafeteria Management System (use doubly linked list)

---

## **Regex Explanation**

### **How the Regex Works to Check ID**
- `^` → Start of the string.
- `nascr` → Exactly "nascr" (case-insensitive) is allowed (`regex_constants::icase`).
- `/` → A literal forward slash.
- `\d{4}` → Exactly 4 digits.
- `/` → Another literal forward slash.
- `\d{2}` → Exactly 2 digits.
- `$` → End of the string.

### **Regex to Check Name**
- `^[A-Za-z ]+$` → Only words (letters) and spaces are allowed.

---

## **Program Overview**

This program implements a **Student Cafeteria Management System** using a **Doubly Linked List (DLL)**. It provides functionalities to manage a list of students, including adding, displaying, searching, sorting, and resetting the list.

### **Key Features**
1. **Add Students**:
   - Add students at the beginning, end, or a specific position in the list.
   - Validates student IDs and names before adding.

2. **Display Students**:
   - Displays all students in the list in a readable format.

3. **Search Students**:
   - Search for a student by their ID (case-insensitive).

4. **Sort Students**:
   - Sorts the list of students alphabetically by their names.

5. **Reset List**:
   - Deletes all students from the list.

6. **Validation**:
   - Validates student IDs using a regex pattern.
   - Validates student names to ensure they contain only letters and spaces.

7. **Menu-Driven Interface**:
   - Provides a user-friendly menu to interact with the system.

---

## **Functions in the Code**

### **1. `isValidID(string id)`**
- Validates the format of a student ID using a regex pattern.
- Returns `true` if the ID matches the pattern, otherwise `false`.

### **2. `isValidName(string name)`**
- Validates the format of a student name using a regex pattern.
- Ensures the name contains only letters and spaces.

### **3. `displayStudents()`**
- Displays all students in the list.
- Prints "List is empty!!!" if the list is empty.

### **4. `insertStudentBeg(string name, string id)`**
- Inserts a new student at the beginning of the list.

### **5. `insertStudentEnd(string name, string id)`**
- Inserts a new student at the end of the list.

### **6. `insertStudentPos(string name, string id, int pos)`**
- Inserts a new student at a specific position in the list.
- Handles cases where the position is greater than the length of the list by inserting at the end.

### **7. `toLowerCase(string str)`**
- Converts a string to lowercase for case-insensitive comparisons.

### **8. `searchStudent(string id)`**
- Checks if a student with the given ID already exists in the list.
- Returns `true` if the ID exists, otherwise `false`.

### **9. `searchStudentById(string id)`**
- Searches for a student by their ID and displays their details.
- Prints a message if the student is not found.

### **10. `resetList()`**
- Deletes all students from the list.
- Frees up memory and resets the list to an empty state.

### **11. `sortStudents()`**
- Sorts the list of students alphabetically by their names using Bubble Sort.
- Swaps only the `studentName` and `studentId` fields to avoid breaking the list structure.

### **12. `getValidInteger(string prompt)`**
- Ensures that only valid integer inputs are accepted from the user.
- Displays the provided `prompt` message and re-prompts the user if invalid input is entered.
- Handles invalid inputs by clearing the error flag and discarding invalid characters from the input buffer.
- Returns the valid integer entered by the user.


### **13. `main()`**
- Implements a menu-driven interface for the user to interact with the system.
- Options include:
  1. Add Students
  2. Display Students
  3. Reset List
  4. Display Sorted Students List
  5. Search Student by ID
  6. Exit

---

## **Menu Options in `main()`**

1. **Add Students**:
   - Prompts the user to enter the number of students to add.
   - Validates the student ID and name before adding.
   - Allows the user to specify where to add the student (beginning, end, or specific position).

2. **Display Students**:
   - Displays all students in the list.

3. **Reset List**:
   - Deletes all students from the list and resets it to an empty state.

4. **Display Sorted Students List**:
   - Sorts the list alphabetically by student names and displays the sorted list.

5. **Search Student by ID**:
   - Prompts the user to enter a student ID and searches for the student in the list.

6. **Exit**:
   - Exits the program.

---

## **Summary**
- The program uses a doubly linked list to manage student data.
- It ensures data integrity through validation functions.
- The menu-driven interface allows users to perform various operations on the student list.
- The program is modular, with each function handling a specific task, making it easy to maintain and extend.

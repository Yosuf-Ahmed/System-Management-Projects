# 📚 Library Management System

A simple C++ console-based application that simulates a full library system where users can borrow and return books, and administrators can manage both books and users.

---

## 📋 System Requirements

The system supports:

- A configurable number of books (`MAX_BOOKS`) — default: **6**
- A configurable number of users (`MAX_USERS`) — default: **10**
- Each book can have up to `MAX_Copies` (default:   **10**)
- Constants are defined in the code and can be easily modified



Each **book** has:
- Name
- Unique ID
- Total quantity
- Borrowed count
- Borrower list

Each **user** has:
- Name
- Unique ID
- List of borrowed books
- Borrowed count

---

## ⚙️ System Functionalities

### 1️⃣ Add Book
- Prompts for:  
  ➤ Book name  
  ➤ Book ID  
  ➤ Total quantity  
- Adds the book to the system if there's space.

---

### 2️⃣ Search Book
- Two search options:  
  ➤ **By ID**  
  ➤ **By name prefix**  
- Displays detailed book info or matching names.

---

### 3️⃣ Print Who Borrowed a Specific Book
- Prompts for book name  
- Shows list of usernames who borrowed that book

---

### 4️⃣ Print Library by ID
- Sorts all books by `Book_ID`  
- Displays their data in sorted order

---

### 5️⃣ Print Library by Name
- Sorts all books by `Book_name` alphabetically  
- Displays their data in sorted order

---

### 6️⃣ Add User
- Prompts for:  
  ➤ User name  
  ➤ National ID  
- Adds the user to the system

---

### 7️⃣ User Borrows Book
- Prompts for:  
  ➤ User name  
  ➤ Book name  
- Validates:  
  ➤ Book exists  
  ➤ Copies available  
  ➤ User exists  
  ➤ User hasn’t already borrowed the book  
- Updates both user and book records

---

### 8️⃣ User Returns Book
- Prompts for:  
  ➤ User name  
  ➤ Book name  
- Validates user and book  
- Updates records to reflect return

---

### 9️⃣ Print All Users
- For each user:  
  ➤ Lists borrowed books by ID  
  ➤ Or notes that no books are borrowed

---

### 🔟 Exit
- Terminates the program

---

## 🔁 System Workflow

```text
Start
  ↓
Show menu
  ↓
User selects an operation:
  ├─➤ Add Book
  ├─➤ Search Book (by ID or prefix)
  ├─➤ Print Book Borrowers
  ├─➤ Sort & Print Library
  ├─➤ Add User
  ├─➤ Borrow Book
  ├─➤ Return Book
  ├─➤ Print All Users
  └─➤ Exit
  ↓
Repeat until exit

``` 
## 📦 Project Structure

```
Library-Management/
│
├── main.cpp           # Full system implementation
├── README.md          # Project documentation
└── [Future Files]     # For modularization, file handling, classes

```


## 🚀 Features Summary

✔️ Add and manage books  
✔️ Add users to the system  
✔️ Borrow and return operations with validation  
✔️ Search and sort functionality  
✔️ Console-based UI with menus  
✔️ Tracks relations between users and books  

---

## 🛠️ Future Improvements

✅ Add persistent storage using file I/O  
✅ Refactor to OOP with classes & encapsulation  
✅ Replace raw arrays with STL containers (`vector`, `map`)  
✅ Split code into multiple files for modularity (`.h / .cpp`)  
✅ Add user login system and permissions (admin/user roles)  

---

## 👨‍💻 Author

**Youssef Ahmed**

This project is part of my self-directed journey to master:

✅ C and C++ programming fundamentals  
✅ OOP and system design  
✅ Low-level programming through real-world simulation  
✅ Problem-solving via structured projects  
✅ Building clean, maintainable, and scalable systems  


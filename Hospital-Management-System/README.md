# 🏥 Hospital Management System

A simple C++ console application that simulates **patient queue management** across different medical specializations.

---

## 📋 System Requirements

- The hospital supports **20 specializations** (e.g., Pediatrics, Surgery, etc.).
- Each specialization maintains a **queue of up to 5 patients**.
- Each patient has:
  - A **name**
  - A **status**: `0 = regular`, `1 = urgent`

---

## ⚙️ System Functionalities

### 1️⃣ Add New Patient
- Prompt for:
  - Specialization number (`1–20`)
  - Patient name
  - Patient status (`0` for regular, `1` for urgent)
- If queue is full → **Display error**
- If **urgent** → Insert at the **front** of the queue (with shifting)
- If **regular** → Insert at the **end** of the queue

---

### 2️⃣ Print Patients of a Specialization
- Prompt for specialization number
- Display:
  - Number of patients
  - Names and statuses (regular/urgent)

---

### 3️⃣ Print All Patients
- Iterate through **all specializations**
- For each specialization:
  - If it has patients, display their data

---

### 4️⃣ Get Next Patient
- Prompt for specialization number
- If queue is **not empty**:
  - Display the name of the first patient
  - Remove the patient from the queue (with shifting)
- If queue is **empty**:
  - Display "No patients, take rest Dr"

---

### 5️⃣ Exit
- Prompt for confirmation: `Y/N`
- If confirmed → Exit program
- Otherwise → Return to menu

---

## 🔁 System Workflow

```text
Start
  ↓
Show menu
  ↓
User selects an operation:
  ├─➤ Add new patient
  ├─➤ Print patients of specialization
  ├─➤ Print all patients
  ├─➤ Get next patient
  └─➤ Exit
  ↓
Repeat until exit

```

## 📦 Project Structure
```text
Hospital-Management/
│
├── main.cpp           # Project implementation
├── README.md          # Project documentation
└── [Future Files]     # STL, file handling, modular headers (planned)

```

## 🚀 Features Summary

- ➕ Add **regular/urgent** patients to specialization queues  
- 📋 Print **specific** or **all** specialization queues  
- 🩺 Serve patients in **priority order** (urgent first)  
- 🧭 Clear and interactive **console-based UI**  

---

## 🛠️ Future Improvements

- ✅ Add **file persistence** using C++ file I/O (`fstream`)
- ✅ Refactor into **OOP design** using classes and encapsulation
- ✅ Replace raw arrays with modern **STL containers** (`vector`, `queue`)
- ✅ Use **modular architecture** with headers and source files (`.h`, `.cpp`)

---

## 👨‍💻 Author

**Youssef Ahmed**  
> This project is part of my self-directed journey to master:
> - ✅ C and C++ programming fundamentals 
> - ✅ OOP (Object Oriented Programming)
> - ✅ System design and simulation  
> - ✅ Clean and maintainable code structure  
> - ✅ Problem-solving through real-world projects

---





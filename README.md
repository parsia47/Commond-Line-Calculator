# Command-Line Calculator (C)

## 📌 Overview

This project is a **line-oriented command-line calculator** written in **C**. It processes user input one line at a time and supports basic arithmetic operations such as addition, subtraction, multiplication, and division.

The calculator is designed to demonstrate **clean structure, input validation, and modular programming**, improving upon typical first-year implementations by removing duplicated logic and organizing functionality into clear functions.

---

## ⚙️ Features

* Supports basic arithmetic operations:

  * Addition (`+`)
  * Subtraction (`-`)
  * Multiplication (`*`)
  * Division (`/`)
* Line-oriented input (operation followed by a number)
* Continuous execution until the user chooses to exit
* Input validation to handle invalid operations and edge cases (e.g., division by zero)
* Clear and readable output messages

---

## 🛠️ Technologies Used

* **Language:** C
* **Environment:** Command-line / Terminal
* **Concepts Demonstrated:**

  * Functions
  * Conditional logic
  * Loops
  * Input validation
  * Clean code practices

---

## ▶️ How to Run

### Compile

```bash
gcc calculator.c -o calculator
```

### Run

```bash
./calculator
```

---

## 🧪 Example Usage

```
Enter operation (+, -, *, /) and number: + 5
Current result: 5

Enter operation (+, -, *, /) and number: * 3
Current result: 15

Enter operation (+, -, *, /) and number: / 0
Error: Division by zero is not allowed.
```

---

## 📚 What I Learned

* How to design a **line-oriented program** that continuously processes user input
* The importance of **refactoring** to remove duplicated code
* Writing clearer and more maintainable C programs
* Handling edge cases and invalid user input gracefully

---

## 🚀 Why This Project Matters

This project reflects my growth beyond beginner-level C programming. While earlier versions of this assignment typically exceeded several hundred lines due to repeated logic, this implementation focuses on **clarity, efficiency, and maintainability** without sacrificing functionality.

---

## 👤 Author

**Parsia Zahedi**
Computer Science (Software Engineering) Student

---

## 📎 Notes

This project was originally developed as part of a university coursework assignment and has since been refined for portfolio purposes.

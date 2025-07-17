# Scientific Calculator - C++

A console-based **scientific calculator** written in C++.  
Supports basic arithmetic, scientific functions, input parsing, error detection, and uses ANSI colors for enhanced terminal output.

---

## 🔧 Technologies Used

- C++ (Standard Library)
- ANSI escape codes for terminal colors

---

## 🧮 Features

- Arithmetic operations: `+`, `-`, `*`, `/`, `^` (exponentiation)  
- Scientific functions: `sin`, `cos`, `tan` (in degrees), `sqrt`, `log` (base 10), `ln` (natural log)  
- Input parsing: Supports parentheses and function calls in user input  
- Error handling: Detects invalid input, division by zero, out-of-range values — displays "Error" in red  
- Reset/Clear: Type `"clear"` to reset calculator state  
- Color-coded output:  
  - Cyan prompts (`>>`)  
  - Magenta for results  
  - Red for errors (works in modern terminals)


---

⚠️ Limitations
-Console-based only, no GUI
-ANSI colors require compatible terminal (Linux Terminal, macOS Terminal, Windows Terminal with VT mode enabled)
-Basic parsing, complex nested expressions may not fully work

---

## 🖥️ How to Compile and Run

```bash
# Compile with g++
g++ -o scientific_calculator main.cpp

# Run the executable
./scientific_calculator

🙋‍♀️ Author
Chamodi Kumarage

GitHub: chamodi-kumarage




# Math Game

A simple console-based Math Game built with C++ that helps users practice arithmetic operations through randomly generated questions.

## Features

- Choose the number of questions.
- Select difficulty level:
  - Easy
  - Medium
  - Hard
- Select operation type:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Modulus (%)
  - Mixed Operations
- Instant feedback after each answer.
- Score tracking.
- Color indication for correct and wrong answers.
- Option to play again after finishing the game.

---

## How It Works

### 1. Choose Number of Questions

The game asks how many questions you want to answer.

Example:

```text
Please enter the number of questions you want to answer: 10
```

### 2. Select Difficulty Level

```text
[1] Easy
[2] Medium
[3] Hard
```

| Level | Number Range |
|---------|-------------|
| Easy | 1 - 10 |
| Medium | 10 - 99 |
| Hard | 100 - 999 |

### 3. Select Operation

```text
[1] Add
[2] Sub
[3] Mul
[4] Div
[5] Mod
[6] Mix
```

Mixed mode randomly chooses one of the available operations for each question.

### 4. Answer Questions

Example:

```text
Question 1:

7 + 8 = ?
15
```

The game immediately tells you whether your answer is correct or wrong.

### 5. Final Results

After all questions are completed, the game displays:

- Total Questions
- Correct Answers
- Wrong Answers
- Final Score
- Win / Lose / Tie Result

---

## Technologies Used

- C++
- Object-Oriented Programming Concepts
- Structures
- Enumerations (Enums)
- Dynamic Memory Allocation
- Random Number Generation

---

## Project Structure

### Enums

```cpp
enLevel
enOperator
enAgain
```

Used to represent:

- Difficulty levels
- Mathematical operations
- Play again option

### Structure

```cpp
stQuestion
```

Stores:

- First number
- Second number
- Operator
- Correct result
- Question status

### Main Functions

| Function | Description |
|-----------|------------|
| Read_Num_Questions() | Reads number of questions |
| Read_Level() | Reads game difficulty |
| Read_Operator() | Reads operation type |
| Random_Num() | Generates random numbers |
| Ask_Question() | Displays and evaluates questions |
| Print_Score_Status() | Shows final score |
| Play_Again() | Allows replaying |
| Print_Total_Questions() | Runs the game loop |

---

## Build & Run

Using g++:

```bash
g++ main.cpp -o MathGame
MathGame.exe
```

Or open the project in Visual Studio and run it directly.

---

## Example Gameplay

```text
Please enter the number of questions you want to answer: 5

Choose level:
[1] Easy
[2] Medium
[3] Hard

Choose operation:
[1] Add
[2] Sub
[3] Mul
[4] Div
[5] Mod
[6] Mix

Question 1:
8 + 4 = ?
12

Your answer is Correct
```

---

## Learning Objectives

This project was created to practice:

- C++ Fundamentals
- Functions
- Arrays
- Structures
- Enums
- Dynamic Memory
- User Input Validation
- Random Number Generation
- Console Applications

---

## Author

**Mohamed Jehad**

GitHub: https://github.com/muhammedgihad10-png

---

⭐ If you like this project, consider giving it a star on GitHub.

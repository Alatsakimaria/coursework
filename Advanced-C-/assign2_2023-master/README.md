# Assignment 2: A String Module in C

## Overview

This assignment involves creating a custom string module in C called **MyString**. The module implements common string manipulation functions similar to those found in the C standard library (`string.h`). The goal is to practice using arrays, pointers, and modular programming in C, as well as to gain experience with GNU/UNIX tools like `gcc`, shell scripting, and text editors (e.g., *emacs* or *vim*).

## MyString Module Functions

| **MyString Function** | **Equivalent C Standard Library Function** |
| --------------------- | -------------------------------------------- |
| `ms_length`           | `strlen`                                     |
| `ms_copy`             | `strcpy`                                     |
| `ms_ncopy`            | `strncpy`                                    |
| `ms_concat`           | `strcat`                                     |
| `ms_nconcat`          | `strncat`                                    |
| `ms_compare`          | `strcmp`                                     |
| `ms_ncompare`         | `strncmp`                                    |
| `ms_search`           | `strstr`                                     |

## Implementation

The module is implemented in two ways:

- **Array Notation:** See `mystring_ars.c`.
- **Pointer Notation:** See `mystring_ptrs.c`.

Each function is designed to handle edge cases (e.g., empty strings, `NULL` inputs) and includes runtime error checking using the `assert` macro.

## How to Run the Code

### Prerequisites

- A C compiler (e.g., `gcc`).
- A UNIX-like environment (Linux, macOS, or WSL on Windows).

### Steps to Compile and Run

1. **Compile the Code Using `gcc`:**

    - **For the Array-Based Implementation:**

      ```bash
      gcc -Wall -ansi -pedantic mystring_ars.c -o mystring_ars
      ```

    - **For the Pointer-Based Implementation:**

      ```bash
      gcc -Wall -ansi -pedantic mystring_ptrs.c -o mystring_ptrs
      ```

3. **Run the Compiled Program:**

    - **Array-Based Implementation:**

      ```bash
      ./mystring_ars
      ```

    - **Pointer-Based Implementation:**

      ```bash
      ./mystring_ptrs
      ```

## Key Features

- **Modular Design:** Implemented using a header file (`mystring.h`) and two source files (`mystring_ars.c` and `mystring_ptrs.c`).
- **Error Checking:** Each function employs the `assert` macro for runtime error validations, like checking for `NULL` pointers.
- **Edge Case Handling:** Functions are rigorously tested for edge cases such as empty strings and invalid inputs.
- **Dual Implementation:** Provides both array-based and pointer-based approaches, offering a comparison in methodology.

## Questions and Answers

### Memory Checks for Destination Buffers

- **Can `ms_copy`, `ms_ncopy`, `ms_concat`, and `ms_nconcat` use `assert` to check if the destination memory is large enough?**

  No, the `assert` macro only evaluates conditions and terminates the program if the condition fails. It cannot determine the size of the destination memory. A proper memory size check would require additional logic or manual verification.

### Checking the Length Parameter

- **Can `ms_ncopy`, `ms_nconcat`, and `ms_ncompare` use `assert` to check if the length parameter is negative?**

  No, because the length parameter is of type `size_t`, an unsigned integer, which makes a negative value impossible. Therefore, such a check is unnecessary.

## Implementation Details

- **Array-Based Implementation:** Functions in `mystring_ars.c` use array notation (e.g., `pcStr[i]`).
- **Pointer-Based Implementation:** Functions in `mystring_ptrs.c` utilize pointer arithmetic (e.g., `*(pcStr + i)`), optimizing for efficiency.

## Files

- **`mystring.h`**: Header file containing the function declarations.
- **`mystring_ars.c`**: Source file with array-based implementations.
- **`mystring_ptrs.c`**: Source file with pointer-based implementations.
- **`README.md`**: This file, providing an overview of the project.


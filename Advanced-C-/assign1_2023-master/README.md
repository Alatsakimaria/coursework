# Translate Program (ISO8859-7 to ISO8859-1)

### Author

**Alatsaki Maria Foteini**

### Description

This program translates Greek characters from ISO8859-7 encoding to Latin characters in ISO8859-1. It functions as a Unix shell filter, reading input from standard input and writing the translated output to standard output.

### Features

- **Converts Greek characters to their Latin equivalents**
- **Handles accented and diaeresis characters**
- **Implements state machine for handling digraphs (e.g., ΜΠ -> B, ΝΤ -> D)**
- **Uses `getchar()`/`putchar()` for efficient character processing**

### Files

- **`main.c`**: The main source file containing the entire program.
- **`tests/`**: Folder containing test files for verification.

### Compilation
```bash
gcc -Wall -ansi -pedantic -o translate main.c

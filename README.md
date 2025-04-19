## **ft_printf**
ft_printf is a custom implementation of the standard printf function in C, developed as part of the 42 School curriculum. This project involves recreating a simplified version of printf that handles various format specifiers and conversions.
Table of Contents

1:Description
2:Supported Format Specifiers
3:Installation
4:Usage
5:How It Works
6:Testing

## **Description**
The goal of ft_printf is to recode the standard printf function from libc, supporting the following features:
* Handling of format strings with % specifiers
* Conversion of different data types (char, string, int, hexadecimal, etc.)
  
This project helps deepen understanding of variadic functions, string formatting, and memory management in C.


## **Supported Format Specifiers**  

| Specifier | Description                          | Example Usage                   | Output Example            |
|-----------|--------------------------------------|----------------------------------|---------------------------|
| `%c`      | Prints a single character            | `ft_printf("%c", 'A')`          | `A`                       |
| `%s`      | Prints a string                      | `ft_printf("%s", "Hello")`      | `Hello`                   |
| `%p`      | Prints a pointer address (hex)       | `ft_printf("%p", ptr)`          | `0x7ffeee3a4b20`          |
| `%d`/`%i` | Prints a signed decimal integer      | `ft_printf("%d", 42)`           | `42`                      |
| `%u`      | Prints an unsigned decimal integer   | `ft_printf("%u", 255)`          | `255`                     |
| `%x`      | Prints lowercase hexadecimal         | `ft_printf("%x", 255)`          | `ff`                      |
| `%X`      | Prints uppercase hexadecimal         | `ft_printf("%X", 255)`          | `FF`                      |
| `%%`      | Prints a percent sign                | `ft_printf("%%")`               | `%`                       |

---

### **Notes**:
- **`%p`**: Output is implementation-dependent but typically in hexadecimal with `0x` prefix.
- **`%x`/`%X`**: Handles unsigned integers. `%x` uses `a-f`; `%X` uses `A-F`.
- **`%%`**: Escapes the `%` character to print it literally.

### **Installation**:
Clone the repository:
```sh
git clone https://github.com/your-username/ft_printf.git
cd ft_printf
```
Compile the library:

```sh
make
```
This generates libftprintf.a, a static library containing the ft_printf function.
### **Usage**:
Include the header in your C file:

```sh
#include "ft_printf.h"
```
Link the library when compiling:
```sh
gcc your_program.c -L. -lftprintf -o your_program
```
### **Example**:

```sh
#include "ft_printf.h"

int main() {
    int num = 42;
    ft_printf("Number: %d, Hex: %x, String: %s\n", num, num, "Hello");
    return 0;
}
```
### **Output**:

```sh
Number: 42, Hex: 2a, String: Hello
```
### **How It Works**:

1 : Parsing the Format String:
* Scans for % and processes the specifier.
2 : Variadic Arguments:
* Uses va_list, va_start, va_arg, and va_end to retrieve arguments.
3 : Conversion & Printing:
* Converts each argument into the correct format (e.g., %d → integer, %x → hexadecimal).
* Writes the result to stdout using write().

### **Testing**:
To ensure correctness, compare against the real printf:

```sh
#include <stdio.h>
#include "ft_printf.h"

int main() {
    printf("Real printf: %d\n", 42);
    ft_printf("ft_printf: %d\n", 42);
    return 0;
}
```

This README.md provides a structured overview of ft_printf.


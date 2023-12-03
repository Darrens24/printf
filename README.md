![Badge Name](ft_printfm.png)

# printf

## Overview
`ft_printf` is a 42 school project that aims to replicate the functionality of the C standard library function `printf`. This project serves as an exercise in handling variadic functions, parsing input strings, and formatting output in C. It demonstrates the ability to process various conversion specifiers and flags, closely mimicking the behavior of the original `printf`.

## Learning Objectives
Through the development of `ft_printf`, the following key skills and concepts in C programming were emphasized:
- Mastery of variadic functions to handle an indefinite number of arguments.
- Deep understanding of format specifiers (`%s`, `%d`, `%x`, etc.) and their implementation.
- Proficiency in string manipulation and memory management.
- Enhanced familiarity with the C Standard Library and its functions.

## Implementation Details
The implementation of `ft_printf` involved several steps:
- **Parsing Input**: Developed a robust parser to interpret format specifiers and flags within the input string.
- **Handling Format Specifiers**: Implemented functionality for common specifiers like `%s` (strings), `%d` (decimal integers), and `%x` (hexadecimal).
- **Flag and Width Management**: Included support for various flags (e.g., `-`, `+`, `#`) and width/precision specifications for detailed formatting.

## Challenges and Problem Solving
Some of the significant challenges faced during the project included:
- **Accurate Parsing**: Ensuring the parser correctly identifies and processes all components of the format string.
- **Memory Efficiency**: Managing memory allocation and deallocation effectively to avoid leaks.
- **Edge Cases**: Handling edge cases and ensuring consistent behavior with the standard `printf`.

## Usage and Examples
To use `ft_printf` in your projects, compile it with your source files. Here’s a basic example of compiling and using `ft_printf`:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!", "world");
    return 0;
}

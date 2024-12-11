# Custom String Class Implementation in C++

## Overview
This project implements a custom string class (`stringg`) that mimics the functionality of the standard C++ string class. It provides a comprehensive set of string manipulation operations and overloaded operators for efficient string handling.

## Features

### Basic Operations
- Dynamic memory management
- Deep copy support
- String concatenation
- Character access through subscript operator
- Comparison operations

### Constructors
- Default constructor
- Parameterized constructor (from C-style string)
- Copy constructor
- Destructor for proper memory cleanup

### Overloaded Operators
- Assignment operator (`=`)
- Addition operator (`+`) for string concatenation
- Subscript operator (`[]`)
- Relational operators (`<`, `>`, `>=`, `<=`, `!=`, `==`)
- Stream operators (`<<`, `>>`) for input/output operations

### String Manipulation Functions
- `strcpy` - Copy strings
- `strncpy` - Copy n characters from source to destination
- `strcmp` - Compare strings
- `strncmp` - Compare n characters of strings
- `strcat` - Concatenate strings
- `strncat` - Concatenate n characters
- `strrev` - Reverse string
- `strlower` - Convert to lowercase
- `strupper` - Convert to uppercase
- `strchr` - Find character in string
- `strstr` - Find substring in string
- `strlen` - Get string length

## Implementation Details
- Uses dynamic memory allocation for string storage
- Implements proper memory management to prevent memory leaks
- Provides bounds checking for safe operations
- Maintains string length for efficient operations

## Usage Example

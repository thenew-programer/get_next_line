# Get Next Line

## Overview

This project implements a C function named `get_next_line()` to efficiently read a single line from a file descriptor (fd) at a time. The function is designed to handle dynamic buffer sizes and leverages advanced C programming concepts like static variables. The implementation is modular, with utility functions provided in separate files.

## Project Concepts

### 1. Static Variables

The project uses static variables to maintain the state of the reading process across multiple calls to `get_next_line()`. Static variables in C retain their value between function calls, enabling partial line data to be preserved until the next read. This is crucial for:

- Handling lines that span multiple reads.

- Managing file descriptors in a thread-safe way (extended in the bonus part).

### 2. I/O Operations

key I/O functions used:

- `read()`: Reads a specified number of bytes from the file descriptor into a buffer.

- `malloc()`: Allocates memory dynamically for storing intermediate and final results.

- `free()`: Frees allocated memory to prevent leaks.

The program is optimized to minimize the number of read() calls, improving performance by processing data in chunks specified by the buffer size.

### 3. File Descriptors

In Unix-like operating systems, file descriptors are integral values used by the kernel to represent open files or I/O streams. Every process has access to a table of file descriptors that provide a way to interact with files, pipes, sockets, or other I/O resources. File descriptors are crucial for managing input/output operations in C programs.

##### Key Concepts

1. Standard File Descriptors:

   - `0`: Standard Input (stdin) – Represents input from the keyboard or another input source.

   - `1`: Standard Output (stdout) – Represents output to the terminal or another output destination.

   - '2': Standard Error (stderr) – Represents error messages output to the terminal.

2. How They work:

   - When a file is opened (using functions like `open()`), the system assigns a unique file descriptor to identify the open file.

   - The `read()` function uses the file descriptor to fetch data from the associated resource.

   - The 'write()' function uses the file descriptor to send data to the resource.

3. In the Context of `get_next_line()`:

   - The file descriptor passed to `get_next_line()` specifies the file or stream to read from.

   - For example, you can pass:

     - A file descriptor obtained by opening a file.

     - `0` for standard input to read user input from the terminal.

##### Example

```c
#include <fcntl.h>
#include <unistd.h>

int fd = open("example.txt", O_RDONLY);
if (fd == -1) {
    // Handle error
}

char *line = get_next_line(fd);
close(fd); // Always close the file descriptor after use
```

### 4. Buffer Management

- The buffer size is dynamically defined using a preprocessor directive (BUFFER_SIZE).

- The program processes the buffer incrementally, ensuring only the required data is read and returned.

## Mandatory Part

### Function Prototype

```c
char *get_next_line(int fd);
```

### Key Requirement

- Return a single line from the file descriptor, including the newline character (`\n`).

- Return `NULL` if the end of the file is reached or an error occurs.

- Handle text files and standard input seamlessly.

- Avoid undefined behavior when files are modified or binary data is used.

## Bonus Part

### 1. Support for multiple File descriptors

- The function manages multiple file descriptors simultaneously using a single static variable, ensuring no cross-contamination of data.

### 2. Code Organization

- Bonus implementation files are clearly separated with `_bonus` suffixes (e.g., `get_next_line_bonus.c`).

## Compilation

Uncomment main in the `get_next_line.c` or make you're own program where you use 'get_next_line' function and compile with:

#### Mandatory Compilation

```make
make -D BUFFER_SIZE=<your-value>
```

#### Bonus Compilation

```make
make bonus -D BUFFER_SIZE=<your-value>
```

## Testing

- run:

```make
make test_all # to test mandatory and bonus part.

make test_m   # to test only mandatory part.

make test_b   # to test only bonus part.
```

## Resources

To help you understand and implement the get_next_line project, here are some recommended resources covering essential concepts like static variables, file descriptors, memory management, and I/O operations in C.

### File I/O in C

- **Article**: [File I/O in C](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
- **Video**: [Reading and wriing files in C](https://youtu.be/BQJBe4IbsvQ?si=68bYexEe2oj__uYr)

### Static Variables

- **Article**: [static variables in c](https://www.geeksforgeeks.org/static-variables-in-c/)
- **Wikipedia**: [static variable](https://www.geeksforgeeks.org/static-variables-in-c/)
- **Video**: [local, global and static variables](https://youtu.be/K9s1EuzMmYI?si=veSuiRD5LPt2ZkrI)

### Memory Management

- **Article**: [Dynamic Memory Allocation in C using `malloc()`, `calloc()`, `free()` and `realloc()`](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- **Video**: [Pointers and Dynamic Memory](https://www.youtube.com/watch?v=_8-ht2AKyH4)

### Understanding Buffers

- **Article**: [Buffer in c](https://www.geeksforgeeks.org/buffer-in-c-programming/)

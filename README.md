# 📖 Get Next Line

A 42 project implementing a function that reads a line from a file descriptor.

---

## Introduction

`get_next_line` is a function that returns the next line from a file descriptor each time it is called.  
It works with **files, standard input, and multiple file descriptors simultaneously** (bonus).

### Key Concepts

- **File descriptors** — low-level representation of an open file or input stream
- **Static variables** — retaining data between function calls without global variables
- **Buffer management** — reading chunks of data and extracting lines efficiently
- **Memory management** — allocating and freeing memory at every call without leaks
- **Multiple file descriptors** — handling several open files at the same time (bonus)

---

## Usage

### Compilation

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Full recompilation
```

### Running

You can define a custom buffer size at compilation :

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o program
```

### Include in your project

```c
#include "get_next_line.h"
```

### In your code

```c
int     fd;
char    *line;

fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Bonus — Multiple file descriptors

```c
int     fd1;
int     fd2;
char    *line;

fd1 = open("file1.txt", O_RDONLY);
fd2 = open("file2.txt", O_RDONLY);

line = get_next_line(fd1); // reads from file1
free(line);
line = get_next_line(fd2); // reads from file2
free(line);
line = get_next_line(fd1); // continues from file1
free(line);
```

> Each file descriptor keeps its own reading position — they don't interfere with each other.

---

## Return Values

| Return | Description |
|---|---|
| `string` | The next line including the `\n` character if present |
| `NULL` | End of file or an error occurred |

---

## Author

Made by [Arthur-PRZ](https://github.com/Arthur-PRZ)

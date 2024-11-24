# Maestro - A C Dynamic Array Library

# Table of Contents

1. [Description](#description)
    - [Key Features](#key-features)
    - [Memory Management](#memory-management)

3. [Maestro's Internal Logic](#maestros-internal-logic)
    - [Internal Mechanism](#internal-mechanism)
    - [Advantages](#advantages)
    - [Disadvantages](#disadvantages)

4. [Installation and Usage](#installation-and-usage)
    - [Installation](#installation)
    - [Including in Your Project](#including-in-your-project)
    - [Compilation](#compilation)

5. [Functions Guide](#functions-guide)
    - [maestro_new](#maestro_new)
    - [push_back](#push_back)
    - [pop_back](#pop_back)
    - [insert](#insert)
    - [erase](#erase)
    - [destroy](#destroy)

6. [Complete Example](#complete-example)

# Description

Maestro is a lightweight and efficient C library that implements a generic dynamic array data structure. It provides an elegant solution for managing collections of elements of any data type, offering flexible and efficient array manipulation in memory.

## Key Features

- **Type Agnostic**: Works with any data type through void* pointers
- **Dynamic Memory Management**: Automatic memory allocation and reallocation as needed
- **Intuitive API**: Clean and consistent interface for collection manipulation
- **Comprehensive Operations**: Support for fundamental operations like insertion, deletion, and appending

## Memory Management

Maestro handles all memory management internally, including:
- Initial allocation during creation
- Dynamic resizing when elements are added
- Proper cleanup when elements are removed
- Complete deallocation during destruction

This automatic memory management helps prevent memory leaks while maintaining optimal performance.

# Maestro's Internal Logic

Maestro implements a contiguous dynamic array using a void pointer (`void* data`) as its primary storage mechanism. This approach allows for storing any data type while maintaining memory efficiency and direct access capabilities.

## Internal Mechanism

The library stores elements in contiguous memory locations, which means all elements are placed next to each other in memory. When you store elements in `data`, they are placed sequentially, with each element occupying `element_size` bytes. To access an element at position `i`, Maestro performs pointer arithmetic: `data + (i * element_size)`.

### Advantages:
- **Cache Efficiency**: Contiguous storage means better cache utilization and faster memory access
- **Type Flexibility**: Using `void*` allows storing any data type
- **Direct Access**: Fast access time to any element using pointer arithmetic

### Disadvantages:
- **Reallocation Cost**: Adding elements may require reallocating and copying the entire array
- **Type Safety**: Using `void*` means type checking must be handled by the user
- **Memory Limitations**: Requires a single contiguous block of memory

# Installation and Usage

## Installation

Maestro can be easily installed by downloading the [last version](https://github.com/L-A-Marchetti/maestro/releases) and using the provided installation script:

```bash
./install.sh
```

This script will:
- Copy the header file to the appropriate system include directory
- Install the static library `libmaestro.a` to the system library path
- Set up the necessary permissions

## Usage

### Including in Your Project

To use Maestro in your C project, include the header file:

```c
#include <maestro/maestro.h>
```

### Compilation

When compiling your project, you need to link against the Maestro library.

If you're using a Makefile, add the library flag:
```makefile
LDFLAGS += -lmaestro
```

Or when compiling directly with gcc:
```bash
gcc your_program.c -o your_program -lmaestro
```

This will link your program with the Maestro library, giving you access to all its dynamic array functionality.

# Functions Guide

First, let's define our structure:
```c
typedef struct {
    int id;
    double value;
    const char* name;
} Item;
```

## `maestro_new`
Creates a new dynamic array with the specified element size.
```c
// Create an array for our Items
maestro* items = maestro_new(sizeof(Item));
```

## `push_back`
Adds a new element at the end of the array. The array will automatically resize if needed.
```c
Item new_item = {1, 3.14, "First"};
items->push_back(items, &new_item);
```

## `pop_back`
Removes the last element from the array. If the array becomes empty, it frees the memory.
```c
items->pop_back(items); // Removes the last Item
```

## `insert`
Inserts a new element at the specified position, shifting all subsequent elements one position forward.
```c
Item insert_item = {2, 2.71, "Second"};
items->insert(items, 1, &insert_item); // Inserts at position 1
```

## `erase`
Removes an element at the specified position, shifting all subsequent elements one position backward.
```c
items->erase(items, 0); // Removes Item at position 0
```

## `destroy`
Frees all allocated memory associated with the array and the array itself.
```c
items->destroy(items); // Cleans up the array
```

# Complete Example
```c
#include <maestro/maestro.h>

typedef struct {
    int id;
    double value;
    const char* name;
} Item;

int main()
{
    // Create the array
    maestro* items = maestro_new(sizeof(Item));

    // Create some Items
    Item a = {1, 1.1, "First"};
    Item b = {2, 2.2, "Second"};
    Item c = {3, 3.3, "Third"};
    Item d = {4, 4.4, "Fourth"};

    // Add elements
    items->push_back(items, &a);    // [{1, 1.1, "First"}]
    items->push_back(items, &b);    // [{1, 1.1, "First"}, {2, 2.2, "Second"}]
    items->push_back(items, &c);    // [{1, 1.1, "First"}, {2, 2.2, "Second"}, {3, 3.3, "Third"}]

    // Remove last element
    items->pop_back(items);         // [{1, 1.1, "First"}, {2, 2.2, "Second"}]

    // Insert at position 1
    items->insert(items, 1, &c);    // [{1, 1.1, "First"}, {3, 3.3, "Third"}, {2, 2.2, "Second"}]

    // Add another element
    items->push_back(items, &d);    // [{1, 1.1, "First"}, {3, 3.3, "Third"}, {2, 2.2, "Second"}, {4, 4.4, "Fourth"}]

    // Erase element at position 2
    items->erase(items, 2);         // [{1, 1.1, "First"}, {3, 3.3, "Third"}, {4, 4.4, "Fourth"}]

    // Display array contents
    for (size_t i = 0; i < items->length; i++) {
        Item current = ((Item*)items->data)[i];
        printf("Id: %d, Value: %.1f, Name: %s\n", 
               current.id, current.value, current.name);
    }

    // Clean up
    items->destroy(items);
    return 0;
}
```
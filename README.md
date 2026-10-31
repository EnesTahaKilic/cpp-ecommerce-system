# C++ E-Commerce System

A console-based e-commerce application written in C++. The project currently supports basic product management, shopping-cart operations, stock validation, and checkout.

## Features

- Add, list, search, and remove products
- Add products to a shopping cart
- View the shopping cart and calculate its total
- Remove items or reduce item quantities in the cart
- Validate available stock during cart operations and checkout
- Confirm or cancel a purchase
- Validate positive and non-negative integer input

## Project Structure

```text
cpp-ecommerce-system/
├── include/             # Header files
├── src/                 # C++ implementation and main entry point
├── tests/               # Automated tests (planned)
├── CMakeLists.txt       # CMake build configuration
├── README.md
├── LICENSE
└── .gitignore
```

## Requirements

- A C++17-compatible compiler (GCC, Clang, or MSVC)
- CMake 3.16 or newer

## Build

From the project root, run:

```bash
cmake -S . -B build
cmake --build build
```

## Run

On Linux/macOS:

```bash
./build/ecommerce
```

On Windows, the executable is typically created at:

```text
build/Debug/ecommerce.exe
```

or, with a single-configuration generator such as MinGW Makefiles:

```text
build/ecommerce.exe
```

## Current OOP Concepts

- Classes and objects
- Encapsulation
- Constructors and member functions
- Getters and setters
- Composition (`ShoppingCart` contains `CartItem` objects)
- Separate header (`.h`) and implementation (`.cpp`) files

## Planned Improvements

- Persistent product storage
- Product update and category management
- User accounts and order history
- Improved separation of responsibilities
- Automated unit tests
- More robust input and error handling

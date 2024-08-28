# CppJSON
# Minimal JSON Serializer/Parser in C++20 for Game Design

## Minimal JSON Library in C++20

A high-performance, header-only JSON parser and serializer library designed for C++20. This library is optimized for real-time applications, such as game development, where speed and low memory overhead are crucial.

## Features

- **Header-Only**: Easy to integrate into any project without additional dependencies.
- **Modern C++20**: Leverages C++20 features like `std::string_view`, `std::variant`, and `constexpr` functions for maximum performance and flexibility.
- **Efficient Parsing and Serialization**: Designed to minimize memory allocations and provide fast JSON parsing and serialization.
- **Cross-Platform Compatibility**: Works on any platform with a modern C++20 compiler.

## Getting Started

### Prerequisites

- A C++20 compliant compiler (e.g., GCC 10+, Clang 10+, MSVC 19.26+).
- CMake 3.15+ (if using the provided CMakeLists.txt).

### Installation

1. **Clone the Repository**:

```sh
   git clone https://github.com/yourusername/json-library.git
   cd json-library
```

Include the Library:

Copy the include/json.hpp file into your project and include it in your source files:
```sh
#include "json.hpp"
```

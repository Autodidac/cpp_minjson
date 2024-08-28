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

```bash
   git clone https://github.com/yourusername/json-library.git
   cd json-library
```

Include the Library:

Copy the include/json.hpp file into your project and include it in your source files:
```cpp
#include "cppjson.hpp"
```
Usage
Here's a basic example demonstrating how to parse and serialize JSON:
```cpp
#include "cppjson.hpp"
#include <iostream>

int main() {
    // Example JSON string to parse
    std::string json_str = R"({
        "name": "John",
        "age": 30,
        "is_student": false,
        "courses": ["Math", "Science"]
    })";

    std::string_view json_view(json_str);

    // Parse JSON
    cppjson::JsonValue value;
    try {
        value = cppjson::parse_value(json_view);
    } catch (const json::JsonParseException& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
        return 1;
    }

    // Serialize JSON back to string
    std::string serialized = cppjson::serialize(value);
    std::cout << "Serialized JSON: " << serialized << std::endl;

    return 0;
}
```
Building the Example
If you want to build the example provided in src/main.cpp:

1. Generate the Build Files:
```bash
cmake -B build
```
2. Build the Project:
```bash
cmake --build build
```
3. Run the Example:
```bash
./build/main
```

### License
This project is licensed under the MIT License - see the LICENSE file for details.

### Contributing
Contributions are welcome! Please submit a pull request or open an issue to discuss improvements or bugs.

### Acknowledgments
This library was inspired by the need for a lightweight, efficient JSON parser for game development and other real-time applications.

### Contact

Your Name - your.email@example.com
GitHub: Autodidac

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    // Example JSON string to parse
    std::string json_str = R"({
        "name": "John",
        "age": 30,
        "is_student": false,
        "courses": ["Math", "Science"],
        "address": {
            "street": "123 Elm St",
            "city": "Somewhere"
        }
    })";

    std::string_view json_view(json_str);

    // Parse JSON
    json::JsonValue value;
    try {
        value = json::parse_value(json_view);
    } catch (const json::JsonParseException& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
        return 1;
    }

    // Serialize JSON back to string
    std::string serialized = json::serialize(value);
    std::cout << "Serialized JSON: " << serialized << std::endl;

    // Access JSON data
    if (auto obj = std::get_if<std::unordered_map<std::string, json::JsonValue>>(&value)) {
        if (auto name = std::get_if<std::string>(&(*obj)["name"])) {
            std::cout << "Name: " << *name << std::endl;
        }

        if (auto age = std::get_if<double>(&(*obj)["age"])) {
            std::cout << "Age: " << *age << std::endl;
        }

        if (auto courses = std::get_if<std::vector<json::JsonValue>>(&(*obj)["courses"])) {
            std::cout << "Courses: ";
            for (const auto& course : *courses) {
                if (auto course_name = std::get_if<std::string>(&course)) {
                    std::cout << *course_name << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Serialize JSON to file
    std::ofstream ofs("output.json");
    ofs << serialized;
    ofs.close();
    std::cout << "JSON saved to 'output.json'" << std::endl;

    return 0;
}

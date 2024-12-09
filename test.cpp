//
// Created by user on 09.12.2024.
//

#include "test.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class SimpleJSON {
public:
    std::string name;
    int age;
    std::vector<std::string> skills;

    // Функция для парсинга строки JSON
    bool parse(const std::string& jsonString) {
        size_t pos = 0;
        pos = jsonString.find("\"name\":", pos);
        if (pos == std::string::npos) return false;

        pos = jsonString.find("\"", pos + 7);  // Пропускаем "name":
        size_t endPos = jsonString.find("\"", pos + 1);
        name = jsonString.substr(pos + 1, endPos - pos - 1);

        pos = jsonString.find("\"age\":", endPos);
        if (pos == std::string::npos) return false;
        pos = jsonString.find(":", pos + 6);  // Пропускаем "age":
        age = std::stoi(jsonString.substr(pos + 1, jsonString.find(",", pos) - pos - 1));

        pos = jsonString.find("\"skills\":", endPos);
        if (pos == std::string::npos) return false;
        pos = jsonString.find("[", pos + 9);  // Пропускаем "skills":
        endPos = jsonString.find("]", pos);
        std::string skillsStr = jsonString.substr(pos + 1, endPos - pos - 1);

        std::stringstream ss(skillsStr);
        std::string skill;
        while (std::getline(ss, skill, ',')) {
            skill = skill.substr(skill.find_first_not_of(" \t\n\r\f\v\""), skill.find_last_not_of(" \t\n\r\f\v\"") + 1);
            skills.push_back(skill);
        }

        return true;
    }
};

int main() {
    std::ifstream inFile("data.json");

    if (!inFile) {
        std::cerr << "File not found!" << std::endl;
        return 1;
    }

    std::string jsonString((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    SimpleJSON data;
    if (data.parse(jsonString)) {
        std::cout << "Name: " << data.name << std::endl;
        std::cout << "Age: " << data.age << std::endl;
        std::cout << "Skills: ";
        for (const auto& skill : data.skills) {
            std::cout << skill << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Failed to parse JSON" << std::endl;
    }

    return 0;
}

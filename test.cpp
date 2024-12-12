#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Читаем JSON файл в строку
    std::ifstream inputFile("data.json");
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string jsonContent = buffer.str();
    inputFile.close();

    // Извлечение данных из JSON вручную
    std::string nameKey = "\"name\":";
    std::string ageKey = "\"age\":";
    std::string isStudentKey = "\"is_student\":";

    std::string jsonName;
    int jsonAge = 0;
    bool jsonIsStudent = false;

    size_t namePos = jsonContent.find(nameKey);
    if (namePos != std::string::npos) {
        size_t start = jsonContent.find('"', namePos + nameKey.length()) + 1;
        size_t end = jsonContent.find('"', start);
        jsonName = jsonContent.substr(start, end - start);
    }

    size_t agePos = jsonContent.find(ageKey);
    if (agePos != std::string::npos) {
        size_t start = jsonContent.find(':', agePos) + 1;
        size_t end = jsonContent.find(',', start);
        jsonAge = std::stoi(jsonContent.substr(start, end - start));
    }

    size_t isStudentPos = jsonContent.find(isStudentKey);
    if (isStudentPos != std::string::npos) {
        size_t start = jsonContent.find(':', isStudentPos) + 1;
        std::string value = jsonContent.substr(start);
        jsonIsStudent = (value.find("true") != std::string::npos);
    }

    // Ввод данных пользователем
    std::string userName;
    int userAge;
    bool userIsStudent;

    std::cout << "Введите имя: ";
    std::cin >> userName;

    std::cout << "Введите возраст: ";
    std::cin >> userAge;

    std::cout << "Вы студент (1 - да, 0 - нет): ";
    std::cin >> userIsStudent;

    // Проверка совпадения
    bool isNameMatch = (userName == jsonName);
    bool isAgeMatch = (userAge == jsonAge);
    bool isStudentMatch = (userIsStudent == jsonIsStudent);

    if (isNameMatch && isAgeMatch && isStudentMatch) {
        std::cout << "Все данные совпадают!" << std::endl;
    } else {
        std::cout << "Данные не совпадают:" << std::endl;
        if (!isNameMatch) std::cout << "Имя не совпадает." << std::endl;
        if (!isAgeMatch) std::cout << "Возраст не совпадает." << std::endl;
        if (!isStudentMatch) std::cout << "Статус студента не совпадает." << std::endl;
    }

    return 0;
}

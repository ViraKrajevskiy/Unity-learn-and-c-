#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

int main(){
    while (true) {
        std::ifstream inputFile('userdata.json');
        if (!inputFile.is_open()) {
            std::cerr << "Не удалось открыть файл!" << std::endl;
            return 1;
        }


        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string jsonContent = buffer.str();

        inputFile.close();

        std::string nameKey = "\"name\":";
        std::string ageKey = "\"age\":";
        std::string isStudentKey = "\"is_student\":";

        size_t namePos = jsonContent.find(nameKey);
        size_t agePos = jsonContent.find(ageKey);
        size_t isStudentPos = jsonContent.find(isStudentKey);

        if (namePos != std::string::npos) {
            size_t start = jsonContent.find('"', namePos + nameKey.length()) + 1;
            size_t end = jsonContent.find('"', start);
            std::string name = jsonContent.substr(start, end - start);
            std::cout << "Имя: " << name << std::endl;
        }

        if (agePos != std::string::npos) {
            size_t start = jsonContent.find(':', agePos) + 1;
            size_t end = jsonContent.find(',', start);
            int age = std::stoi(jsonContent.substr(start, end - start));
            std::cout << "Возраст: " << age << std::endl;
        }

        if (isStudentPos != std::string::npos) {
            size_t start = jsonContent.find(':', isStudentPos) + 1;
            std::string value = jsonContent.substr(start);
            bool isStudent = (value.find("true") != std::string::npos);
            std::cout << "Студент: " << (isStudent ? "Да" : "Нет") << std::endl;
        }
        return 0;
    }
}




/* таймер
#include <chrono>
#include <thread>
void timer(int seconds) {
    for (int i = seconds; i > 0; --i) {
        std::cout << "Time left: " << i << " seconds\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\nTime's up!\n";
}
int main() {
    int duration;
    std::cout << "Enter timer duration in seconds: ";
    std::cin >> duration;
    timer(duration);
    return 0;
}
*/


void enter_sms() {
    std::cout << "ears";
}

void password_change() {
    std::cout << "dee";
}

void money_apeend() {
    std::cout<<" he ";
}

void money_reverse() {
    std::cout<<"fuck";
}
void left_cash() {
        std::cout<<" hi ";
}

void menu() {

        setlocale(LC_ALL, "Russian");
        int a;

        std::cout << "1. Вывод денег \n2. Пополнение карты. \n3. Обмен валюты. \n4. Изменить пароль вашей карты. \n5. Подключение смс на карту. \n6. Выйти из программы. \nВВедите число:  ";
        std::cin >> a;
        if (a == 1) {
            return left_cash();
        }
        if (a == 2) {
            return money_apeend();
        }
        if (a == 3) {
            return money_reverse();
        }
        if (a == 4) {
            return password_change();
        }
        if (a == 5) {
            return enter_sms();
        }
        if (a == 6) {
            exit(0);
        }
        else {
            std::cout << "Ввели неправильное число";
            return menu();
        }

    }

int user_t() {
    setlocale(LC_ALL, "Russian");

}



int mai() {
    setlocale(LC_ALL, "Russian");

    std::string name;
    std::cout << "Введите свое имя: ";
    std::getline(std::cin, name);

    if (!name.empty()) {
        menu();
    } else {
        std::cout << "Вы не ввели имя.\n";
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <bits/ranges_base.h>
#include <fstream>

/*
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



int main() {

    std::cout << "Введите свое имя:";
    std::cin >>
}

void parol_Change() {
    std::cout << "dee";
}

void money_reverse() {
    std::cout<<" he ";
}

void left_cash() {
        std::cout<<" hi ";
}

void menu() {
    while (true) {
        setlocale(LC_ALL, "RU");
        int a;


        std::cout << "1. Вывод денег \n2. Пополнение карты.\n3. Обмен валюты. \n4. Изменить пароль вашей карты. \n5. Подключение смс на карту. \n6. Выйти из программы.";
        std::cin >> a;
        if (a == 1) {
            return left_cash();
        }
        if (a == 2) {
            return money_reverse();
        }
        if (a == 3) {
            return ;
        }
        if (a == 4) {
            return ;
        }
        if (a == 5) {
            return ;
        }
        if (a == 6) {
            break;
        }
    }
}




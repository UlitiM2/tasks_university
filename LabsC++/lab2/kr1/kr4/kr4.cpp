#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main() {
    system("chcp 1251");
    int score = 0;
    int shots = 0;
    const int targetScore = 50;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Случайный центр мишени
    double targetX = (double)rand() / RAND_MAX * 2 - 1;
    double targetY = (double)rand() / RAND_MAX * 2 - 1;

    while (score < targetScore) {
        double x, y;
        std::cout << "Введите координаты x и y: ";
        std::cin >> x >> y;

        // Случайная помеха при выстреле
        double interferenceX = (double)rand() / RAND_MAX * 0.2 - 0.1;
        double interferenceY = (double)rand() / RAND_MAX * 0.2 - 0.1;
        x += interferenceX;
        y += interferenceY;

        double distance = std::sqrt(std::pow(x - targetX, 2) + std::pow(y - targetY, 2));

        if (distance <= 1) {
            score += 10;
        }
        else if (distance <= 2) {
            score += 5;
        }

        shots++;

        std::cout << "Текущий счет: " << score << std::endl;
    }

    std::cout << "Выстрелов сделано: " << shots << std::endl;

    if (score >= targetScore) {
        if (shots <= 5) {
            std::cout << "Уровень стрелка: Снайпер" << std::endl;
        }
        else if (shots <= 10) {
            std::cout << "Уровень стрелка: Просто стрелок" << std::endl;
        }
        else {
            std::cout << "Уровень стрелка: Новичок" << std::endl;
        }
    }

    return 0;
}

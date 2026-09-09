//
// Created by Артемий on 09/09/2026.
//

#include "I.h"

double I::fastPow(double number, long long power) {
    if (power == 0) {
        return 1.0;
    }

    if (power % 2 == 0) {
        double half = fastPow(number, power / 2);
        return half * half;
    }

    return number * fastPow(number, power - 1);
}

void I::solve() {
    double number;
    int power;

    std::cin >> number >> power;

    if (power < 0) {
        std::cout << 1.0 / fastPow(number, -power) << std::endl;
    } else {
        std::cout << fastPow(number, power) << std::endl;
    }
}

//
// Created by Артемий on 09/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_D_H
#define YANDEX_ALGORITHM_TRAINEES_D_H

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <functional>

class D {
public:
    static std::unordered_map<std::string, std::function<int(int, int)>> operandToFunc;

    static int sum(int a, int b);
    static int subtract(int a, int b);
    static int multiply(int a, int b);

    static bool isOperator(std::string s);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_D_H

//
// Created by Артемий on 08/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_A_H
#define YANDEX_ALGORITHM_TRAINEES_A_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <functional>
#include <regex>

class E {
public:
    static std::unordered_map<std::string, std::function<int(int, int)>> operatorToFunc;
    static std::unordered_map<char, int> operatorToPriority;

    static int sum(int a, int b);
    static int subtract(int a, int b);
    static int multiply(int a, int b);

    static int postfixPerform(const std::vector<std::string>& tokens);

    static bool isOperator(std::string s);
    static bool isParenthes(std::string s);
    static bool isOperand(std::string s);
    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_A_H

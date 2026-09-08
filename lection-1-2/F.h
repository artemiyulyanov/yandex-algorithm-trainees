//
// Created by Артемий on 09/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_F_H
#define YANDEX_ALGORITHM_TRAINEES_F_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <functional>
#include <regex>

class F {
public:
    static std::unordered_map<char, std::function<bool(bool, bool)>> operatorToFunc;
    static std::unordered_map<char, int> operatorToPriority;

    static bool binaryAnd(bool a, bool b);
    static bool binaryOr(bool a, bool b);
    static bool binaryXor(bool a, bool b);

    static bool isOperator(char t);
    static bool isParenthesis(char t);

    static int postfixPerform(const std::vector<std::string>& tokens);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_F_H

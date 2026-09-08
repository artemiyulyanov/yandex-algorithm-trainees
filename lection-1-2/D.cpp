//
// Created by Артемий on 09/09/2026.
//

#include "D.h"

int D::sum(int a, int b) {
    return a + b;
}

int D::subtract(int a, int b) {
    return a - b;
}

int D::multiply(int a, int b) {
    return a * b;
}

std::unordered_map<std::string, std::function<int(int, int)>> D::operandToFunc = {
    {"+", sum},
    {"-", subtract},
    {"*", multiply}
};

bool D::isOperator(std::string s) {
    return s == "-" || s == "+" || s == "*";
}

void D::solve() {
    std::string s;
    std::getline(std::cin, s);

    std::stringstream ss(s);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    std::vector<std::string> stack;

    for (auto& el : tokens) {
        if (!isOperator(el)) stack.push_back(el);
        else {
            std::string num2 = stack.back();
            stack.pop_back();

            std::string num1 = stack.back();
            stack.pop_back();

            int res = operandToFunc.find(el)->second(std::stoi(num1), std::stoi(num2));

            stack.push_back(std::to_string(res));
        }
    }

    std::cout << stack.back() << std::endl;
}
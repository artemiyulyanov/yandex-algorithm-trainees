//
// Created by Артемий on 09/09/2026.
//

#include "F.h"

bool F::binaryAnd(bool a, bool b) {
    return a & b;
}

bool F::binaryOr(bool a, bool b) {
    return a | b;
}

bool F::binaryXor(bool a, bool b) {
    return a ^ b;
}

std::unordered_map<char, std::function<bool(bool, bool)>> F::operatorToFunc = {
    {'&', binaryAnd},
    {'|', binaryOr},
    {'^', binaryXor}
};

std::unordered_map<char, int> F::operatorToPriority = {
    {'!', 3},
    {'&', 2},
    {'|', 1},
    {'^', 1}
};

bool F::isOperator(char t) {
    return t == '&' || t == '^' || t == '|' || t == '!';
}

bool F::isParenthesis(char t) {
    return t == '(' || t == ')';
}

int F::postfixPerform(const std::vector<std::string> &tokens) {
    std::stack<std::string> stack;

    for (auto& el : tokens) {
        if (!isOperator(el.front())) stack.push(el);
        else {
            if (el != "!") {
                std::string num2 = stack.top();
                stack.pop();

                std::string num1 = stack.top();
                stack.pop();

                int res = operatorToFunc.find(el.front())->second(std::stoi(num1), std::stoi(num2));

                stack.push(std::to_string(res));

                continue;
            }

            std::string num1 = stack.top();
            stack.pop();

            int res = 1 - std::stoi(num1);

            stack.push(std::to_string(res));
        }
    }

    return std::stoi(stack.top());
}

void F::solve() {
    std::string s;
    std::getline(std::cin, s);

    for (const std::string& obj : {"|", "^", "&", "(", ")", "0", "1", "!"}) {
        std::string pattern = (obj == "0" || obj == "1") ? obj : "\\" + obj;
        s = std::regex_replace(s, std::regex(pattern), " " + obj + " ");
    }

    while (s.find("  ") != std::string::npos) {
        s = std::regex_replace(s, std::regex(" {2}"), " ");
    }

    std::vector<std::string> tokens;
    std::istringstream iss(s);
    std::string token;

    while (iss >> token) tokens.push_back(token);

    std::stack<std::string> st;
    std::vector<std::string> postfix;

    for (auto& token : tokens) {
        if (!isOperator(token.front()) && !isParenthesis(token.front())) {
            postfix.push_back(token);
            continue;
        }

        if (token == "(") {
            st.push(token);
        } else if (token == ")") {
            while (!st.empty() && st.top() != "(") {
                std::string top = st.top();
                postfix.push_back(top);

                st.pop();
            }

            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && operatorToPriority[st.top()[0]] >= operatorToPriority[token[0]]) {
                std::string top = st.top();
                postfix.push_back(top);

                st.pop();
            }

            st.push(token);
        }
    }

    while (!st.empty()) {
        std::string top = st.top();
        postfix.push_back(top);

        st.pop();
    }

    int res = postfixPerform(postfix);
    std::cout << res << std::endl;
}

//
// Created by Артемий on 08/09/2026.
//

// ВНИМАНИЕ, ЭТО ГОВНОКОД EDITION, КОД БУДЕТ ПЕРЕПИСАН

#include "E.h"

int E::sum(int a, int b) {
    return a + b;
}

int E::subtract(int a, int b) {
    return a - b;
}

int E::multiply(int a, int b) {
    return a * b;
}

std::unordered_map<std::string, std::function<int(int, int)>> E::operatorToFunc = {
    {"+", sum},
    {"-", subtract},
    {"*", multiply}
};

std::unordered_map<char, int> E::operatorToPriority = {
    {'+', 1},
    {'-', 1},
    {'*', 2}
};

bool E::isOperator(std::string s) {
    return s == "+" || s == "-" || s == "*" || s == "(" || s == ")";
}

bool E::isOperand(std::string s) {
    const std::regex numberRegex(R"(^-?\d+$)");
    return std::regex_match(s, numberRegex);
}

bool E::isParenthes(std::string s) {
    return s == "(" || s == ")";
}

int E::postfixPerform(const std::vector<std::string>& tokens) {
    std::stack<std::string> stack;

    for (auto& el : tokens) {
        if (!isOperator(el)) stack.push(el);
        else {
            std::string num2 = stack.top();
            stack.pop();

            std::string num1 = stack.top();
            stack.pop();

            int res = operatorToFunc.find(el)->second(std::stoi(num1), std::stoi(num2));

            stack.push(std::to_string(res));
        }
    }

    return std::stoi(stack.top());
}

void E::solve() {
    std::string s;
    std::getline(std::cin, s);

    if (s.back() != ')' && isOperator(std::string(1, s.back()))) {
        std::cout << "WRONG" << std::endl;
        return;
    }

    if (s.front() != '(' && isOperator(std::string(1, s.front())) && s.front() != '-') {
        std::cout << "WRONG" << std::endl;
        return;
    }

    std::string preprocessed;
    bool expectOperand = true;

    for (char ch : s) {
        if (ch == ' ') {
            preprocessed += ch;
            continue;
        }

        if (ch == '-' && expectOperand) {
            preprocessed += "0-";
            expectOperand = true;
            continue;
        }

        preprocessed += ch;

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*') {
            expectOperand = true;
        } else if (ch == ')') {
            expectOperand = false;
        } else {
            expectOperand = false;
        }
    }

    s = preprocessed;

    for (const std::string& op : {"-", "+", "*", "(", ")"}) {
        std::string pattern = (op == "-") ? op : ("\\" + op);
        s = std::regex_replace(s, std::regex(pattern), " " + op + " ");
    }

    while (s.find("  ") != std::string::npos) {
        s = std::regex_replace(s, std::regex(" {2}"), " ");
    }

    std::vector<std::string> tokens;
    std::istringstream iss(s);
    std::string token;

    std::string last;

    while (iss >> token) {
        if (!isOperator(token) && !isOperand(token)) {
            std::cout << "WRONG" << std::endl;
            return;
        }

        if ((isOperator(last) || last.empty()) && isOperator(token)) {
            if ((last == "(" && !isParenthes(token)) || (token == ")" && !isParenthes(last))) {
                std::cout << "WRONG" << std::endl;
                return;
            }
        }
        
        if (!isOperator(last) && !isOperator(token) && !last.empty()) {
            std::cout << "WRONG" << std::endl;
            return;
        }

        tokens.push_back(token);
        last = token;
    }

    std::stack<std::string> st;
    std::vector<std::string> postfix;

    std::stack<std::string> stParenthesis;

    for (auto& token : tokens) {
        if (!isOperator(token)) {
            postfix.push_back(token);
            continue;
        }

        if (token == "(") stParenthesis.push(token);
        if (token == ")") {
            if (!stParenthesis.empty()) stParenthesis.pop();
            else {
                std::cout << "WRONG" << std::endl;
                return;
            }
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

    if (!stParenthesis.empty()) {
        std::cout << "WRONG" << std::endl;
        return;
    }

    while (!st.empty()) {
        std::string top = st.top();
        postfix.push_back(top);

        st.pop();
    }

    int res = postfixPerform(postfix);
    std::cout << res << std::endl;
}

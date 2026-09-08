//
// Created by Артемий on 07/09/2026.
//

#include "E.h"

#include <iostream>
#include <map>

std::map<char, char> E::dct = {
    {'}', '{'},
    {']', '['},
    {')', '('}
};

void E::solve() {
    std::stack<char> st;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
            continue;
        }

        if (st.empty()) {
            std::cout << "no" << std::endl;
            return;
        }

        char cur = st.top();

        if (cur == dct[s[i]]) {
            st.pop();
        } else {
            std::cout << "no" << std::endl;
            return;
        }
    }

    if (st.empty()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}
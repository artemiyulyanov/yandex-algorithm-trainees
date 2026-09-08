//
// Created by Артемий on 07/09/2026.
//

#include "B.h"

std::map<char, char> B::closedToOpened = {
    {']', '['},
    {')', '('}
};

bool B::isOpening(char t) {
    return t == '(' || t == '[';
}

bool B::isClosing(char t) {
    return t == ')' || t == ']';
}

char B::firstCompliable(std::stack<char>& st, char last, int& left, std::string w) {
    for (auto& w_char : w) {
        if (isClosing(w_char)) {
            if (isOpening(last) && closedToOpened[w_char] == last) {
                st.pop();
                return w_char;
            }

            if (isClosing(last) && !st.empty() && closedToOpened[w_char] == st.top()) {
                st.pop();
                return w_char;
            }
        }

        if (isOpening(w_char) && left > 0) {
            left--;
            st.push(w_char);
            return w_char;
        }
    }

    return '-';
}

void B::solve() {
    int n;
    std::cin >> n;

    std::string w;
    std::cin >> w;

    std::string s;
    std::cin >> s;

    int used = 0;
    for (auto& ch : s) if (isOpening(ch)) used++;

    int left = n / 2 - used;
    std::string ans;

    std::stack<char> st;
    char last = '-';

    for (auto& ch : s) {
        if (isOpening(ch)) st.push(ch);
        else {
            char t = st.top();

            if (t == closedToOpened[ch]) {
                st.pop();
            }
        }

        ans += ch;
        last = ch;
    }

    if (ans.length() == n) {
        std::cout << ans << std::endl;
        return;
    }

    while (ans.length() < n) {
        char newChar = firstCompliable(st, last, left, w);

        ans += newChar;
        last = newChar;
    }

    std::cout << ans << std::endl;
}
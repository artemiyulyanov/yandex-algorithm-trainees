//
// Created by Артемий on 07/09/2026.
//

#include "C.h"

bool C::isXmlCorrect(std::string s) {
    std::stack<std::string> st;

    std::string tag;
    std::string buffer;

    for (auto& t : s) {
        if (t == '<') {
            if (!buffer.empty()) return false;
            buffer += t;

            continue;
        }

        if (t == '/') {
            if (buffer != "<") return false;
            buffer += t;

            continue;
        }

        if (t == '>') {
            buffer += t;

            if (buffer.starts_with("</")) {
                if (st.empty()) return false;

                std::string lastOpened = st.top();

                if (lastOpened != tag) {
                    return false;
                }

                st.pop();
            } else if (buffer.starts_with("<")) {
                st.push(tag);
            }

            buffer = "";
            tag = "";

            continue;
        }

        if (buffer.starts_with("<")) {
            tag += t;
            buffer += t;
        } else {
            return false;
        }
    }

    return st.empty() && buffer.empty() && tag.empty();
}

void C::solve() {
    std::string s;
    std::cin >> s;

    if (!s.empty()) {
        char copy = s[0];

        s[0] = '<';

        if (isXmlCorrect(s)) {
            std::cout << s << std::endl;
            return;
        }

        s[0] = copy;
    }

    for (int i = 1; i < s.length(); i++) {
        char copy = s[i];

        if (s[i-1] != '>') {
            for (char x = 'a'; x <= 'z'; x++) {
                s[i] = x;

                if (isXmlCorrect(s)) {
                    std::cout << s << std::endl;
                    return;
                }

                s[i] = copy;
            }
        }

        if (s[i-1] == '<') {
            s[i] = '/';

            if (isXmlCorrect(s)) {
                std::cout << s << std::endl;
                return;
            }

            s[i] = copy;
        }

        if (s[i-1] == '/' || (s[i-1] >= 'a' && s[i-1] <= 'z')) {
            s[i] = '>';

            if (isXmlCorrect(s)) {
                std::cout << s << std::endl;
                return;
            }

            s[i] = copy;
        }

        if (s[i-1] == '>') {
            s[i] = '<';

            if (isXmlCorrect(s)) {
                std::cout << s << std::endl;
                return;
            }

            s[i] = copy;
        }
    }
}

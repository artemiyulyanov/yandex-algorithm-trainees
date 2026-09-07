//
// Created by Артемий on 07/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_SECONDTASK_H
#define YANDEX_ALGORITHM_TRAINEES_SECONDTASK_H

#include <iostream>
#include <vector>
#include <map>

class B {
public:
    static std::map<char, char> closedToOpened;

    static bool isOpening(char t);
    static bool isClosing(char t);

    static char firstCompliable(std::stack<char>& st, char last, int& left, std::string w);
    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_SECONDTASK_H

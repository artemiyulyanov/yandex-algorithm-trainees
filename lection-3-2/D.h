//
// Created by Артемий on 16/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_D_H
#define YANDEX_ALGORITHM_TRAINEES_D_H

#include <iostream>
#include <vector>
#include <random>
#include <climits>

struct Ship {
    int r, c;

    Ship() {}

    Ship(int r, int c) : r(r), c(c) {}
};

class D {
public:
    static int random(int start, int end);

    static void quick_sort_median_c(std::vector<Ship>& arr, int start, int end, int mid);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_D_H

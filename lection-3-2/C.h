//
// Created by Артемий on 16/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_C_H
#define YANDEX_ALGORITHM_TRAINEES_C_H

#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <climits>
#include <queue>
#include <set>

struct City {
    int x, y;

    City() {}

    City(int x, int y) : x(x), y(y) {}
};

class C {
public:
    static int random(int start, int end);

    static void quick_sort_median_x(std::vector<City>& arr, int start, int end, int mid);
    static void quick_sort_median_y(std::vector<City>& arr, int start, int end, int mid);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_C_H

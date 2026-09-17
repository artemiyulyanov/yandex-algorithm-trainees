//
// Created by Артемий on 18/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_H_H
#define YANDEX_ALGORITHM_TRAINEES_H_H

#include <iostream>
#include <vector>

class H {
public:
    static void merge(std::vector<int>& arr, int start, int mid, int end, long long& permutations);
    static void merge_sort(std::vector<int>& arr, int start, int end, long long& permutations);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_H_H

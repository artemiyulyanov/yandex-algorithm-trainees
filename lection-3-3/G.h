//
// Created by Артемий on 17/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_G_H
#define YANDEX_ALGORITHM_TRAINEES_G_H

#include <iostream>
#include <vector>

class G {
public:
    static void merge(std::vector<int>& arr, int start, int mid, int end);
    static void merge_sort(std::vector<int>& arr, int start, int end);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_G_H

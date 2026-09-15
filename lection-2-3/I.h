//
// Created by Артемий on 15/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_I_H
#define YANDEX_ALGORITHM_TRAINEES_I_H

#include <iostream>
#include <vector>
#include <iomanip>

struct Heap {
    std::vector<int> arr;

    Heap() : arr(0) {}

    void insert(int k) {
        arr.push_back(k);

        int child = arr.size() - 1;
        int parent = (child - 1) / 2;

        while (child > 0 && arr[parent] > arr[child]) {
            std::swap(arr[child], arr[parent]);

            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void pop_front() {
        if (arr.empty()) return;

        arr[0] = arr.back();
        arr.pop_back();

        int parent = 0;

        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int smallest = parent;

            if (left < (int)arr.size() && arr[left] < arr[smallest]) smallest = left;
            if (right < (int)arr.size() && arr[right] < arr[smallest]) smallest = right;

            if (smallest == parent) break;

            std::swap(arr[parent], arr[smallest]);
            parent = smallest;
        }
    }

    int extract() {
        int root = arr[0];

        pop_front();

        return root;
    }
};

class I {
public:
    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_I_H

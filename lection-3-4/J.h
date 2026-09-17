//
// Created by Артемий on 18/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_J_H
#define YANDEX_ALGORITHM_TRAINEES_J_H

#include <iostream>
#include <vector>

struct Heap {
    std::vector<int> arr;
    int limit, swaps;

    Heap() : arr(0), limit(0), swaps(0) {}

    Heap(const std::vector<int>& a) : arr(a), limit((int)a.size()), swaps(0) {
        for (int i = limit / 2 - 1; i >= 0; i--) sift_down(i);
    }

    void sift_down(int parent) {
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;

            if (left < limit && arr[left] > arr[largest]) largest = left;
            if (right < limit && arr[right] > arr[largest]) largest = right;

            if (largest == parent) break;

            std::swap(arr[parent], arr[largest]);
            swaps++;

            parent = largest;
        }
    }

    void insert(int k) {
        arr.push_back(k);
        limit++;

        int child = limit - 1;
        int parent = (child - 1) / 2;

        while (child > 0 && arr[parent] < arr[child]) {
            std::swap(arr[parent], arr[child]);
            child = parent;
            parent = (child - 1) / 2;
        }
    }


    void pop_front() {
        if (limit <= 0) return;

        std::swap(arr[0], arr[limit - 1]);
        limit--;

        sift_down(0);
    }

    int extract() {
        int num = arr[0];
        pop_front();
        return num;
    }
};

class J {
public:
    static void pyramid_sort(Heap& heap);

    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_J_H

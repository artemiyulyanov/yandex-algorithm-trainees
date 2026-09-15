#ifndef YANDEX_ALGORITHM_TRAINEES_C_H
#define YANDEX_ALGORITHM_TRAINEES_C_H

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <algorithm>

struct Rover {
    int direction;
    int arrivalTime;
    int id;
};

class C {
private:
    static int mainA;
    static int mainB;

    static std::array<std::deque<Rover>, 5> roads;
    static std::vector<int> result;

    static bool isCrossRoadEquivalent(int a, int b);

    static int getRightIndexFor(int direction);

    static bool isMain(int direction);
    static bool mustGiveWay(const Rover& x, const Rover& y);
public:
    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_C_H

#include "C.h"

int C::random(int start, int end) {
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(start, end);

    int randomIndex = dist(gen);

    return randomIndex;
}

void C::quick_sort_median_x(std::vector<City> &arr, int start, int end, int mid) {
    if (start >= end || start >= arr.size()) return;

    int x = random(start, end);
    int pivot = arr[x].x;

    int eq = start, gr = start, none = start;

    while (none <= end) {
        if (arr[none].x == pivot) {
            std::swap(arr[gr], arr[none]);
            gr++;
        } else if (arr[none].x < pivot) {
            std::swap(arr[gr], arr[none]);
            std::swap(arr[eq], arr[gr]);

            eq++;
            gr++;
        }

        none++;
    }

    if (mid < eq) {
        quick_sort_median_x(arr, start, eq - 1, mid);
    } else if (mid >= gr) {
        quick_sort_median_x(arr, gr, end, mid);
    }
}

void C::quick_sort_median_y(std::vector<City> &arr, int start, int end, int mid) {
    if (start >= end || start >= arr.size()) return;

    int x = random(start, end);
    int pivot = arr[x].y;

    int eq = start, gr = start, none = start;

    while (none <= end) {
        if (arr[none].y == pivot) {
            std::swap(arr[gr], arr[none]);
            gr++;
        } else if (arr[none].y < pivot) {
            std::swap(arr[gr], arr[none]);
            std::swap(arr[eq], arr[gr]);

            eq++;
            gr++;
        }

        none++;
    }

    if (mid < eq) {
        quick_sort_median_y(arr, start, eq - 1, mid);
    } else if (mid >= gr) {
        quick_sort_median_y(arr, gr, end, mid);
    }
}

void C::solve() {
    int n;
    std::cin >> n;

    std::vector<City> cities(n);

    std::unordered_map<int, std::vector<int>> occupied;

    for (int i = 0; i < n; i++) {
        std::cin >> cities[i].x >> cities[i].y;
        occupied[cities[i].x].push_back(cities[i].y);
    }

    int mid = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    mid--;

    quick_sort_median_x(cities, 0, n - 1, mid);

    int mid_x = cities[mid].x;

    if (n % 2 == 0) {
        int upper_x = INT_MAX;
        for (int i = mid + 1; i < n; i++)
            upper_x = std::min(upper_x, cities[i].x);
        mid_x = (mid_x + upper_x) / 2;
    }

    quick_sort_median_y(cities, 0, n - 1, mid);

    int mid_y = cities[mid].y;

    if (n % 2 == 0) {
        int upper_y = INT_MAX;
        for (int i = mid + 1; i < n; i++)
            upper_y = std::min(upper_y, cities[i].y);
        mid_y = (mid_y + upper_y) / 2;
    }

    if (!occupied.contains(mid_x) || std::find(occupied[mid_x].begin(), occupied[mid_x].end(), mid_y) == occupied[mid_x].end()) {
        std::cout << mid_x << ' ' << mid_y << std::endl;
        return;
    }

    const int LO = -2001, HI = 2001;
    const int RANGE = HI - LO + 1;

    auto computeCost = [&](bool useX) {
        std::vector<long long> cost(RANGE, 0);
        for (int idx = 0; idx < RANGE; idx++) {
            int v = LO + idx;
            long long s = 0;
            for (auto &c : cities) {
                int coord = useX ? c.x : c.y;
                s += llabs((long long)coord - v);
            }
            cost[idx] = s;
        }
        return cost;
    };

    std::vector<long long> fx = computeCost(true);
    std::vector<long long> fy = computeCost(false);

    std::vector<int> X(RANGE), Y(RANGE);
    for (int i = 0; i < RANGE; i++) { X[i] = i; Y[i] = i; }

    std::sort(X.begin(), X.end(), [&](int a, int b) { return fx[a] < fx[b]; });
    std::sort(Y.begin(), Y.end(), [&](int a, int b) { return fy[a] < fy[b]; });

    using State = std::tuple<long long, int, int>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    std::set<std::pair<int,int>> visited;

    pq.push({fx[X[0]] + fy[Y[0]], 0, 0});
    visited.insert({0, 0});

    int min_r = mid_x, min_c = mid_y;

    while (!pq.empty()) {
        auto [sum, i, j] = pq.top();
        pq.pop();

        int cx = LO + X[i];
        int cy = LO + Y[j];

        auto it = occupied.find(cx);
        bool blocked = (it != occupied.end() &&
                         std::find(it->second.begin(), it->second.end(), cy) != it->second.end());

        if (!blocked) {
            min_r = cx;
            min_c = cy;
            break;
        }

        if (i + 1 < RANGE && !visited.count({i + 1, j})) {
            visited.insert({i + 1, j});
            pq.push({fx[X[i + 1]] + fy[Y[j]], i + 1, j});
        }
        if (j + 1 < RANGE && !visited.count({i, j + 1})) {
            visited.insert({i, j + 1});
            pq.push({fx[X[i]] + fy[Y[j + 1]], i, j + 1});
        }
    }

    std::cout << min_r << ' ' << min_c << std::endl;
}

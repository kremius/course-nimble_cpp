#include "util.hpp"

//////////////////////////// TASK 4 ////////////////////////////

int naive_100_to_1000(std::vector<int>& d) {
    std::sort(d.begin(), d.end());
    auto it1 = std::lower_bound(d.begin(), d.end(), 100);
    auto it2 = std::lower_bound(d.begin(), d.end(), 1000);
    return it2 - it1;
}

int optimized_100_to_1000(std::vector<int>& d) {
    return std::count_if(d.begin(), d.end(), [](int v) { return (v > 100) && (v <= 1000); });
}


//////////////////////////// DETAIL ////////////////////////////
BENCH(algorithms, naive_100_to_1000, naive_100_to_1000, naive_100_to_1000)->Range(8, 8 << 10)->Complexity();
BENCH(algorithms, optim_100_to_1000, optimized_100_to_1000, naive_100_to_1000)->Range(8, 8 << 10)->Complexity();


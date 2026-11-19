#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

int knapsack(const std::vector<int>& weights, const std::vector<int>& values, int capacity) {
    std::vector<int> dp(capacity + 1, 0);
    for (size_t i = 0; i < weights.size(); ++i) {
        int w = weights[i];
        int v = values[i];
        for (int c = capacity; c >= w; --c) {
            dp[c] = std::max(dp[c], dp[c - w] + v);
        }
    }
    return dp[capacity];
}

int main() {
    const int N = 2000;
    const int CAPACITY = 20000;
    
    std::vector<int> weights(N);
    std::vector<int> values(N);
    
    std::mt19937 gen(42); // Фиксированный seed
    std::uniform_int_distribution<> dis(1, 100);
    
    for (int i = 0; i < N; ++i) {
        weights[i] = dis(gen);
        values[i] = dis(gen);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    int max_value = knapsack(weights, values, CAPACITY);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> elapsed = end - start;
    
    std::cout << "Linux C++ Result: " << max_value << "\n";
    std::cout << "Linux C++ Time: " << elapsed.count() << " ms\n";
    
    return 0;
}
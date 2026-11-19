#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <windows.h>

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
    
    std::mt19937 gen(42); // Тот же seed
    std::uniform_int_distribution<> dis(1, 100);
    
    for (int i = 0; i < N; ++i) {
        weights[i] = dis(gen);
        values[i] = dis(gen);
    }
    
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    
    QueryPerformanceCounter(&start);
    int max_value = knapsack(weights, values, CAPACITY);
    QueryPerformanceCounter(&end);
    
    double elapsed_ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    
    std::cout << "Windows C++ Result: " << max_value << "\n";
    std::cout << "Windows C++ Time: " << elapsed_ms << " ms\n";
    
    return 0;
}
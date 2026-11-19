import time
import random

def knapsack(weights, values, capacity):
    n = len(weights)
    dp = [0] * (capacity + 1)
    
    for i in range(n):
        w = weights[i]
        v = values[i]
        for c in range(capacity, w - 1, -1):
            dp[c] = max(dp[c], dp[c - w] + v)
            
    return dp[capacity]

if __name__ == "__main__":
    random.seed(42)
    N = 2000
    CAPACITY = 20000
    
    weights = [random.randint(1, 100) for _ in range(N)]
    values = [random.randint(1, 100) for _ in range(N)]
    
    start_time = time.perf_counter()
    max_value = knapsack(weights, values, CAPACITY)
    end_time = time.perf_counter()
    
    elapsed_ms = (end_time - start_time) * 1000
    print(f"Python Result: {max_value}")
    print(f"Python Time: {elapsed_ms:.2f} ms")
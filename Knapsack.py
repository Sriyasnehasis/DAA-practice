def knapsack(values, weights, W):
    n = len(values)
    # dp[i][w] = max value using first i items with capacity w
    dp = [[0] * (W + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if weights[i-1] <= w:
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]])
            else:
                dp[i][w] = dp[i-1][w]

    # reconstruct chosen items
    res = dp[n][W]
    w = W
    chosen = []
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i-1][w]:
            chosen.append(i-1)  # item index
            w -= weights[i-1]

    chosen.reverse()
    return res, chosen

# Example (same as your C example)
values = [60, 100, 120]       # profits
weights = [10, 20, 30]        # weights
W = 50                        # knapsack capacity

max_profit, items = knapsack(values, weights, W)
print("Maximum Profit:", max_profit)
print("Chosen items (index, weight, value):")
for i in items:
    print(i, weights[i], values[i])

    
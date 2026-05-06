n = int(input("Enter number of items: "))

wt = list(map(int, input("Enter weights: ").split()))
val = list(map(int, input("Enter values: ").split()))

W = int(input("Enter capacity: "))

# DP table
K = [[0] * (W + 1) for _ in range(n + 1)]

# Fill table
for i in range(1, n + 1):
    for w in range(1, W + 1):
        if wt[i - 1] <= w:
            K[i][w] = max(K[i - 1][w],
                          val[i - 1] + K[i - 1][w - wt[i - 1]])
        else:
            K[i][w] = K[i - 1][w]

print("\nMaximum Profit:", K[n][W])

# Find selected items
w = W
selected = []
for i in range(n, 0, -1):
    if K[i][w] != K[i - 1][w]:
        selected.append(i - 1)
        w -= wt[i - 1]

print("Selected items (0-based index):", selected[::-1])
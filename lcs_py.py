X = input("Enter first string: ")
Y = input("Enter second string: ")

m, n = len(X), len(Y)

# DP table
L = [[0] * (n + 1) for _ in range(m + 1)]

# Fill table
for i in range(1, m + 1):
    for j in range(1, n + 1):
        if X[i - 1] == Y[j - 1]:
            L[i][j] = L[i - 1][j - 1] + 1
        else:
            L[i][j] = max(L[i - 1][j], L[i][j - 1])

# Reconstruct LCS
i, j = m, n
lcs = ""

while i > 0 and j > 0:
    if X[i - 1] == Y[j - 1]:
        lcs = X[i - 1] + lcs
        i -= 1
        j -= 1
    elif L[i - 1][j] > L[i][j - 1]:
        i -= 1
    else:
        j -= 1

print("\nLength of LCS:", L[m][n])
print("LCS:", lcs)
n = int(input("Enter number of files: "))
files = list(map(int, input("Enter file sizes: ").split()))

# Step 1: Sort (Greedy)
files.sort()

total_time = 0
cumulative = 0

# Step 2: Calculate MRT
for f in files:
    cumulative += f
    total_time += cumulative

mrt = total_time / n

print("\nOptimal Order:", files)
print("Mean Retrieval Time:", mrt)
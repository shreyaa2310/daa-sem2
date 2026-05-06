import heapq

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def print_codes(root, code=""):
    if root is None:
        return
    
    if root.char != '$':
        print(f"{root.char}: {code}")
    
    print_codes(root.left, code + "0")
    print_codes(root.right, code + "1")

# Input
n = int(input("Enter number of characters: "))
chars = input("Enter characters: ").split()
freq = list(map(int, input("Enter frequencies: ").split()))

heap = []

# Build heap
for i in range(n):
    heapq.heappush(heap, Node(chars[i], freq[i]))

# Build tree
while len(heap) > 1:
    left = heapq.heappop(heap)
    right = heapq.heappop(heap)

    merged = Node('$', left.freq + right.freq)
    merged.left = left
    merged.right = right

    heapq.heappush(heap, merged)

root = heap[0]

print("\nHuffman Codes:")
print_codes(root)
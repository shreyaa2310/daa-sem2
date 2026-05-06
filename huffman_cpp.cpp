#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for min-heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Print Huffman codes
void printCodes(Node* root, string code) {
    if (!root) return;

    if (root->ch != '$') {
        cout << root->ch << ": " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters:\n";
    for(int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter frequencies:\n";
    for(int i = 0; i < n; i++)
        cin >> freq[i];

    priority_queue<Node*, vector<Node*>, compare> pq;

    // Insert into heap
    for(int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Build Huffman Tree
    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
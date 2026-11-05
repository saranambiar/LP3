#include <bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node *l, Node *r){
        ch = c;
        freq = f;
        left = l;
        right = r;
    }
};

struct Compare{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};

void printCodes(Node *node, string code){
    if (node->left == NULL && node->right == NULL){
        cout << node->ch << " -> " << code << endl;
        return;
    }
    printCodes(node->left, code + "0");
    printCodes(node->right, code + "1");
}

int main(){
    char chars[] = {'a','b','c','d','e','f'};
    int freqs[] = {5,9,12,13,16,45};
    int n = 6;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(int i = 0; i <n; i++){
        pq.push(new Node(chars[i], freqs[i], NULL, NULL));
    }

    while (pq.size() > 1){
        Node *x = pq.top();
        pq.pop();
        Node *y = pq.top();
        pq.pop();
        pq.push(new Node('-', x->freq + y->freq, x, y));
    }

    Node *root = pq.top();
    printCodes(root, "");

    return 0;
}
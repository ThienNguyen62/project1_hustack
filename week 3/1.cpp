//1 Insertion and PreOrder Traversal
/*
Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
insert k: insert a key k into the BST (do not insert if the key k exists)
Input
•Each line contains command under the form: “insert k”
•The input is terminated by a line containing #
Output
•Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
Example
Input
insert 20
insert 10
insert 26
insert 7
insert 15
insert 23
insert 30
insert 3
insert 8
#
Output
20 10 7 3 8 15 26 23 30
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int k) {
    if (root == nullptr)
        return new Node(k);

    if (k < root->key)
        root->left = insert(root->left, k);
    else if (k > root->key)
        root->right = insert(root->right, k);

    return root;
}

void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;
    string cmd;
    int k;

    while (cin >> cmd && cmd != "#") {
        if (cmd == "insert") {
            cin >> k;
            root = insert(root, k);
        }
    }

    preorder(root);

    return 0;
}

//8  Tree manipulation & Traversal
/*
Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10
*/


#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;

    Node(int x) {
        id = x;
    }
};

Node* root = nullptr;
map<int, Node*> nodes;

void makeRoot(int u) {
    if (root != nullptr)
        return;

    root = new Node(u);
    nodes[u] = root;
}

void insertNode(int u, int v) {
    if (nodes.count(u) || !nodes.count(v))
        return;

    Node* p = new Node(u);
    nodes[u] = p;
    nodes[v]->children.push_back(p);
}

void preOrder(Node* p) {
    if (p == nullptr)
        return;

    cout << p->id << " ";

    for (Node* child : p->children)
        preOrder(child);
}

void inOrder(Node* p) {
    if (p == nullptr)
        return;

    int n = p->children.size();

    if (n > 0)
        inOrder(p->children[0]);

    cout << p->id << " ";

    for (int i = 1; i < n; i++)
        inOrder(p->children[i]);
}

void postOrder(Node* p) {
    if (p == nullptr)
        return;

    for (Node* child : p->children)
        postOrder(child);

    cout << p->id << " ";
}

int main() {
    string cmd;
    int u, v;

    while (cin >> cmd && cmd != "*") {
        if (cmd == "MakeRoot") {
            cin >> u;
            makeRoot(u);
        }
        else if (cmd == "Insert") {
            cin >> u >> v;
            insertNode(u, v);
        }
        else if (cmd == "PreOrder") {
            preOrder(root);
            cout << endl;
        }
        else if (cmd == "InOrder") {
            inOrder(root);
            cout << endl;
        }
        else if (cmd == "PostOrder") {
            postOrder(root);
            cout << endl;
        }
    }

    return 0;
}

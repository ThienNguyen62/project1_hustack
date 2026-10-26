//5  Linked List Manipulation
/*
Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a
1
, a
2
, …, a
n
, sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a
1
, a
2
, …, a
n
.
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10 
*/


#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

Node* head = nullptr;

bool exists(int k) {
    Node* p = head;
    while (p != nullptr) {
        if (p->key == k)
            return true;
        p = p->next;
    }
    return false;
}

void addfirst(int k) {
    if (exists(k))
        return;

    Node* p = new Node(k);
    p->next = head;
    head = p;
}

void addlast(int k) {
    if (exists(k))
        return;

    Node* p = new Node(k);

    if (head == nullptr) {
        head = p;
        return;
    }

    Node* q = head;
    while (q->next != nullptr)
        q = q->next;

    q->next = p;
}

void addafter(int u, int v) {
    if (exists(u))
        return;

    Node* p = head;
    while (p != nullptr && p->key != v)
        p = p->next;

    if (p == nullptr)
        return;

    Node* q = new Node(u);
    q->next = p->next;
    p->next = q;
}

void addbefore(int u, int v) {
    if (exists(u))
        return;

    if (head == nullptr)
        return;

    if (head->key == v) {
        addfirst(u);
        return;
    }

    Node* p = head;
    while (p->next != nullptr && p->next->key != v)
        p = p->next;

    if (p->next == nullptr)
        return;

    Node* q = new Node(u);
    q->next = p->next;
    p->next = q;
}

void removeNode(int k) {
    if (head == nullptr)
        return;

    if (head->key == k) {
        Node* p = head;
        head = head->next;
        delete p;
        return;
    }

    Node* p = head;
    while (p->next != nullptr && p->next->key != k)
        p = p->next;

    if (p->next == nullptr)
        return;

    Node* q = p->next;
    p->next = q->next;
    delete q;
}

void reverseList() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void printList() {
    Node* p = head;

    while (p != nullptr) {
        cout << p->key;
        if (p->next != nullptr)
            cout << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n, k, u, v;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        addlast(k);
    }

    while (cin >> cmd && cmd != "#") {
        if (cmd == "addlast") {
            cin >> k;
            addlast(k);
        }
        else if (cmd == "addfirst") {
            cin >> k;
            addfirst(k);
        }
        else if (cmd == "addafter") {
            cin >> u >> v;
            addafter(u, v);
        }
        else if (cmd == "addbefore") {
            cin >> u >> v;
            addbefore(u, v);
        }
        else if (cmd == "remove") {
            cin >> k;
            removeNode(k);
        }
        else if (cmd == "reverse") {
            reverseList();
        }
    }

    printList();

    return 0;
}

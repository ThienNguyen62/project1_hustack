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

/*chủ đề cây nhị phân tìm kiếm, con trỏ , đệ quy, duyệt cây
cây nhị phân là cây mà node đầu tiên là root, left là con bên trái, right là con bên phải
cây nhị phân tìm kiếm thì cây con trái nhỏ hơn root, con cây con phải sẽ lớn hơn root
quy tắc áp dụng tại mọi node không chỉ root

vd
       20
      /  \
    10    26
   /  \
  7   15
sau khi preorder 20 10 7 15 26

preorder là root -left - right
inorder là left - root -right
postorder là left - right -root
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right; // 2 con trỏ lưu địa chỉ node khác

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};
// hàm trả về con trỏ tới root cây con sau khi chèn
Node* insert(Node* root, int k) { // node*root là con trỏ gốc của cây con đang xét, k là khóa cần chèn
    if (root == nullptr)
        return new Node(k);  // nếu vị trí không có node, tạo node mới chứa k và trả về địa chỉ của node đó
    // nếu khóa nhỏ hơn
    if (k < root->key)
        root->left = insert(root->left, k);
    // nếu khóa lớn hơn
    else if (k > root->key)
        root->right = insert(root->right, k);
    // nếu khóa bằng nhau thì không chèn
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
/*
INPUT
=========================================================

insert 20
insert 10
insert 30
insert 5
insert 15
#

=========================================================
PHẦN 1: CHẠY HÀM main()
=========================================================

BƯỚC 1:
    Node* root = nullptr;

    => Cây hiện tại rỗng.
    => root chưa trỏ đến node nào.

BƯỚC 2:
    cin >> cmd;   // cmd = "insert"
    cin >> k;     // k = 20

    root = insert(root, 20);

    Tương đương:
    root = insert(nullptr, 20);

    Chuyển sang hàm insert().

---------------------------------------------------------
PHẦN 2: CHÈN SỐ 20
---------------------------------------------------------

GỌI: insert(nullptr, 20)

    if (root == nullptr)
        return new Node(20);

    => Điều kiện đúng.
    => Tạo node chứa key = 20.
    => left = nullptr, right = nullptr.
    => Trả về địa chỉ Node(20).

QUAY VỀ main():

    root = địa_chỉ_Node_20;

CÂY HIỆN TẠI:

        20

---------------------------------------------------------
PHẦN 3: CHÈN SỐ 10
---------------------------------------------------------

main() đọc:
    cmd = "insert"
    k = 10

Gọi:
    root = insert(root, 10);

LẦN GỌI 1: insert(Node20, 10)

    root == nullptr ? SAI

    10 < 20 ? ĐÚNG

    Thực hiện:
    root->left = insert(root->left, 10);

    Vì Node20->left == nullptr:

    => Gọi insert(nullptr, 10).
    => insert(Node20, 10) TẠM DỪNG tại đây.

LẦN GỌI 2: insert(nullptr, 10)

    root == nullptr ? ĐÚNG

    return new Node(10);

    => Tạo Node10.
    => Trả địa chỉ Node10.

QUAY VỀ LẦN GỌI 1:

    Node20->left = Node10;

    Sau đó chạy:
    return root;

    => Trả lại Node20.

QUAY VỀ main():

    root = Node20;

CÂY HIỆN TẠI:

        20
       /
      10

---------------------------------------------------------
PHẦN 4: CHÈN SỐ 30
---------------------------------------------------------

main() đọc:
    k = 30

Gọi:
    insert(Node20, 30)

LẦN GỌI 1:

    30 < 20 ? SAI
    30 > 20 ? ĐÚNG

    root->right = insert(root->right, 30);

    Node20->right == nullptr.

    => Gọi insert(nullptr, 30).

LẦN GỌI 2:

    root == nullptr ? ĐÚNG

    return new Node(30);

QUAY VỀ LẦN GỌI 1:

    Node20->right = Node30;
    return Node20;

CÂY HIỆN TẠI:

        20
       /  \
      10   30

---------------------------------------------------------
PHẦN 5: CHÈN SỐ 5
---------------------------------------------------------

main() đọc:
    k = 5

Gọi:
    insert(Node20, 5)

LẦN GỌI 1: insert(Node20, 5)

    5 < 20 ? ĐÚNG

    root->left = insert(Node10, 5);

    => Tạm dừng tại Node20.

LẦN GỌI 2: insert(Node10, 5)

    5 < 10 ? ĐÚNG

    root->left = insert(nullptr, 5);

    => Tạm dừng tại Node10.

LẦN GỌI 3: insert(nullptr, 5)

    root == nullptr ? ĐÚNG

    return new Node(5);

BẮT ĐẦU QUAY NGƯỢC:

    Lần gọi 3 trả Node5.
            |
            v
    Node10->left = Node5;

    Lần gọi 2:
        return Node10;
            |
            v
    Node20->left = Node10;

    Lần gọi 1:
        return Node20;
            |
            v
    main():
        root = Node20;

CÂY HIỆN TẠI:

          20
         /  \
       10    30
      /
     5

---------------------------------------------------------
PHẦN 6: CHÈN SỐ 15
---------------------------------------------------------

main() đọc:
    k = 15

Gọi:
    insert(Node20, 15)

LẦN GỌI 1:

    15 < 20 ? ĐÚNG

    => Gọi insert(Node10, 15).

LẦN GỌI 2:

    15 < 10 ? SAI
    15 > 10 ? ĐÚNG

    => Gọi insert(nullptr, 15).

LẦN GỌI 3:

    root == nullptr ? ĐÚNG

    => Tạo Node15.
    => return Node15.

QUAY NGƯỢC:

    Node10->right = Node15;
    return Node10;

    Node20->left = Node10;
    return Node20;

    main():
        root = Node20;

CÂY CUỐI CÙNG:

          20
         /  \
       10    30
      /  \
     5   15

=========================================================
PHẦN 7: GẶP DẤU #
=========================================================

main() đọc:
    cmd = "#"

Điều kiện:

    while (cin >> cmd && cmd != "#")

    => cmd != "#" là SAI.
    => Thoát vòng while.

Chương trình thực hiện:

    preorder(root);

Tức:
    preorder(Node20);

=========================================================
PHẦN 8: MÔ PHỎNG PREORDER
=========================================================

QUY TẮC: ROOT -> LEFT -> RIGHT

LẦN 1: preorder(Node20)

    root != nullptr

    cout << 20;       // OUTPUT: 20

    preorder(Node10); // Gọi hàm, tạm dừng Node20.

LẦN 2: preorder(Node10)

    cout << 10;       // OUTPUT: 20 10

    preorder(Node5);  // Gọi hàm, tạm dừng Node10.

LẦN 3: preorder(Node5)

    cout << 5;        // OUTPUT: 20 10 5

    preorder(Node5->left);

    Vì Node5->left == nullptr:
        preorder(nullptr)
        => return;

    Quay về preorder(Node5).

    Tiếp tục:
        preorder(Node5->right);

    Vì Node5->right == nullptr:
        preorder(nullptr)
        => return;

    => preorder(Node5) kết thúc.
    => Quay về preorder(Node10).

LẦN 4: Quay lại preorder(Node10)

    Đã chạy xong:
        preorder(root->left);

    Tiếp tục dòng kế tiếp:
        preorder(root->right);

    => Gọi preorder(Node15).

LẦN 5: preorder(Node15)

    cout << 15;       // OUTPUT: 20 10 5 15

    preorder(nullptr); // left -> return
    preorder(nullptr); // right -> return

    => Kết thúc preorder(Node15).
    => Quay về preorder(Node10).

QUAY VỀ preorder(Node10):

    Đã duyệt xong left và right.
    => Kết thúc hàm.
    => Quay về preorder(Node20).

QUAY VỀ preorder(Node20):

    Đã duyệt xong cây con trái.

    Tiếp tục:
        preorder(root->right);

    => Gọi preorder(Node30).

LẦN 6: preorder(Node30)

    cout << 30;       // OUTPUT: 20 10 5 15 30

    preorder(nullptr); // left -> return
    preorder(nullptr); // right -> return

    => Kết thúc preorder(Node30).
    => Quay về preorder(Node20).

QUAY VỀ preorder(Node20):

    Đã duyệt xong trái và phải.
    => Kết thúc preorder(Node20).
    => Quay về main().

main():
    return 0;

=========================================================
OUTPUT CUỐI CÙNG
=========================================================

20 10 5 15 30

=========================================================
ĐIỀU CẦN NHỚ
=========================================================

1. insert() đi từ root xuống để tìm vị trí chèn.

2. Khi gặp nullptr:
       return new Node(k);

3. Khi return:
       Trả con trỏ ngược về các lời gọi trước.

4. preorder() luôn thực hiện:
       In root
       Duyệt hết cây con trái
       Duyệt hết cây con phải

5. Khi một lời gọi đệ quy kết thúc:
       Chương trình quay về ngay sau dòng đã gọi nó.

=========================================================
*/
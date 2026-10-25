/*Text Replacement
Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). 
Hãy thay thế các xâu P1 trong T bằng xâu P2.
Dữ liệu
· Dòng 1: xâu P1
· Dòng 2: xâu P2
· Dòng 3: văn bản T
Kết quả:
· Ghi văn bản T sau khi thay thế
Ví dụ
Dữ liệu
AI
Artificial Intelligence
Recently, AI is a key technology. AI enable efficient operations in many fields.
Kết quả
Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable 
efficient operations in many fields.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string P1, P2, T;
    // nhập string
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    size_t pos = 0; // kiểu dữ liệu số nguyên không dấu, dùng để biểu diễn kích thước và vị trí

    while ((pos = T.find(P1, pos)) != string::npos) 
    {
        T.replace(pos, P1.length(), P2);

        // Tiếp tục tìm sau phần vừa thay thế
        pos += P2.length();
    }

    cout << T;

    return 0;
}
/*
tìm vị trí của Ai tring T
thay Ai bằng AR...
tiếp tục tìm xem con ai nào khác không
không thấy nữa thì dừng


cách hàm sẵn
getline (cin,s) đọc cả một dòng văn bản
T.find(P1,pos)  tìm vị trí xuất hiện của P1 trong T
T.replace (pos,n,P2)  thay n ký tự trong T bằng P2
p1.length() lấy độ dài chuỗi P1
String::npos hằng số biểu thị không tìm thấy
size_t kiểu dữ liệu số nguyên không dấu, thuwognf dùng cho vị trí và kích thước
*/
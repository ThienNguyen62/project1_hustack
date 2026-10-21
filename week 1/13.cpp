/*So sánh chênh lệch giá điện theo đề xuất mới của EVN
Hiện tại giá điện đang được tính theo bậc thang gồm 6 mức (mức điều chỉnh từ 04/05/2023), với giá thấp nhất (bậc 1) là 1.728VND và giá bậc cao nhất là 3.015 VND. Tuy nhiên EVN đang đề xuất một cách tính giá điện bậc thang mới chỉ gồm 5 mức như hinh dưới, giá thấp nhất (bậc 1) khoảng 1.728 đồng một kWh và cao nhất (bậc 5) là 3.457 đồng một kWh. 

Bậc	Biểu giá hiện hành	Phương án 5 bậc
  	Mức sử dụng	Giá (*)	Mức sử dụng	Giá
1	0-50 kWh	1.728	0-100 kWh	1.728
2	51-100 kWh	1.786	101-200 kWh	2.074
3	101-200 kWh	2.074	201-400 kWh	2.612
4	201-300 kWh	2.612	401-700 kWh	3.111
5	301-400 kWh	2.919	701 kWh trở lên	3.457
6  	401 kWh trở lên	3.015		
(*) Giá chưa bao gồm thuế VAT

Hãy xây dựng chương trình nhập vào số kwh điện của một hộ tiêu thụ và so sánh xem theo bảng giá mới đang lấy ý kiến thì tiền điện tiêu thụ của hộ đó sẽ tăng thêm hay giảm đi bao nhiêu.

INPUT: là số kwh điện tiêu thụ của hộ (là số nguyên)
OUTPUT: là chênh lệch giữa giá theo đề xuất và giá theo mô hình bậc thang 6 mức đang được áp dụng.

VAT sẽ được lấy là 10%, và kết quả in ra sẽ lấy tới 2 chữ số thập phân

EXAMPLE 
INPUT
540
OUTPUT
-22176.00


INPUT
70
OUTPUT
-1276.00
*/
#include <bits/stdc++.h>
using namespace std;

long long giaCu(int kwh) {
    long long tien = 0;

    if (kwh <= 50)
        tien = 1LL * kwh * 1728;
    else if (kwh <= 100)
        tien = 50LL * 1728
             + 1LL * (kwh - 50) * 1786;
    else if (kwh <= 200)
        tien = 50LL * 1728
             + 50LL * 1786
             + 1LL * (kwh - 100) * 2074;
    else if (kwh <= 300)
        tien = 50LL * 1728
             + 50LL * 1786
             + 100LL * 2074
             + 1LL * (kwh - 200) * 2612;
    else if (kwh <= 400)
        tien = 50LL * 1728
             + 50LL * 1786
             + 100LL * 2074
             + 100LL * 2612
             + 1LL * (kwh - 300) * 2919;
    else
        tien = 50LL * 1728
             + 50LL * 1786
             + 100LL * 2074
             + 100LL * 2612
             + 100LL * 2919
             + 1LL * (kwh - 400) * 3015;

    return tien;
}

long long giaMoi(int kwh) {
    long long tien = 0;

    if (kwh <= 100)
        tien = 1LL * kwh * 1728;
    else if (kwh <= 200)
        tien = 100LL * 1728
             + 1LL * (kwh - 100) * 2074;
    else if (kwh <= 400)
        tien = 100LL * 1728
             + 100LL * 2074
             + 1LL * (kwh - 200) * 2612;
    else if (kwh <= 700)
        tien = 100LL * 1728
             + 100LL * 2074
             + 200LL * 2612
             + 1LL * (kwh - 400) * 3111;
    else
        tien = 100LL * 1728
             + 100LL * 2074
             + 200LL * 2612
             + 300LL * 3111
             + 1LL * (kwh - 700) * 3457;

    return tien;
}

int main() {
    int kwh;
    cin >> kwh;

    long long cu = giaCu(kwh);
    long long moi = giaMoi(kwh);

    // Chênh lệch sau khi tính VAT 10%
    double chenhLech = (moi - cu) * 1.1;

    cout << fixed << setprecision(2) << chenhLech;

    return 0;
}

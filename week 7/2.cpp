/*Analyze sales order of an e-commerce company
Trung bình
Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
            <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
<CustomerID>: string of length from 3 to 10
<ProductID>: string of length from 3 to 10
<Price>: a positive integer from 1 to 1000
<ShopID>: string of length from 3 to 10
<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)


Perform a sequence of queries of following types:
?total_number_orders: return the total number of orders
?total_revenue: return the total revenue the e-commerce company gets
?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets 
?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID> 
?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)

Input
The input consists of two blocks of data:
The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format 
The first block is terminated with a line containing the character #
The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
The second block is terminated with a line containing the character #

Output
Write in each line, the result of the corresponding query 

Example
Input
C001 P001 10 SHOP001 10:30:10
C001 P002 30 SHOP001 12:30:10
C003 P001 40 SHOP002 10:15:20
C001 P001 80 SHOP002 08:40:10
C002 P001 130 SHOP001 10:30:10
C002 P001 160 SHOP003 11:30:20
#
?total_number_orders
?total_revenue
?revenue_of_shop SHOP001
?total_consume_of_customer_shop C001 SHOP001 
?total_revenue_in_period 10:00:00 18:40:45
#


Output 
6
450
170
40
370
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int totalOrders = 0;
    long long totalRevenue = 0;

    unordered_map<string, long long> shopRevenue;
    unordered_map<string, unordered_map<string, long long>> customerShop;

    long long revenueByTime[86401] = {0};

    string customer, product, shop, time;
    int price;

    // Read orders
    while (cin >> customer && customer != "#") {
        cin >> product >> price >> shop >> time;

        totalOrders++;
        totalRevenue += price;

        shopRevenue[shop] += price;
        customerShop[customer][shop] += price;

        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));

        int seconds = h * 3600 + m * 60 + s;
        revenueByTime[seconds] += price;
    }

    // Calculate prefix sums
    for (int i = 1; i <= 86400; i++) {
        revenueByTime[i] += revenueByTime[i - 1];
    }

    // Process queries
    string query;

    while (cin >> query && query != "#") {

        if (query == "?total_number_orders") {
            cout << totalOrders << '\n';
        }

        else if (query == "?total_revenue") {
            cout << totalRevenue << '\n';
        }

        else if (query == "?revenue_of_shop") {
            cin >> shop;
            cout << shopRevenue[shop] << '\n';
        }

        else if (query == "?total_consume_of_customer_shop") {
            cin >> customer >> shop;
            cout << customerShop[customer][shop] << '\n';
        }

        else if (query == "?total_revenue_in_period") {
            string fromTime, toTime;
            cin >> fromTime >> toTime;

            int h1 = stoi(fromTime.substr(0, 2));
            int m1 = stoi(fromTime.substr(3, 2));
            int s1 = stoi(fromTime.substr(6, 2));

            int h2 = stoi(toTime.substr(0, 2));
            int m2 = stoi(toTime.substr(3, 2));
            int s2 = stoi(toTime.substr(6, 2));

            int start = h1 * 3600 + m1 * 60 + s1;
            int finish = h2 * 3600 + m2 * 60 + s2;

            long long result = revenueByTime[finish];

            if (start > 0) {
                result -= revenueByTime[start - 1];
            }

            cout << result << '\n';
        }
    }

    return 0;
}

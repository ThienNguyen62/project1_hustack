/*Course assignment balancing sum credits and lower bound on number of courses between teachers
At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each course i has credit crd(i) (i = 1,2,...,n). Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. 
Each teacher j has LB(j) which is the minimum number of courses assigned to her/him.
We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the sum of credits of courses assigned to her/him. How to assign nn courses to mm teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
Input
The input consists of following lines
Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
Line m+2: contains crd(1), crd(2), . . ., crd(n) (1 <= crd(i) <= 10)
Line m+3: contains m integers LB(1), LB(2), . . ., LB(m);
Line m+4: contains an integer k
Line i+m+4: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
Output
The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
Example
Input
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
2 3 3 2 1 2 3 2 2 2 3 1
3 1 1 1
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12


Output
8
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int m, n;
vector<int> credit;
vector<vector<int>> canTeach;
vector<unsigned int> conflictMask;
vector<unsigned int> assignedMask;
vector<int> loadTeacher;
vector<int> countTeacher;
vector<int> LB;
vector<int> assigned;

bool feasible(int limit) {
    fill(assignedMask.begin(), assignedMask.end(), 0);
    fill(loadTeacher.begin(), loadTeacher.end(), 0);
    fill(countTeacher.begin(), countTeacher.end(), 0);
    fill(assigned.begin(), assigned.end(), -1);

    auto dfs = [&](auto&& self, int done) -> bool {
        if (done == n) {
            for (int t = 0; t < m; t++) {
                if (countTeacher[t] < LB[t])
                    return false;
            }
            return true;
        }

        int remaining = n - done;
        int totalNeed = 0;

        for (int t = 0; t < m; t++) {
            int need = max(0, LB[t] - countTeacher[t]);
            totalNeed += need;

            int possible = 0;

            for (int c = 0; c < n; c++) {
                if (assigned[c] == -1 && canTeach[t][c]) {
                    if (loadTeacher[t] + credit[c] <= limit &&
                        !(assignedMask[t] & conflictMask[c])) {
                        possible++;
                    }
                }
            }

            if (possible < need)
                return false;
        }

        if (totalNeed > remaining)
            return false;

        int bestCourse = -1;
        int bestCount = m + 1;
        int bestDegree = -1;
        int bestCredit = -1;
        vector<int> bestTeachers;

        for (int c = 0; c < n; c++) {
            if (assigned[c] != -1)
                continue;

            vector<int> teachers;

            for (int t = 0; t < m; t++) {
                if (!canTeach[t][c])
                    continue;

                if (loadTeacher[t] + credit[c] > limit)
                    continue;

                if (assignedMask[t] & conflictMask[c])
                    continue;

                teachers.push_back(t);
            }

            if (teachers.empty())
                return false;

            int degree = __builtin_popcount(conflictMask[c]);

            if ((int)teachers.size() < bestCount ||
                ((int)teachers.size() == bestCount && degree > bestDegree) ||
                ((int)teachers.size() == bestCount && degree == bestDegree &&
                 credit[c] > bestCredit)) {
                bestCount = teachers.size();
                bestCourse = c;
                bestDegree = degree;
                bestCredit = credit[c];
                bestTeachers = teachers;
            }
        }

        sort(bestTeachers.begin(), bestTeachers.end(), [&](int a, int b) {
            bool needA = countTeacher[a] < LB[a];
            bool needB = countTeacher[b] < LB[b];

            if (needA != needB)
                return needA > needB;

            if (loadTeacher[a] != loadTeacher[b])
                return loadTeacher[a] < loadTeacher[b];

            return countTeacher[a] < countTeacher[b];
        });

        for (int t : bestTeachers) {
            assigned[bestCourse] = t;
            loadTeacher[t] += credit[bestCourse];
            countTeacher[t]++;
            assignedMask[t] |= (1u << bestCourse);

            if (self(self, done + 1))
                return true;

            assignedMask[t] ^= (1u << bestCourse);
            countTeacher[t]--;
            loadTeacher[t] -= credit[bestCourse];
            assigned[bestCourse] = -1;
        }

        return false;
    };

    return dfs(dfs, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    canTeach.assign(m, vector<int>(n, 0));

    for (int t = 0; t < m; t++) {
        int k;
        cin >> k;

        while (k--) {
            int c;
            cin >> c;
            canTeach[t][c - 1] = 1;
        }
    }

    credit.resize(n);

    for (int i = 0; i < n; i++)
        cin >> credit[i];

    LB.resize(m);

    for (int i = 0; i < m; i++)
        cin >> LB[i];

    conflictMask.assign(n, 0);

    int k;
    cin >> k;

    while (k--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        conflictMask[u] |= (1u << v);
        conflictMask[v] |= (1u << u);
    }

    assignedMask.assign(m, 0);
    loadTeacher.assign(m, 0);
    countTeacher.assign(m, 0);
    assigned.assign(n, -1);

    if (accumulate(LB.begin(), LB.end(), 0) > n) {
        cout << -1;
        return 0;
    }

    for (int c = 0; c < n; c++) {
        bool ok = false;

        for (int t = 0; t < m; t++) {
            if (canTeach[t][c]) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << -1;
            return 0;
        }
    }

    int totalCredit = accumulate(credit.begin(), credit.end(), 0);

    int low = *max_element(credit.begin(), credit.end());
    low = max(low, (totalCredit + m - 1) / m);

    int high = totalCredit;
    int answer = -1;

    if (!feasible(high)) {
        cout << -1;
        return 0;
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (feasible(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer;

    return 0;
}

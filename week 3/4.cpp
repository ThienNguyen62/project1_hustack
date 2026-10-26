//4  Family Tree
/*
Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, vector<string>> tree;
map<string, int> desc, gen;

int descendants(string name) {
    if (desc.count(name))
        return desc[name];

    int cnt = 0;

    for (string child : tree[name]) {
        cnt += 1 + descendants(child);
    }

    desc[name] = cnt;
    return cnt;
}

int generation(string name) {
    if (gen.count(name))
        return gen[name];

    int maxGen = 0;

    for (string child : tree[name]) {
        maxGen = max(maxGen, 1 + generation(child));
    }

    gen[name] = maxGen;
    return maxGen;
}

int main() {
    string child, parent, cmd, name;

    while (cin >> child && child != "***") {
        cin >> parent;
        tree[parent].push_back(child);
    }

    while (cin >> cmd && cmd != "***") {
        cin >> name;

        if (cmd == "descendants")
            cout << descendants(name) << endl;
        else if (cmd == "generation")
            cout << generation(name) << endl;
    }

    return 0;
}

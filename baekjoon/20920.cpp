#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<pair<int, string>> v = {
        {2, "apple"},
        {1, "banana"},
        {2, "cherry"},
        {1, "date"}
    };

    // sort (�Ҿ��� ����)
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.first < b.first;
        });
    cout << "sort ���:\n";
    for (auto& p : v) cout << p.first << " " << p.second << "\n";

    // stable_sort (���� ����)
    vector<pair<int, string>> v2 = {
        {2, "apple"},
        {1, "banana"},
        {2, "cherry"},
        {1, "date"}
    };
    stable_sort(v2.begin(), v2.end(), [](auto& a, auto& b) {
        return a.first < b.first;
        });
    cout << "\nstable_sort ���:\n";
    for (auto& p : v2) cout << p.first << " " << p.second << "\n";
}

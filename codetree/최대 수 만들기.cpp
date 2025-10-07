#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[50000];

bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    sort(arr, arr + n, cmp);
    string result = "";
    for (int i = 0; i < n; i++) {
            result += to_string(arr[i]);
    }

    cout << result;
    return 0;
}

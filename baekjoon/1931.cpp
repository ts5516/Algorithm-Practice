#include <iostream>

using namespace std;

int num1_count = 0;
int num0_count = 0;

int fibonacci(int n) {
    if (n == 0) {
        num0_count++;
        return 0;
    }
    else if (n == 1) {
        num1_count++;
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        fibonacci(n);
        cout << num0_count << " " << num1_count << "\n";
        num0_count = 0; num1_count = 0;
        t--;
    }

    return 0;
}
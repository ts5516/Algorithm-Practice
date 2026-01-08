#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int a, b, c;
    cin >> a >> b >> c;

    int max_prev[3] = { a, b, c };
    int min_prev[3] = { a, b, c };

    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;

        int max_curr[3];
        int min_curr[3];

        // 0번 열
        max_curr[0] = max(max_prev[0], max_prev[1]) + a;
        min_curr[0] = min(min_prev[0], min_prev[1]) + a;

        // 1번 열 (세 개 중 최대/최소)
        max_curr[1] = max(max(max_prev[0], max_prev[1]), max_prev[2]) + b;
        min_curr[1] = min(min(min_prev[0], min_prev[1]), min_prev[2]) + b;

        // 2번 열
        max_curr[2] = max(max_prev[1], max_prev[2]) + c;
        min_curr[2] = min(min_prev[1], min_prev[2]) + c;

        // 현재 값을 이전 값으로 복사
        for (int j = 0; j < 3; j++) {
            max_prev[j] = max_curr[j];
            min_prev[j] = min_curr[j];
        }
    }

    int max_result = max(max(max_prev[0], max_prev[1]), max_prev[2]);
    int min_result = min(min(min_prev[0], min_prev[1]), min_prev[2]);

    cout << max_result << " " << min_result;
    return 0;
}

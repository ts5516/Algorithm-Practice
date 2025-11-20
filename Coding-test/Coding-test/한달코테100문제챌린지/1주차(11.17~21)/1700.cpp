#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> arr(K);
    for (int i = 0; i < K; i++) cin >> arr[i];

    set<int> multi_tab;
    int result = 0;

    for (int i = 0; i < K; i++) {

        // 이미 꽂혀 있으면 패스
        if (multi_tab.count(arr[i])) continue;

        // 아직 포트가 남아있으면 그냥 꽂기
        if (multi_tab.size() < N) {
            multi_tab.insert(arr[i]);
            continue;
        }

        // 뽑을 기기 고르기
        int remove_target = -1;
        int farthest_index = -1;

        for (int m : multi_tab) {
            int next_use = 1e9;

            // 현재 i 이후에서 m이 다시 언제 쓰이는지 탐색
            for (int j = i + 1; j < K; j++) {
                if (arr[j] == m) {
                    next_use = j;
                    break;
                }
            }

            // 아예 안 쓰이면 즉시 뽑기
            if (next_use == 1e9) {
                remove_target = m;
                break;
            }

            // 가장 나중에 다시 사용되는 기기 선택
            if (next_use > farthest_index) {
                farthest_index = next_use;
                remove_target = m;
            }
        }

        // 뽑고 새 기기 꽂기
        multi_tab.erase(remove_target);
        multi_tab.insert(arr[i]);
        result++;
    }

    cout << result;
    return 0;
}

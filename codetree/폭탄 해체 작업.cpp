#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int score[10000];
int time_limit[10000];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};


int main() {
    cin >> N;

    vector<pair<int, int>> bombs;
    for (int i = 0; i < N; i++) {
        cin >> score[i] >> time_limit[i];
        bombs.push_back({ time_limit[i], score[i] });
    }
    // 폭탄들을 시간 순으로 정렬한다
    sort(bombs.begin(), bombs.end());

    // score가 제일 작은 값이 항상 top에 있다
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (auto bomb : bombs) {
        int time = bomb.first;
        pq.push(bomb);

        // time보다 pq size가 크면 두개의 bomb을 해체할 수 없으므로 pq top인 것을 pop한다
        if (pq.size() > time) {
            pq.pop();
        }
    }

    // 자연스럽게 bomb time 최대값보다 pq.size()가 작거나 같고 그 시간안에 해체할 수 있는 큰 것들만 남는다
    int result = 0;
    while (!pq.empty()) {
        result += pq.top().second;
        pq.pop();
    }

    cout << result;
    return 0;
}

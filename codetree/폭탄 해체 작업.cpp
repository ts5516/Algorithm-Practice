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
    // ��ź���� �ð� ������ �����Ѵ�
    sort(bombs.begin(), bombs.end());

    // score�� ���� ���� ���� �׻� top�� �ִ�
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (auto bomb : bombs) {
        int time = bomb.first;
        pq.push(bomb);

        // time���� pq size�� ũ�� �ΰ��� bomb�� ��ü�� �� �����Ƿ� pq top�� ���� pop�Ѵ�
        if (pq.size() > time) {
            pq.pop();
        }
    }

    // �ڿ������� bomb time �ִ밪���� pq.size()�� �۰ų� ���� �� �ð��ȿ� ��ü�� �� �ִ� ū �͵鸸 ���´�
    int result = 0;
    while (!pq.empty()) {
        result += pq.top().second;
        pq.pop();
    }

    cout << result;
    return 0;
}

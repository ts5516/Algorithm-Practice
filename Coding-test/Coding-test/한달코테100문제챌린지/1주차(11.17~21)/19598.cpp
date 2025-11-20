#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> rooms;
	rooms.reserve(N);

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		rooms.push_back({ start, end });
	}

	/*sort(rooms.begin(), rooms.end(), [](auto& a, auto& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
		});*/

	sort(rooms.begin(), rooms.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto& room : rooms) {
		int start = room.first;
		int end = room.second;

		if (!pq.empty() && pq.top() <= start) {
			pq.pop();
		}

		pq.push(end);
	}

	cout << pq.size();

	return 0;
} 
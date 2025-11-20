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

	vector<pair<int, int>> gas_stations;
	gas_stations.reserve(N);
	
	for (int i = 0; i < N; i++) {
		int locate, oil;
		cin >> locate >> oil;
		gas_stations.push_back({ locate, oil });
	}

	int end, cur_oil;
	cin >> end >> cur_oil;

	sort(gas_stations.begin(), gas_stations.end());

	priority_queue<int> pq;
	int count = 0;
	for (auto& gs : gas_stations) {
		int locate = gs.first;
		int oil = gs.second;

		while (!pq.empty() && cur_oil < locate) {
			cur_oil += pq.top();
			pq.pop();
			count++;
		}

		if (cur_oil >= locate)
			pq.push(oil);
	}

	while (!pq.empty() && cur_oil < end) {
		cur_oil += pq.top();
		pq.pop();
		count++;
	}

	if (cur_oil < end) {
		cout << -1;
	}
	else {
		cout << count;
	}
	
	return 0;
} 
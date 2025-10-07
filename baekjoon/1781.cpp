#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int day = 0;

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) const {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	int N;
	cin >> N;

	int deadline, ramen;
	vector<pair<int, int>> ramens;
	for (int i = 0;i < N; i++) {
		cin >> deadline >> ramen;
		ramens.push_back({ deadline, ramen });
	}

	sort(ramens.begin(), ramens.end());

	int size = 0;
	for (auto& r : ramens) {
	//	cout << "push: " << r.first << " " << r.second << "\n";
		size = r.first;
		pq.push(r);
		
		if (pq.size() > size) {
		//	cout << "pop: " << pq.top().first << " " << pq.top().second << "\n";
			pq.pop();
		}
	}

	int max_ramen = 0;
	while (!pq.empty()) {
		//cout << "add ramen : " << pq.top().second << '\n';;
		max_ramen += pq.top().second;
		pq.pop();
	}

	cout << max_ramen;
	return 0;
} 
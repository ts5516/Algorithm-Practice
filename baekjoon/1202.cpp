#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> gems(n);
	int weight, value;
	for (int i = 0;i < n; i++) {
		cin >> weight >> value;
		gems[i] = { weight, value };
	}

	sort(gems.begin(), gems.end());

	vector<int> bags(k);
	for (int i = 0; i < k; i++) {
		cin >> bags[i];
	}

	sort(bags.begin(), bags.end());
	
	long long result = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> candinates;
	int index = 0;
	for (int b : bags) {
		for (;index < n; index++) {
			if (gems[index].first > b) {
				break;
			}
			candinates.push(gems[index]);
		}
		if (!candinates.empty()) {
			result += candinates.top().second;
			candinates.pop();
		}
	}

	cout << result;
	return 0;
} 
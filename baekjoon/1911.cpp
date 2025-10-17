#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> pool(n);
	int start, end;
	for (int i = 0;i < n; i++) {
		cin >> start >> end;
		pool[i] = { start, end };
	}

	sort(pool.begin(), pool.end());

	int index = 0;
	int count = 0;
	for (int i = 0;i < n; i++) {
		if (pool[i].first > index){
			index = pool[i].first;
		}
		while (index < pool[i].second) {
			index += l;
			count++;
		}
	}

	cout << count;

	return 0;
} 
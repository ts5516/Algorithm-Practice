#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n;
	cin >> n;
	
	vector<pair<int, int>> rooms(n);
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		rooms[i] = { start, end };
	}

	sort(rooms.begin(), rooms.end(), [](auto& a, auto& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
		});

	int time = rooms[0].second;
	int result = 1;

	for (int i = 1; i < n; i++) {
		if (rooms[i].first >= time) {
			time = rooms[i].second;
			result++;
		}
	}

	cout << result;
	return 0;
} 
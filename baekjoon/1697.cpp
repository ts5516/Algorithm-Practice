#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> dots;
	
	vector<bool> visited(200000, false);

	dots.push({n, 0});
	visited[n] = true;

	while (!dots.empty()) {
		int node = dots.front().first;
		int time = dots.front().second;
		dots.pop();

		if (node == k) {
			cout << time;
			return 0;
		}

		if (node - 1 >= 0 && !visited[node - 1]) {
			dots.push({ node - 1, time + 1 });
			visited[node - 1] = true;
		}

		if (node + 1 >= 0 && !visited[node + 1]) {
			dots.push({ node + 1, time + 1 });
			visited[node + 1] = true;
		}

		if (node*2 <= 200000&& node*2 >= 0 && !visited[node*2]) {
			dots.push({ node * 2, time + 1 });
			visited[node*2] = true;
		}
	}

	return 0;
} 
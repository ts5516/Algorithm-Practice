#include <iostream>
#include <vector>

using namespace std;

vector<int> dist;

const int INF = 1e9;

bool bellmanFord(vector<vector<int>>& edges, int n) {
	dist.resize(n + 1, INF);
	dist[1] = 0; // start == 1

	for (int i = 0; i < n - 1; i++) {
		for (auto& edge : edges) {
			int from = edge[0];
			int to = edge[1];
			int weight = edge[2];

			if (dist[from] != INF && dist[to] > dist[from] + weight) {
				dist[to] = dist[from] + weight;
			}
		}
	}

	for (auto& edge : edges) {
		int from = edge[0];
		int to = edge[1];
		int weight = edge[2];

		if (dist[from] != INF && dist[to] > dist[from] + weight) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;

	vector<vector<int>> edges(m, vector<int>(3));
	for (int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}

	if (bellmanFord(edges, n)) {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) {
				cout << -1 << "\n";
			}
			else {
				cout << dist[i] << '\n';
			}
		}
	}
	else {
		cout << -1;
	}

	return 0;
}
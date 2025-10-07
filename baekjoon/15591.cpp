#include <iostream>
#include <queue>
#include <set>

using namespace std;

int bfs(int k, int v, vector<vector<pair<int, int>>>& graph) {
	vector<bool> visited(graph.size(), false);
	queue<int> que;
	visited[v] = true;
	que.push(v);

	int count = 0;
	while (!que.empty()) {
		int node = que.front();
		que.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].first;
			int usado = graph[node][i].second;

			if (!visited[next] && usado >= k) {
				visited[next] = true;
				que.push(next);
				count++;
			}
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<vector<pair<int, int>>> graph(n + 1);
	int from, to, weight;
	for (int i = 0; i < n-1; i++) {
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	int k, v;
	for (int i = 0; i < q; i++) {
		cin >> k >> v;
		cout << bfs(k, v, graph) << "\n";
	}

	return 0;
}
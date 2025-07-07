#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a, b;

vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> path;

const int INF = 1e9;

void Dijkstra() {
	dist.resize(n + 1, INF);
	dist[a] = 0;

	path.resize(n + 1, INF);
	path[a] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, a });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int index = pq.top().second;
		pq.pop();

		if (dist[index] != distance) continue;

		for (int i = 0; i < graph[index].size(); i++) {
			int n_index = graph[index][i].first;
			int n_dist = graph[index][i].second;

			if (dist[n_index] > dist[index] + n_dist) {
				dist[n_index] = dist[index] + n_dist;
				path[n_index] = index;
				pq.push({ dist[n_index], n_index });
			}
			else if (dist[n_index] == dist[index] + n_dist && index < path[n_index]) {
				path[n_index] = index;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	graph.resize(n+1);

	int from, to, weight;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
	}

	cin >> a >> b;

	Dijkstra();

	int x = b;
	vector<int> arr;
	arr.push_back(x);
	while (x != a) {
		x = path[x];
		arr.push_back(x);
	}

	reverse(arr.begin(), arr.end());

	cout << dist[b] << "\n" << arr.size() << "\n";
	for (int i : arr) {
		cout << i << " ";
	}

	return 0;
}
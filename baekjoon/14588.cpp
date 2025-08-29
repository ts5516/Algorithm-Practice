#include <iostream>
#include <vector>

using namespace std;

bool isOverlap(pair<int, int> line1, pair<int, int> line2) {
	if (line1.first < line2.first) {
		return line1.second >= line2.first;
	}
	else if (line1.first > line2.first) {
		return line2.second >= line1.first;
	}
	else {
		return true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	const int INF = 1e9;
	vector<pair<int, int>> lines(N+1);
	vector<vector<int>> graph(N+1, vector<int>(N+1, INF));

	for (int i = 1; i <= N; i++) {
		cin >> lines[i].first >> lines[i].second;

		for (int g = 1; g < i; g++) {
			if (isOverlap(lines[i], lines[g])) {
				graph[i][g] = 1;
				graph[g][i] = 1;
			}
		}

		graph[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int Q;
	cin >> Q;

	int a, b;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		int result = graph[a][b];

		if (result == INF) {
			cout << -1 << "\n";
		}
		else {
			cout << result << "\n";
		}
	}

	return 0;
}
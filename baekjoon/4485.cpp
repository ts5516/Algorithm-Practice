#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <tuple>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int count = 1;

	while (cin >> N && N != 0) {
		vector<vector<int>> board(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		vector<vector<int>> dist(N, vector<int>(N, INF));
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> pq;

		dist[0][0] = board[0][0];
		pq.push({ board[0][0], 0, 0});

		while (!pq.empty()) {
			auto [distance, x, y] = pq.top();
			pq.pop();

			if (distance != dist[x][y]) continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					int newDist = dist[x][y] + board[nx][ny];

					if (dist[nx][ny] > newDist) {
						dist[nx][ny] = newDist;
						pq.push({ newDist, nx, ny });
					}
				}
			}
		}

		cout << "Problem " << count++ << ": " << dist[N - 1][N - 1] << "\n";
	}
	
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int dx[6] = { -2,-2,0,0,2,2 };
	int dy[6] = { -1,1,-2,2,-1,1 };

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;

	vector<vector<int>> visited(N, vector<int>(N, -1));
	queue<pair<int, int>> que;

	que.push({ sx,sy });
	visited[sx][sy] = 0;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if (x == ex && y == ey) break;

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (visited[nx][ny] == -1) {
					visited[nx][ny] = visited[x][y] + 1;
					que.push({ nx, ny });
				}
			}
		}
	}

	cout << visited[ex][ey];

	return 0;
} 
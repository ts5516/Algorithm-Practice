#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int r, c;
int maze[1000][1000];
int visited[1000][1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;

	queue<pair<int, int>> que;

	string line;
	// 0 - empty, 1 - wall, 2 - person, 3 - fire
	for (int i = 0; i < r; i++) {
		cin >> line;
		for (int j = 0; j < c; j++) {
			switch (line[j]) {
			case '.':
				maze[i][j] = 0;
				break;
			case '#':
				maze[i][j] = 1;
				break;
			case 'J':
				maze[i][j] = 2;
				break;
			case 'F':
				maze[i][j] = 3;
				break;
			default:
				break;
			}

			visited[i][j] = -1;

			if (maze[i][j] == 3) {
				que.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 2) {
				que.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	bool isEscape = false;
	int time = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if (maze[x][y] != 3) {
			if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
				isEscape = true;
				time = visited[x][y];
				break;
			}
		}
		

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (visited[nx][ny] < 0 && maze[nx][ny] == 0) {
					visited[nx][ny] = visited[x][y] + 1;
					que.push({ nx, ny });

					if (maze[x][y] == 3) {
						maze[nx][ny] = 3;
					}
				}
			}
		}
	}

	if (isEscape)
		cout << time;
	else
		cout << "IMPOSSIBLE";

	return 0;
}
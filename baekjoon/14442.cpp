#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
	int x, y, wall, move;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> board;
	board.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K+1, false)));
	queue<Node> que;
	que.push({ 0,0,0,1 });

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int wall = que.front().wall;
		int move = que.front().move;
		que.pop();

		if (x == N - 1 && y == M - 1) {
			cout << move;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (board[nx][ny] == 1 && wall < K && !visited[nx][ny][wall + 1]) {
					visited[nx][ny][wall + 1] = true;
					que.push({ nx, ny, wall + 1, move + 1 });
				}
				else if (board[nx][ny] == 0 && !visited[nx][ny][wall]) {
					visited[nx][ny][wall] = true;
					que.push({ nx, ny, wall, move + 1 });
				}
			}
		}
	}

	cout << -1;
	return 0;
} 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x, y, wall, move;
	bool isNight;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<char>> board(N, vector<char>(M, 0));
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j];
		}
	}

	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K+1, false)));
	queue<Node> que;
	que.push({ 0,0,0,1,false });
	visited[0][0][0] = true;

	int dx[5] = { 0,0,1,0,-1 };
	int dy[5] = { 0,1,0,-1,0 };

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int wall = que.front().wall;
		int move = que.front().move;
		bool isNight = que.front().isNight;
		que.pop();

		if (x == N - 1 && y == M - 1) {
			cout << move;
			return 0;
		}

		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (x == nx && y == ny && isNight) {
				que.push({ nx,ny,wall, move + 1, !isNight });
				continue;
			}

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (board[nx][ny] == '1' && !isNight && wall < K && !visited[nx][ny][wall]) {
					visited[nx][ny][wall] = true;
					que.push({ nx,ny, wall + 1, move + 1, !isNight });
				} else if (board[nx][ny] == '0' && !visited[nx][ny][wall]){
					visited[nx][ny][wall] = true;
					que.push({ nx,ny, wall, move + 1, !isNight });
				}
			}
		}
	}
	
	cout << -1;
	return 0;
} 
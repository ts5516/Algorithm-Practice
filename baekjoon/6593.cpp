#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int bfs(int L, int R, int C) {
	vector<vector<vector<int>>> visited;
	visited.resize(L, vector<vector<int>>(R, vector<int>(C, -1)));

	vector<vector<vector<char>>> board;
	board.resize(L, vector<vector<char>>(R, vector<char>(C)));

	queue<vector<int>> que;

	for (int l = 0; l < L; l++) {

		for (int r = 0; r < R; r++) {
			string line;
			cin >> line;

			for (int c = 0; c < C; c++) {
				board[l][r][c] = line[c];
				if (board[l][r][c] == 'S') {
					que.push({ l,r,c });
					visited[l][r][c] = 0;
				}
			}
		}
	}

	int time = -1;
	while (!que.empty()) {
		int x = que.front()[1];
		int y = que.front()[2];
		int z = que.front()[0];
		que.pop();

		if (board[z][x][y] == 'E') {
			time = visited[z][x][y];
			break;
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C && nz >= 0 && nz < L) {
				if (visited[nz][nx][ny] < 0 && board[nz][nx][ny] != '#') {
					visited[nz][nx][ny] = visited[z][x][y] + 1;
					que.push({ nz,nx,ny });
				}
			}
		}
	}

	return time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L = 0, R = 0, C = 0;

	while (cin >> L >> R >> C && !(L == 0 && R == 0 && C == 0)) {
		int result = bfs(L, R, C);
		if (result > 0) {
			cout << "Escaped in " << result << " minute(s)." << "\n";
		}
		else {
			cout << "Trapped!" << "\n";
		}
	}
	
	return 0;
}
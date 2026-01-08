#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<pair<int, int>> que;

	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j];
			if (board[i][j] == 'I') {
				que.push({ i,j });
				visited[i][j] = true;
			}
		}
	}

	int count = 0;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if (board[x][y] == 'P') {
			count++;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visited[nx][ny] && board[nx][ny] != 'X') {
					visited[nx][ny] = true;
					que.push({ nx, ny });
				}
			}	
		}
	}

	if (count == 0) {
		cout << "TT";
	}
	else {
		cout << count;
	}

	return 0;
} 
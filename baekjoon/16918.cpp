#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C, N;
	cin >> R >> C >> N;

	vector<vector<char>> board(R, vector<char>(C));
	vector<vector<int>> bombTime(R, vector<int>(C, 0));

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'O') {
				bombTime[i][j] = 1;
			}
		}
	}

	int time = 1;
	while(time < N) {
		time++;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == '.') {
					board[i][j] = 'O';
					bombTime[i][j] = 0;
				}
				else {
					bombTime[i][j]++;
				}
			}
		}

		/*cout << "Time : " << time << '\n';
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}*/

		if (time == N) {
			break;
		}

		time++;

		queue<pair<int, int>> bomb;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				bombTime[i][j]++;
				if (bombTime[i][j] == 3) {
					bomb.push({ i,j });
				}
			}
		}

		while (!bomb.empty()) {
			int x = bomb.front().first;
			int y = bomb.front().second;
			bomb.pop();

			board[x][y] = '.';
			bombTime[x][y] = 0;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
					board[nx][ny] = '.';
					bombTime[nx][ny] = 0;
				}
			}
		}
		
		/*cout << "Time : " << time << '\n';
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}*/
	}

	//cout << "Result : " << time << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}

	return 0;
} 
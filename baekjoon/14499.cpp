#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 왼, 오 | 위, 아래 | 앞, 뒤
vector<int> dice = {4,3,1,6,5,2};
void rolling(int dir) {
	vector<int> temp = dice;

	switch (dir) {
	case 1: // 동쪽
		dice[0] = temp[3]; dice[1] = temp[2];
		dice[2] = temp[0]; dice[3] = temp[1];
		break;
	case 2: // 서쪽
		dice[0] = temp[2]; dice[1] = temp[3];
		dice[2] = temp[1]; dice[3] = temp[0];
		break;
	case 3:	// 북쪽
		dice[2] = temp[4]; dice[3] = temp[5];
		dice[4] = temp[3]; dice[5] = temp[2];
		break;
	case 4:	// 남쪽
		dice[2] = temp[5]; dice[3] = temp[4];
		dice[4] = temp[2]; dice[5] = temp[3];
		break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	int x, y;
	int K;
	cin >> N >> M >> x >> y >> K;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	int dice_bottom = dice[3];
	vector<int> dice_value = { 0,0,0,0,0,0,0 };
	if (board[x][y] != 0) {
		dice_value[dice_bottom] = board[x][y];
		board[x][y] = 0;
	}

	int dir;
	for (int i = 0; i < K; i++) {
		cin >> dir;

		int nx = x + dx[dir-1];
		int ny = y + dy[dir-1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			x = nx; y = ny;
			rolling(dir);
			dice_bottom = dice[3];
			if (board[x][y] == 0) {
				board[x][y] = dice_value[dice_bottom];
			}
			else {
				dice_value[dice_bottom] = board[x][y];
				board[x][y] = 0;
			}
			
			int dice_cell = dice[2];
			cout << dice_value[dice_cell] << "\n";
		}
	}

	partial_sort(dice.begin(), dice.begin() + 5, dice.end());
	return 0;
} 
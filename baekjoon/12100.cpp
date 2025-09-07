#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};	// up, down, left, right
int dy[4] = {0, 0, -1, 1};

int N;

bool isInRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void moveRight(int d, vector<vector<int>>& board) {
	vector<vector<bool>> merged(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (board[i][j] == 0) continue;

			int nx = i + dx[d];
			int ny = j + dy[d];

			if (!isInRange(nx, ny)) continue;

			while (board[nx][ny] == 0) {
				if (isInRange(nx + dx[d], ny + dy[d])) {
					nx += dx[d];
					ny += dy[d];
				}
				else {
					break;
				}
			}

			if (board[nx][ny] == board[i][j] && !merged[nx][ny]) {
				board[nx][ny] += board[i][j];
				board[i][j] = 0;
				merged[nx][ny] = true;  // º´ÇÕµÊÀ» Ç¥½Ã
			}
			else {
				nx -= dx[d];
				ny -= dy[d];

				if (isInRange(nx, ny) && board[nx][ny] == 0) {
					board[nx][ny] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}
}

void moveLeft(int d, vector<vector<int>>& board) {
	vector<vector<bool>> merged(N, vector<bool>(N, false));
	for (int j = 1; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (board[i][j] == 0) continue;

			int nx = i + dx[d];
			int ny = j + dy[d];

			if (!isInRange(nx, ny)) continue;

			while (board[nx][ny] == 0) {
				if (isInRange(nx + dx[d], ny + dy[d])) {
					nx += dx[d];
					ny += dy[d];
				}
				else {
					break;
				}
			}

			if (board[nx][ny] == board[i][j] && !merged[nx][ny]) {
				board[nx][ny] += board[i][j];
				board[i][j] = 0;
				merged[nx][ny] = true;  // º´ÇÕµÊÀ» Ç¥½Ã
			}
			else {
				nx -= dx[d];
				ny -= dy[d];

				if (isInRange(nx, ny) && board[nx][ny] == 0) {
					board[nx][ny] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}
}

void moveDown(int d, vector<vector<int>>& board) {
	vector<vector<bool>> merged(N, vector<bool>(N, false));
	for (int i = N-2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;

			int nx = i + dx[d];
			int ny = j + dy[d];

			if (!isInRange(nx, ny)) continue;

			while (board[nx][ny] == 0) {
				if (isInRange(nx + dx[d], ny + dy[d])) {
					nx += dx[d];
					ny += dy[d];
				}
				else {
					break;
				}
			}

			if (board[nx][ny] == board[i][j] && !merged[nx][ny]) {
				board[nx][ny] += board[i][j];
				board[i][j] = 0;
				merged[nx][ny] = true;  // º´ÇÕµÊÀ» Ç¥½Ã
			}
			else {
				nx -= dx[d];
				ny -= dy[d];

				if (isInRange(nx, ny) && board[nx][ny] == 0) {
					board[nx][ny] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}
}

void moveUp(int d, vector<vector<int>>& board) {
	vector<vector<bool>> merged(N, vector<bool>(N, false));
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;

			int nx = i + dx[d];
			int ny = j + dy[d];
			
			if (!isInRange(nx, ny)) continue;

			while (board[nx][ny] == 0) {
				if (isInRange(nx + dx[d], ny + dy[d])) {
					nx += dx[d];
					ny += dy[d];
				}
				else {
					break;
				}
			}

			if (board[nx][ny] == board[i][j] && !merged[nx][ny]) {
				board[nx][ny] += board[i][j];
				board[i][j] = 0;
				merged[nx][ny] = true;  // º´ÇÕµÊÀ» Ç¥½Ã
			}
			else {
				nx -= dx[d];
				ny -= dy[d];

				if (isInRange(nx, ny) && board[nx][ny] == 0) {
					board[nx][ny] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}
}

void move(int dir, vector<vector<int>>& board) {
	
	switch (dir) {
	case 0:
		moveUp(dir, board);
		break;
	case 1:
		moveDown(dir, board);
		break;
	case 2:
		moveLeft(dir, board);
		break;
	case 3:
		moveRight(dir, board);
		break;
	default:
		break;
	}

}

int max_result = 0;

void dfs(int depth, vector<vector<int>> board) {
	if (depth == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_result = max(max_result, board[i][j]);
			}
		}
		return;
	}

	auto tempBoard = board;
	for (int i = 0; i < 4; i++) {
		move(i, board);
		dfs(depth + 1, board);
		board = tempBoard;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<vector<int>> board;
	board.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, board);

	cout << max_result;

	return 0;
}
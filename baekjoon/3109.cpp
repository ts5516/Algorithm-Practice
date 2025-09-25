#include <iostream>
#include <vector>

using namespace std;

int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };

bool dfs(int x, int y, vector<vector<bool>>& visited, const vector<vector<char>>& board) {
	if (y == visited[0].size() - 1) {
		return true;
	}

	int n = visited.size();
	int m = visited[0].size();
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || y + 1 >= m) continue;
		if (visited[nx][y + 1] || board[nx][y+1] != '.') continue;
		
		visited[nx][y + 1] = true;
		bool result = dfs(nx, y + 1, visited, board);
		
		if (result) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c;
	cin >> r >> c;
	vector<vector<char>> board(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<bool>> visited(r, vector<bool>(c, false));
	int count = 0;
	for (int i = 0; i < r; i++) {
		visited[i][0] = true;
		bool result = dfs(i, 0, visited, board);
		if (result) {
			count += 1;
		}
	}

	cout << count;

	return 0;
} 
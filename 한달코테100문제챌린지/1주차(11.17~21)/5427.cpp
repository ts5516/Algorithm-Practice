#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int w, h;
		cin >> w >> h;

		vector<vector<char>> board(h, vector<char>(w));
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		queue<vector<int>> que;

		for (int i = 0; i < h; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < w; j++) {
				board[i][j] = line[j];

				if (board[i][j] == '@') {
					que.push({ i,j, 0 });
					visited[i][j] = true;
				} else if(board[i][j] == '*') {
					que.push({ i,j, 1});
					visited[i][j] = true;
				}
			}
		}

		int time = 0;
		int size = que.size();
		int count = 0;
		while (!que.empty()) {
			int x = que.front()[0];
			int y = que.front()[1];
			bool isSangGeon = que.front()[2] ? 0 : 1;

			if (count == size) {

			}
		}
	}

	return 0;
} 
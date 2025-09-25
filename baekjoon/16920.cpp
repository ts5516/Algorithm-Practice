#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct Step {
	int x;
	int y;
};

struct Player {
	int move;
	queue<Step> que;
	int towerNum;
};

bool isEmptyForAll(const vector<Player>& players) {
	for (auto& player : players) {
		if (!player.que.empty()) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<char>> board;
	vector<Player> players;

	int n, m, p;
	cin >> n >> m >> p;
	
	players.resize(p+1);
	for (int i = 1; i <= p; i++) {
		cin >> players[i].move;
		players[i].towerNum = 0;
	}

	board.resize(n, vector<char>(m));

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '#') {
				visited[i][j] = true;
			}
			else if ('1' <= board[i][j] && board[i][j] <= '9') {
				visited[i][j] = true;
				int pnum = board[i][j] - '0';
				players[pnum].que.push({i,j});
				players[pnum].towerNum += 1;
			}
		}
	}

	while (!isEmptyForAll(players)) {
		for (auto& player : players) {
			auto& que = player.que;
		
			int move = 0;
			int size = que.size();
			while (!que.empty() && move != player.move) {
				int x = que.front().x;
				int y = que.front().y;
				que.pop();
				size -= 1;

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (!visited[nx][ny] && board[nx][ny] == '.') {
							visited[nx][ny] = true;
							que.push({ nx, ny });
							player.towerNum += 1;
						}
					}
				}

				if (size == 0) {
					size = que.size();
					move += 1;
				}
			}
		}
	}

	for (int i = 1; i <= p; i++) {
		cout << players[i].towerNum << " ";
	}

	return 0;
} 
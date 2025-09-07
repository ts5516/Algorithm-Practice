#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 상어 : 1 이상 M 이하 자연수 번호가 붙어 있음, 번호는 유니크
// 방향 : 1,2,3,4 / 위, 아래, 왼쪽, 오른쪽
// 우선순위 : 4줄 위, 아래, 왼쪽, 오른쪽
struct Shark {
	int x;
	int y;
	int dir;
	int priority[5][5]; // 0 값은 쓰지 않는다.
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, k;	// N :격자 크기 M : 상어 수, M개의 칸에 한마리씩 들어있음, k: 냄새 지속시간
	cin >> N >> M >> k;

	vector<vector<int>> sharkBoard(N, vector<int>(N, 0));
	vector<vector<pair<int, int>>> smellBoard(N, vector<pair<int,int>>(N, {0,0}));

	vector<Shark> sharks(M + 1);
	set<int> aliveSharks;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sharkBoard[i][j];

			int sharkNum = sharkBoard[i][j];
			if (sharkNum != 0) {
				sharks[sharkNum].x = i;
				sharks[sharkNum].y = j;
				smellBoard[i][j] = { sharkNum, k };
				aliveSharks.insert(sharkNum);
			}
		}
	}

	int dir;
	for (int i = 1; i <= M; i++) {
		cin >> dir;
		sharks[i].dir = dir;
	}

	int priorityDir;
	for (int m = 1; m <= M; m++) {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				cin >> priorityDir;

				sharks[m].priority[i][j] = priorityDir;
			}
		}
	}
	
	int dx[5] = { 0,-1,1,0,0 };	// 0은 쓰지 않는다.
	int dy[5] = { 0,0,0,-1,1 };
	int time = 0;
	while (time < 1000) {
		for (int n = 1; n <= M; n++) {
			if (aliveSharks.count(n)) {
				Shark& shark = sharks[n];
				int sdir = shark.dir;
				bool move = false;
				for (int d = 1; d <= 4; d++) {
					int pdir = shark.priority[sdir][d];
					int nx = shark.x + dx[pdir];
					int ny = shark.y + dy[pdir];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (smellBoard[nx][ny].first == 0) {
							sharkBoard[shark.x][shark.y] = 0;
							shark.x = nx;
							shark.y = ny;
							shark.dir = pdir;

							if (sharkBoard[nx][ny] == 0) {
								sharkBoard[nx][ny] = n;
							}
							else {
								int loser = max(sharkBoard[nx][ny], n);
								int winner = min(sharkBoard[nx][ny], n);

								aliveSharks.erase(loser);
								sharkBoard[nx][ny] = winner;
							}

							move = true;
							break;
						}
					}
				}

				if (!move) {
					for (int d = 1; d <= 4; d++) {
						int pdir = shark.priority[sdir][d];
						int nx = shark.x + dx[pdir];
						int ny = shark.y + dy[pdir];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							if (smellBoard[nx][ny].first == n) {
								sharkBoard[shark.x][shark.y] = 0;
								shark.x = nx;
								shark.y = ny;
								shark.dir = pdir;
								sharkBoard[nx][ny] = n;
								break;
							}
						}
					}
				}
				
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (smellBoard[i][j].first != 0) {
					if (sharkBoard[i][j] != smellBoard[i][j].first) {
						smellBoard[i][j].second -= 1;

						if (smellBoard[i][j].second == 0) {
							smellBoard[i][j].first = 0;
						}
					}
				}

				if (sharkBoard[i][j] != 0) {
					smellBoard[i][j] = { sharkBoard[i][j], k };
				}
			}
		}

		time++;

		if (aliveSharks.size() == 1) {
			cout << time;
			return 0;
		}
	}

	cout << -1;
	return 0;
}
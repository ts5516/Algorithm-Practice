#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 위에서 부터 반시계, 0은 안쓰는 값
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1 };

// 상어가 집에 갈때까지 반복 : 상어는 더이상 이동할 칸이 없으면 집에 간다

struct Fish {
	int num;
	int dir;

	bool operator!= (const Fish& comp) const {
		return this->dir != comp.dir || this->num != comp.num;
	}
};

const Fish Blink = { 0,0 };

const int SHARK_NUM = 100;

int N = 4;
int MaxEatenFish = 0;

void FishMove(int /*depth*/, vector<vector<Fish>>& Fishes, Fish& /*Shark*/) {
	// 현재 상어 위치(= num == SHARK_NUM) 찾기
	int sx = -1, sy = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Fishes[i][j].num == SHARK_NUM) {
				sx = i; sy = j;
				break;
			}
		}
		if (sx != -1) break;
	}

	// 물고기 1번부터 16번까지 순서대로 이동
	for (int target = 1; target <= 16; ++target) {
		int x = -1, y = -1;

		// 현재 보드에서 target 물고기 위치 찾기 (이미 먹혔으면 패스)
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (Fishes[i][j].num == target) { x = i; y = j; }
			}
		}
		if (x == -1) continue; // 먹혔음

		int dir = Fishes[x][y].dir;

		// 최대 8번 회전하며 이동 시도
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 보드 안 & 상어 자리 아님
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !(nx == sx && ny == sy)) {
				// 빈칸이든(0) 다른 물고기든 상관없이 swap
				swap(Fishes[x][y], Fishes[nx][ny]);
				// 이동한(= target) 물고기의 방향을 회전된 dir로 업데이트
				Fishes[nx][ny].dir = dir;

				// 상어가 방금 swap된 곳에 있었다면 sx,sy를 갱신해야 하지만
				// 위 조건에서 (nx,ny)가 상어가 아닌 것을 보장했으므로 필요 없음.
				break;
			}

			// 반시계 회전
			dir++;
			if (dir == 9) dir = 1;
		}
	}
}

void dfs(int depth, int eatenFish, vector<vector<Fish>> Fishes, Fish Shark, pair<int, int> SharkPos) {
	MaxEatenFish = max(MaxEatenFish, eatenFish);

	if (depth == 16) return;

	FishMove(depth, Fishes, Shark);

	int x = SharkPos.first;
	int y = SharkPos.second;
	int dir = Shark.dir;
	
	//if (depth == 6) {
	//	cout << "Depth 6 Current Fish Location\n";
	//	for (int i = 0; i < N; i++) {
	//		for (int j = 0; j < N; j++) {
	//			cout << Fishes[i][j].num << "\t";
	//		}
	//		cout << "\n";
	//	}
	//}

	while (x >= 0 && x < N && y >= 0 && y < N) {
		Fish fish = Fishes[x][y];
		if (fish != Shark && fish != Blink) {
			pair<int, int> tempPos = SharkPos;

			// 기존 상어 위치를 비운다.
			Fishes[SharkPos.first][SharkPos.second] = Blink;

			// 상어 위치와 방향을 해당 물고기 것으로 대체
			SharkPos = { x, y };
			Shark.dir = fish.dir;

			// 상어를 이동하고 해당 물고기를 없앤다.
			Fishes[x][y] = Shark;

			//cout << "Shark eat count " << depth+1 <<  " now fish num: " << fish.num << " and Total Num : " << eatenFish + fish.num << "\n";
			//for (int i = 0; i < N; i++) {
			//	for (int j = 0; j < N; j++) {
			//		cout << Fishes[i][j].num << "\t";
			//	}
			//	cout << "\n";
			//}

			dfs(depth + 1, eatenFish + fish.num, Fishes, Shark, SharkPos);

			Fishes[x][y] = fish;

			Shark.dir = dir;
			SharkPos = tempPos;
			Fishes[SharkPos.first][SharkPos.second] = Shark;
		}
		x += dx[dir];
		y += dy[dir];
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<Fish>> Fishes(N, vector<Fish>(N));

	int fnum, fdir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> fnum >> fdir;
			Fishes[i][j] = { fnum, fdir };
		}
	}

	Fish Shark = { SHARK_NUM, 0 };
	pair<int, int> SharkPos = { 0,0 };

	Fish eatenFish = Fishes[0][0];
	int eatenNum = eatenFish.num;

	// 상어 방향을 해당 물고기 것으로 대체
	Shark.dir = eatenFish.dir;

	// 상어를 이동하고 해당 물고기를 없앤다.
	Fishes[0][0] = Shark;

	dfs(1, eatenNum, Fishes, Shark, SharkPos);

	cout << MaxEatenFish;
	return 0;
}
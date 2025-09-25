#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ������ ���� �ݽð�, 0�� �Ⱦ��� ��
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1 };

// �� ���� �������� �ݺ� : ���� ���̻� �̵��� ĭ�� ������ ���� ����

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
	// ���� ��� ��ġ(= num == SHARK_NUM) ã��
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

	// ����� 1������ 16������ ������� �̵�
	for (int target = 1; target <= 16; ++target) {
		int x = -1, y = -1;

		// ���� ���忡�� target ����� ��ġ ã�� (�̹� �������� �н�)
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (Fishes[i][j].num == target) { x = i; y = j; }
			}
		}
		if (x == -1) continue; // ������

		int dir = Fishes[x][y].dir;

		// �ִ� 8�� ȸ���ϸ� �̵� �õ�
		for (int k = 0; k < 8; ++k) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// ���� �� & ��� �ڸ� �ƴ�
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !(nx == sx && ny == sy)) {
				// ��ĭ�̵�(0) �ٸ� ������ ������� swap
				swap(Fishes[x][y], Fishes[nx][ny]);
				// �̵���(= target) ������� ������ ȸ���� dir�� ������Ʈ
				Fishes[nx][ny].dir = dir;

				// �� ��� swap�� ���� �־��ٸ� sx,sy�� �����ؾ� ������
				// �� ���ǿ��� (nx,ny)�� �� �ƴ� ���� ���������Ƿ� �ʿ� ����.
				break;
			}

			// �ݽð� ȸ��
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

			// ���� ��� ��ġ�� ����.
			Fishes[SharkPos.first][SharkPos.second] = Blink;

			// ��� ��ġ�� ������ �ش� ����� ������ ��ü
			SharkPos = { x, y };
			Shark.dir = fish.dir;

			// �� �̵��ϰ� �ش� ����⸦ ���ش�.
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

	// ��� ������ �ش� ����� ������ ��ü
	Shark.dir = eatenFish.dir;

	// �� �̵��ϰ� �ش� ����⸦ ���ش�.
	Fishes[0][0] = Shark;

	dfs(1, eatenNum, Fishes, Shark, SharkPos);

	cout << MaxEatenFish;
	return 0;
}
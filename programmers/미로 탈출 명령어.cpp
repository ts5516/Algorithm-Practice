#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

char dir[4] = { 'd', 'l', 'r', 'u'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

vector<vector<int>> board;
string result = "";

bool dfs(int depth, string path, int n, int m, int x, int y, int r, int c, int k) {
	if (depth == k) {
		if (x == r && y == c && result == "") {
			result = path;
			return true;
		}
		return false;
	}

	int remain = k - depth;
	for (int i = 0;i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int dist = abs(nx - r) + abs(ny - c);
		

		if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
		if (dist > remain) continue;
		if ((remain - dist - 1) % 2 == 1) continue;

		if (dfs(depth + 1, path + dir[i], n, m, nx, ny, r, c, k)) {
			return true;
		}
	}

	return false;
}


string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "";

	board.resize(n + 1, vector<int>(m + 1));

	if (dfs(0, "", n, m, x, y, r, c, k)) {
		answer = result;
	}
	else {
		answer = "impossible";
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solution(3, 4, 2, 3, 3, 1, 5);
	return 0;
}
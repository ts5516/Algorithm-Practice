#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;
int A[501][501];
bool visited[501][501];

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			visited[i][j] = false;
		}
	}

	
	int count = 0;
	int max_width = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && A[i][j] == 1) {
				queue<pair<int, int>> que;
				que.push({ i,j });
				visited[i][j] = true;

				int width = 1;
				
				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];

						// 항상 범위를 잘 설정했는지 확인하자
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (!visited[nx][ny] && A[nx][ny] == 1) {
								que.push({ nx, ny });
								visited[nx][ny] = true;
								width++;
							}
						}
					}
				}

				count++;
				max_width = max(max_width, width);
			}
		}
	}

	cout << count << "\n" << max_width;

	return 0;
}
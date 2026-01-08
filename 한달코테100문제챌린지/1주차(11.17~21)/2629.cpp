#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 추 입력
	int n;
	cin >> n;

	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	// 구슬 입력
	int m;
	cin >> m;

	vector<int> beads(m);
	for (int i = 0; i < m; i++) {
		cin >> beads[i];
	}

	vector<vector<bool>> dp(n, vector<bool>(15001, false));
	dp[0][0] = true;
	dp[0][weights[0]] = true;

	for (int i = 1; i < n; i++) {
		dp[i][weights[i]] = true;
		for (int w = 1; w <= 15000; w++) {
			if (dp[i - 1][w]) {
				dp[i][w] = true;
				if (w + weights[i] <= 15000) {
					dp[i][w + weights[i]] = true;
				}

				dp[i][abs(w - weights[i])] = true;
			}
		}
	}

	for (int bead : beads) {
		if (bead > 15000) {
			cout << 'N' << ' ';
		}
		else if (dp[n-1][bead]) {
			cout << 'Y' << " ";
		}
		else {
			cout << 'N' << " ";
		}
	}

	return 0;
} 
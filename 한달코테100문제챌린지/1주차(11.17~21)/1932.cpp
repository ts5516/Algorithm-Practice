#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> board[i][j];
		}
	}

	dp[0][0] = board[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + board[i][0];
		dp[i][i] = dp[i - 1][i - 1] + board[i][i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j-1], dp[i - 1][j]) + board[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[n - 1][i]);
	}

	cout << result;
	return 0;
} 
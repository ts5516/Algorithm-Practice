#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int stairs[1000];
	stairs[0] = 0;
	for (int i = 1;i <= n; i++) {
		cin >> stairs[i];
	}

	vector<int> dp(n + 1);
	dp[0] = stairs[0];
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
	}

	cout << dp[n];

	return 0;
} 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end());

	vector<int> dp(k+1, INF);
	dp[0] = 0;
	for (int& coin : coins) {
		if (coin > k) continue;

		for (int i = coin; i <= k; i++) {
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	if (dp[k] == INF) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
	return 0;
} 
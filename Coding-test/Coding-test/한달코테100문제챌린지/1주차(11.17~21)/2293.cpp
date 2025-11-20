#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) {		
		cin >> coins[i];
	}

	vector<int> dp(k + 1);
	dp[0] = 1;
	for (int coin : coins) {
		for (int i = coin; i <= k; i++) {
			dp[i] += dp[i - coin];
		}
	}

	cout << dp[k];
	return 0;
} 
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> dp(1000001);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		cout << dp[n] << "\n";
	}
	return 0;
} 
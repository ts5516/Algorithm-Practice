#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> weights(N);
	vector<int> values(N);
	for (int i = 0; i < N; i++) {
		cin >> weights[i] >> values[i];
	}

	vector<int> dp(K + 1, 0);

	for (int i = 0; i < N; i++) {
		for (int k = K; k >= weights[i]; k--) {
			dp[k] = max(dp[k], dp[k - weights[i]] + values[i]);
		}
	}


	cout << dp[K];
	return 0;
} 
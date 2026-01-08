#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> ch_dp(N);
	vector<int> nch_dp(N);
	ch_dp[0] = arr[0];
	nch_dp[0] = 0;
	ch_dp[1] = arr[0] + arr[1];
	nch_dp[1] = arr[0];
	for (int i = 2; i < N; i++) {
		ch_dp[i] = max(ch_dp[i - 2] + arr[i], nch_dp[i - 2] + arr[i-1] + arr[i]);
		nch_dp[i] = max(ch_dp[i - 1], nch_dp[i - 1]);
	}

	cout << max(ch_dp[N - 1], nch_dp[N - 1]);
	return 0;
} 
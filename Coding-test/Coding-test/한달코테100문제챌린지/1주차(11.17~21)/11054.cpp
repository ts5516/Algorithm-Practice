#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<int> arr;

	cin >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> inc_dp(N);
	vector<int> dec_dp(N);
	vector<int> dp(N);

	inc_dp[0] = 1;
	for (int i = 1; i < N; i++) {
		inc_dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				inc_dp[i] = max(inc_dp[i], inc_dp[j] + 1);
			}
		}
	}

	dec_dp[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--) {
		dec_dp[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dec_dp[i] = max(dec_dp[i], dec_dp[j] + 1);
			}
		}
	}

	int result = 1;
	for (int i = 0; i < N; i++) {
		result = max(result, inc_dp[i] + dec_dp[i] - 1);
	}

	cout << result;

	return 0;
} 
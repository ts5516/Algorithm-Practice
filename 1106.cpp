#include <iostream>

using namespace std;

int c, n;

int costs[20];
int values[20];
int dp[2000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);  

	cin >> c >> n;

	for (int i = 0; i < n; i++) {
		cin >> costs[i] >> values[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= c + 100; i++) {
		dp[i] = 100000;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= c+100; j++) {
			if (j >= values[i]) {
				dp[j] = min(dp[j], dp[j - values[i]] + costs[i]);
			}
		}
	}

	int result = 1000000;
	for (int i = 0; i < 100; i++) {
		result = min(result, dp[i + c]);
	}

	cout << result;
	
	return 0;
}
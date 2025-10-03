#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> sensor(n);
	vector<int> diff(n-1);

	for (int i = 0; i < n; i++) {
		cin >> sensor[i];
	}

	sort(sensor.begin(), sensor.end());

	for (int i = 0; i < n - 1; i++) {
		diff[i] = sensor[i + 1] - sensor[i];
	}

	if (!diff.empty()) {
		sort(diff.begin(), diff.end());

		for (int i = 0; i < k - 1; i++) {
			diff.pop_back();
		}
	}
	

	int result = 0;
	for (int d : diff) {
		result += d;
	}

	cout << result;

	return 0;
} 
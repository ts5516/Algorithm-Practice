#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getInstalledWifi(vector<int>& houses, int dist) {
	int count = 1;
	int pre = houses[0];

	for (int& house : houses) {
		if (house - pre >= dist) {
			pre = house;
			count++;
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;
	
	vector<int> houses(n);
	for (int i = 0; i < n; i++) {
		cin >> houses[i];
	}

	sort(houses.begin(), houses.end());

	int left = 1;
	int right = houses[n - 1];

	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		int count = getInstalledWifi(houses, mid);
		if (count >= c) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
} 
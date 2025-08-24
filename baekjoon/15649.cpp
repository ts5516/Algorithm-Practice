#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> arr;

int result = 0;
void dfs(int index, int sum, vector<int> arr1) {
	if (index >= 1 && sum == s) {
		result++;
	}

	if (index >= n) {
		return;
	}

	for (int i = index; i < n; i++) {
		sum += arr[i];
		arr1.push_back(arr[i]);

		dfs(i + 1, sum, arr1);

		sum -= arr[i];
		arr1.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> arr1;
	dfs(0, 0, arr1);

	cout << result;

	return 0;
}
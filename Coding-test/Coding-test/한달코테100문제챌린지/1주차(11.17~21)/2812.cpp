#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	string input;
	cin >> input;

	vector<char> st;
	st.reserve(N);

	for (char c : input) {
		while (!st.empty() && K > 0 && st.back() < c) {
			st.pop_back();
			K--;
		}

		st.push_back(c);
	}

	while (K > 0) {
		st.pop_back();
		K--;
	}

	for (char c : st) cout << c;

	return 0;
} 
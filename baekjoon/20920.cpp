#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> words;
	
	int n, m;
	cin >> n >> m;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str.size() >= m) {
			words[str]++;
		}
	}

	vector<pair<string, int>> vwords;
	for (auto& word : words) {
		vwords.push_back(word);
	}

	sort(vwords.begin(), vwords.end(), [](pair<string, int> a, pair<string, int> b) {
		if (a.second == b.second) {
			if (a.first.size() == b.first.size()) {
				return a.first < b.first;
			}
			return a.first.size() > b.first.size();
		}
		return a.second > b.second;
		});

	for (auto& vword : vwords) {
		cout << vword.first << "\n";
	}

	return 0;
} 
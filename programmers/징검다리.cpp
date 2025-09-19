#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getToRemoveRock(vector<int>& rocks, int dist) {
	int pre = 0; // 시작 지점

	int removeCount = 0;
	for (int& rock : rocks) {
		if (rock - pre < dist) {
			removeCount++;
		}
		else {
			pre = rock;
		}
	}

	return removeCount;
}

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;

	sort(rocks.begin(), rocks.end());

	vector<int> positions = rocks;
	positions.push_back(distance);

	int left = 1;
	int right = distance;

	while (left <= right) {
		int mid = (left + right) / 2;

		int count = getToRemoveRock(positions, mid);

		if (count <= n) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}

		if (left == right) {
			break;
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solution(25, { 2, 14, 11, 21, 17 }, 2);
	return 0;
} 
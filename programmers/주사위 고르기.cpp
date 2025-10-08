#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> getSums(vector<vector<int>> dice, vector<int> index) {
    vector<int> result = { 0 };

    for (int i : index) {
        vector<int> new_sum;
        for (int r : result) {
            for (int d : dice[i]) {
                new_sum.push_back(r + d);
            }
        }
        result = move(new_sum);
    }

    return result;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;

    int n = dice.size();
    int half = n / 2;
    vector<int> compMask(n, 0);
    fill(compMask.end() - half, compMask.end(), 1);

    long long maxWinCount = 0;
    do {
        vector<int> compA;
        vector<int> compB;
        for (int i = 0;i < n; i++) {
            compMask[i] ? compA.push_back(i) : compB.push_back(i);
        }

        vector<int> sumA = getSums(dice, compA);
        vector<int> sumB = getSums(dice, compB);

        sort(sumB.begin(), sumB.end());

        long long winCount = 0;
        for (int& sa : sumA) {
            int count = lower_bound(sumB.begin(), sumB.end(), sa) - sumB.begin();

            winCount += count;
        }

        if (maxWinCount < winCount) {
            maxWinCount = winCount;
            for (int& a : compA) {
                a++;
            }
            cout << compA[0];
            answer = compA;
        }
    } while (next_permutation(compMask.begin(), compMask.end()));

    return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    solution({ {1,2,3,4,5,6},{2,2,4,4,6,6} });
	return 0;
}
#include <iostream>

using namespace std;

int n;
int arr[100][100];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Please write your code here.
    int count = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i - 1][j] == 0) {
                arr[i][j] ^= 1;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        arr[nx][ny] ^= 1;
                    }
                }
                count++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << count;

    return 0;
}

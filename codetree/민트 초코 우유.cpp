#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<char>> F;
vector<vector<int>> B;

int FoodGroups[8] = { 0, 3, 2, 4, 1, 5,6,7 };
struct Pos {
    int r;
    int c;
};
inline int groupRank(int mask) {
    // ����(1,2,4) -> 0,  ����(3,5,6) -> 1,  ����(7) -> 2
    if (mask == 1 || mask == 2 || mask == 4) return 0;
    if (mask == 3 || mask == 5 || mask == 6) return 1;
    return 2; // 7
}

bool compare(const Pos& a, const Pos& b) {
    int fa = F[a.r][a.c], fb = F[b.r][b.c];
    int ga = groupRank(fa), gb = groupRank(fb);

    if (ga != gb) return ga < gb;                          // �׷� ��: ���� -> ���� -> ����
    if (B[a.r][a.c] != B[b.r][b.c]) return B[a.r][a.c] > B[b.r][b.c]; // ���� �׷�: B ��������
    if (a.r != b.r) return a.r < b.r;                      // �� ��������
    return a.c < b.c;                                      // �� ��������
}


int main() {
    // �ʱ� �Է�
    int N, T;
    cin >> N >> T;

    F.assign(N, vector<char>(N));
    B.assign(N, vector<int>(N, 0));

    // ��Ʈ : 4(100), ���� : 2(010), ���� : 1(001)
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++) {
            switch (line[j]) {
            case 'T':
                F[i][j] = 4;
                break;
            case 'C':
                F[i][j] = 2;
                break;
            case 'M':
                F[i][j] = 1;
                break;
            default:
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    // �� �Ʒ� ���� ������
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    // T��° ������ �ݺ��Ѵ�.
    int day = 1;
    while (day <= T) {
        // ��ħ�ð�
        // ��� �л��� Bij���� +1
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] += 1;
            }
        }

        // ���ɽð� 
        // �׷� ����
        // B array: �žӽ� �迭 ��ǥ�ڴ� Brc ����ũ�� rc�� �������� ���
        // ��ǥ�� += �׷���� -1 / �׷�� -= 1
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        queue<Pos> que;
        vector<Pos> leaders;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    // �湮���� �ʾ����� �׷�����
                    visited[i][j] = true;
                    que.push({ i,j });

                    vector<Pos> group;
                    group.push_back({ i,j });
                    Pos leader = { i,j };

                    int Food = F[i][j];
                    while (!que.empty()) {
                        int r = que.front().r;
                        int c = que.front().c;
                        que.pop();

                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                                if (!visited[nr][nc] && F[nr][nc] == Food) {
                                    visited[nr][nc] = true;
                                    que.push({ nr,nc });
                                    group.push_back({ nr,nc });

                                    if (B[leader.r][leader.c] < B[nr][nc]) {
                                        leader = { nr,nc };
                                    }
                                    else if (B[leader.r][leader.c] == B[nr][nc]) {
                                        if (leader.r > nr) {
                                            leader = { nr, nc };
                                        }
                                        else if (leader.r == nr) {
                                            if (leader.c > nc) {
                                                leader = { nr, nc };
                                            }
                                            // leader�� nr, nc ���� ������ �Ȱ��� ���� ����
                                        }
                                    }
                                }
                            }
                        }
                    }

                    // �žӽ� �й�
                    for (auto& pos : group) {
                        B[pos.r][pos.c] -= 1;
                    }
                    B[leader.r][leader.c] += group.size();

                    leaders.push_back(leader);
                }
            }
        }

        // ���� �ð�
        // ��ǥ�ڵ��� �ž��� �����Ѵ�
        // ��ǥ�� ���� ����
        vector<vector<bool>> given(N, vector<bool>(N, false));

        sort(leaders.begin(), leaders.end(), compare);

        for (auto& leader : leaders) {
            if (given[leader.r][leader.c]) continue;

            int dir = B[leader.r][leader.c] % 4;
            int give = B[leader.r][leader.c] - 1;
            B[leader.r][leader.c] = 1;
            int Food = F[leader.r][leader.c];
            int r = leader.r + dr[dir];
            int c = leader.c + dc[dir];

            while (r >= 0 && r < N && c >= 0 && c < N && give > 0) {
                // ���� �����Ѵ�!!!
                if (Food != F[r][c]) {
                    if (give > B[r][c]) {
                        // ���� ����
                        int y = B[r][c];
                        give -= y + 1;
                        B[r][c] = y + 1;
                        F[r][c] = Food;
                    }
                    else {
                        F[r][c] |= Food;
                        B[r][c] += give;
                        give = 0;
                    }
                    given[r][c] = true;
                }

                r += dr[dir];
                c += dc[dir];
            }            
        }

        // �Ϸ簡 ������ ��� �� �������� �̵�
        day++;
        // 7 6 5 3 4 2 1 ������ ���
        int Foods[8] = {0,0,0,0,0,0,0,0};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Foods[F[i][j]] += B[i][j];
            }
        }

        cout << Foods[7] << " " << Foods[6] << " "
            << Foods[5] << " " << Foods[3] << " "
            << Foods[1] << " " << Foods[2] << " "
            << Foods[4] << "\n";
        
    }

    return 0;
}
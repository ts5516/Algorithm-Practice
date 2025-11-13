#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상 하 좌 우 우선순위에 맞춰서
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int mdx[4][3] = { {-1,-1,-1},{1,1,1},{-1,0,1}, {-1,0,1} };
int mdy[4][3] = { {-1,0,1},{-1,0,1},{} };

int warrior_move_length_sum = 0;
int rocked_warrior_num = 0;
int attacked_warrior_num = 0;


const int MAEDUSA = 5;
const int WARRIOR = 7;
const int GOAL = 9;

struct Maedusa {
    int sr;
    int sc;
    int er;
    int ec;

    vector<pair<int, int>> path;
    int cur = 0;
};

struct Warrior {
    bool isRocked = false;
    bool isDied = false;
    int r;
    int c;
};

Maedusa maedusa;
vector<Warrior> warriors;

vector<pair<int, int>> getPathToPark(const Maedusa& maedusa, const vector<vector<int>>& board) {
    const int N = board.size();

    vector<vector<vector<pair<int, int>>>> path(N, vector<vector<pair<int, int>>>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> que;
    que.push({ maedusa.sr, maedusa.sc });
    visited[maedusa.sr][maedusa.sc] = true;
    path[maedusa.sr][maedusa.sc].push_back({ maedusa.sr, maedusa.sc });

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if (board[x][y] == GOAL) {
            return path[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[nx][ny] && board[nx][ny] != 1) {
                    visited[nx][ny] = true;
                    path[nx][ny] = path[x][y];
                    path[nx][ny].push_back({ nx, ny });
                    que.push({ nx, ny });
                }
            }
        }
    }

    return path[maedusa.er][maedusa.ec];
}

// 1. 메두사의 이동
// 도로를 따라 한 칸 이동 공원까지
// 이동한 칸에 전사가 있으면 전사 공격
// 여러 최단경로가 가능하면 상 하 좌 우 우선순위 따름, 없을수도 있다
void MaedusaMove(vector<vector<int>>& board) {
    auto cur = maedusa.path[maedusa.cur];

    if (board[cur.first][cur.second] == GOAL) {
        return;
    }

    int next = maedusa.cur + 1;
    auto nextP = maedusa.path[next];

    if (board[nextP.first][nextP.second] == WARRIOR) {
        for (auto& warrior : warriors) {
            if (warrior.r == nextP.first && warrior.c == nextP.second) {
                warrior.isDied = true;
            }
        }
    }

    maedusa.cur = next;
}


// 2. 메두사의 시선
// 상 하 좌 우 선택해 바라본다
// 시선방향 대각선으로 해서 바라본다
// 이때 다른 전사에게 가려진 전사는 보이지 않는다
void MaedusaEyeline() {
    for (int i = 0; i < 4; i++) {
        getWarriorsFromDir(i);
    }
}


// N x N 배열, 도로 0, 도로가 아닌곳 1
// 메두사 집 (Sr, Sc), 공원 (Er, Ec) 
// BFS(getPathToPark) : 메두사는 도로만을 사용해 공원으로 최단 경로 이동

// 전사 M명, 각각 (ri, ci)에 위치
// BFS : 메두사를 향해 최단경로 이동 이때 도로, 비도로 구분없이 이동
int main() {
    int N, M;
    cin >> N >> M;
    cin >> maedusa.sr >> maedusa.sc >> maedusa.er >> maedusa.ec;

    warriors.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> warriors[i].r >> warriors[i].c;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    board[maedusa.sr][maedusa.sc] = MAEDUSA;
    board[maedusa.er][maedusa.ec] = GOAL;

    vector<pair<int, int>> path;
    path = getPathToPark(maedusa, board);
    if (path.empty()) {
        cout << -1;
        return 0;
    }

    maedusa.path = path;

    /*for (int i = 0; i < path.size(); i++) {
        int x = path[i].first;
        int y = path[i].second;

        board[x][y] = 3;
    }

    cout << "Maedusa Path\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/

  /*  for (int i = 0; i < M; i++) {
        board[warriors[i].r][warriors[i].c] = WARRIOR;
    }*/

    return 0;
}
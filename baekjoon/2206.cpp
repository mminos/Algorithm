#include <bits/stdc++.h>
using namespace std;

typedef struct {
        int x;
        int y;
        int cnt;
        bool pos;
} DEF;

queue<DEF> bfs;
int N, M, MIN = INT_MAX;
char arr[1000][1000];
bool visited[2][1000][1000];

int main(void) {
        scanf("%d %d\n", &N, &M);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                        scanf("%c", &arr[i][j]);
                getchar();
        }
        N--, M--;

        bfs.push({0, 0, 1, true});
        visited[1][0][0] = true;

        while (!bfs.empty()) {
                auto a = bfs.front();
                int x  = a.x, y = a.y, cnt = a.cnt;
                bool pos = a.pos;
                bfs.pop();

                if (x == N && y == M) {
                        MIN = min(MIN, cnt);
                        continue;
                }

                if (cnt > MIN) continue;

                if (x > 0 && !visited[pos][x - 1][y]) {
                        if (arr[x - 1][y] == '1' && pos) {
                                visited[pos][x - 1][y] = true;
                                bfs.push({x - 1, y, cnt + 1, false});
                        }
                        else if (arr[x - 1][y] == '0') {
                                visited[pos][x - 1][y] = true;
                                bfs.push({x - 1, y, cnt + 1, pos});
                        }
                }
                if (y > 0 && !visited[pos][x][y - 1]) {
                        if (arr[x][y - 1] == '1' && pos) {
                                visited[pos][x][y - 1] = true;
                                bfs.push({x, y - 1, cnt + 1, false});
                        }
                        else if (arr[x][y - 1] == '0') {
                                visited[pos][x][y - 1] = true;
                                bfs.push({x, y - 1, cnt + 1, pos});
                        }
                }
                if (x < N && !visited[pos][x + 1][y]) {
                        if (arr[x + 1][y] == '1' && pos) {
                                if (x + 1 != N || y != M) visited[pos][x + 1][y] = true;
                                bfs.push({x + 1, y, cnt + 1, false});
                        }
                        else if (arr[x + 1][y] == '0') {
                                if (x + 1 != N || y != M) visited[pos][x + 1][y] = true;
                                bfs.push({x + 1, y, cnt + 1, pos});
                        }
                }
                if (y < M && !visited[x][y + 1]) {
                        if (arr[x][y + 1] == '1' && pos) {
                                if (x != N || y + 1 != M) visited[pos][x][y + 1] = true;
                                bfs.push({x, y + 1, cnt + 1, false});
                        }
                        else if (arr[x][y + 1] == '0') {
                                if (x != N || y + 1 != M) visited[pos][x][y + 1] = true;
                                bfs.push({x, y + 1, cnt + 1, pos});
                        }
                }
        }
        if (MIN == INT_MAX) printf("-1");
        else printf("%d", MIN);
        
        return 0;
}

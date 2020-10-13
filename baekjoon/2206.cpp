#include <bits/stdc++.h>
using namespace std;

typedef struct {
        int x;
        int y;
        int cnt;
        int block;
} DEF;

queue<DEF> bfs;
int M, N, MIN = INT_MAX;
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
bool visited[1001][1001][2];
char graph[1001][1001];

int main(void) {
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++)
                scanf("%s", &graph[i][1]);
        
        bfs.push({1, 1, 1, 1});
        visited[1][1][1] = true;
        while (!bfs.empty()) {
                auto a = bfs.front();
                int x = a.x, y = a.y, cnt = a.cnt, block = a.block;
                bfs.pop();

                if (x == N && y == M) {
                        MIN = min(MIN, cnt);
                        break;
                }

                for (int i = 0; i < 4; i++) {
                        int nx = x + moveX[i];
                        int ny = y + moveY[i];

                        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                                if (graph[nx][ny] == '1' && block) {
                                        visited[nx][ny][block - 1] = true;
                                        bfs.push({nx, ny, cnt + 1, block - 1});
                                }

                                if (graph[nx][ny] == '0' && visited[nx][ny][block] == false) {
                                        visited[nx][ny][block] = true;
                                        bfs.push({nx, ny, cnt + 1, block});
                                }
                        }
                }
        }

        if (MIN == INT_MAX) printf("-1");
        else printf("%d", MIN);
}
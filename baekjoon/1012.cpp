#include <bits/stdc++.h>
using namespace std;

int T, M, N, K;
int x, y, cnt;
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, -1, 1};
int arr[51][51];
bool visited[51][51];
queue<pair<int, int>> bfs;

int main(void) {
        scanf("%d", &T);
        while (T--) {
                cnt = 0;
                memset(arr, 0, sizeof(arr));
                memset(visited, 0, sizeof(visited));
                scanf("%d %d %d", &M, &N, &K);
                for (int i = 0; i < K; i++) {
                        scanf("%d %d", &x, &y);
                        arr[y][x] = 1;                 
                }

                for (int i = 0; i < N; i++) {
                        for (int j = 0; j < M; j++) {
                                if (arr[i][j] == 1 && !visited[i][j]) {
                                        bfs.push({i, j});
                                        while (!bfs.empty()) {
                                                auto a = bfs.front();
                                                bfs.pop();
                                                y = a.first, x = a.second;

                                                for (int k = 0; k < 4; k++) {
                                                        int nx = x + moveX[k];
                                                        int ny = y + moveY[k];

                                                        if (nx >= 0 && nx < M && ny >= 0 && ny < N && arr[ny][nx] == 1 && !visited[ny][nx]) {
                                                                visited[ny][nx] = true;
                                                                bfs.push({ny, nx});
                                                        }
                                                }
                                        }
                                        cnt++;
                                }  
                        }
                }
                printf("%d\n", cnt);
        }
        return 0;
}
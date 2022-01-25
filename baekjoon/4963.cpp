#include <bits/stdc++.h>
using namespace std;

bool visited[55][55];
int arr[55][55];
int moveX[8] = {-1, -1, -1,  0,  1,  1,  1,  0};
int moveY[8] = {-1,  0,  1,  1,  1,  0, -1, -1};
queue<pair<int, int>> q;

int main(void) {
        while (1) {
                int w, h, cnt = 0;

                scanf("%d %d", &w, &h);
                
                if (w == 0 && h == 0) break;

                memset(visited, 0, sizeof(visited));

                for (int i = 0; i < h; i++)
                        for (int j = 0; j < w; j++)
                                scanf("%d", &arr[i][j]);
                
                for (int i = 0; i < h; i++)
                        for (int j = 0; j < w; j++) {
                                if (arr[i][j] == 0 || visited[i][j]) continue;
                                
                                q.push({i, j});
                                visited[i][j] = true;
                                cnt++;

                                while (!q.empty()) {
                                        int x = q.front().first, y = q.front().second; q.pop();

                                        for (int idx = 0; idx < 8; idx++) {
                                                int nx = x + moveX[idx];
                                                int ny = y + moveY[idx];

                                                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                                                if (visited[nx][ny] || arr[nx][ny] == 0) continue;

                                                q.push({nx, ny});
                                                visited[nx][ny] = true;
                                        }
                                }
                        }
                printf("%d\n", cnt);
        }

        return 0;
}
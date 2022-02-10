#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
bool choose[10][10];
int moveX[4] = {1, 0, 0, -1};
int moveY[4] = {0, 1, -1, 0};
int n, m;
int safe, res;
vector<pair<int, int>> v;

void bfs(void) {
        queue<pair<int, int>> q;
        int tmp[10][10];
        bool visited[10][10];
        int cnt = 0;

        memcpy(tmp, arr, sizeof(tmp));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < 3; i++) {
                int x = v[i].first;
                int y = v[i].second;

                tmp[x][y] = 1;
        }

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                        if (tmp[i][j] != 2) continue;
                        if (visited[i][j]) continue;

                        q.push({i, j});
                        visited[i][j] = true;

                        while (!q.empty()) {
                                int x = q.front().first, y = q.front().second;
                                q.pop();

                                for (int k = 0; k < 4; k++) {
                                        int nx = x + moveX[k];
                                        int ny = y + moveY[k];

                                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                                        if (visited[nx][ny]) continue;
                                        if (tmp[nx][ny] == 1) continue;

                                        q.push({nx, ny});
                                        visited[nx][ny] = true;
                                        if (tmp[nx][ny] == 0)
                                                cnt++;
                                }
                        }
                }
        
        res = max(safe - cnt, res);
}

void dfs(int cnt) {
        if (cnt == 3) {
                bfs();
                return;
        }

        for (int i = 0; i < n; i++) 
                for (int j = 0; j < m; j++) {
                        if (arr[i][j] != 0) continue;
                        if (choose[i][j]) continue;

                        choose[i][j] = true;
                        v.push_back({i, j});
                        dfs(cnt + 1);
                        v.pop_back();
                        choose[i][j] = false;
                }
}

int main(void)
{
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                        scanf("%d", &arr[i][j]);
                        if (arr[i][j] == 0) safe++;
                }
        
        safe -= 3;
        dfs(0);

        printf("%d", res);
}
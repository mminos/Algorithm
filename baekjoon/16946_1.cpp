#include <bits/stdc++.h>
using namespace std;

int arr[1000][1000];
bool visited[1000][1000];
bool visited_idx[1000000];
int moveX[4] = {1, 0, 0, -1};
int moveY[4] = {0, 1, -1, 0};

int n, m;
int idx = 2;
vector<int> v(2);
queue<pair<int, int>> q;
int main(void)
{
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        scanf("%1d", &arr[i][j]);
        
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                        if (arr[i][j] != 0 || visited[i][j])
                                continue;
                        
                        int flag = idx++;
                        int cnt = 0;

                        arr[i][j] = flag;
                        q.push({i, j});
                        visited[i][j] = true;
                        cnt++;

                        while (!q.empty()) {
                                int x = q.front().first, y = q.front().second;
                                q.pop();

                                for (int k = 0; k < 4; k++) {
                                        int nx = x + moveX[k];
                                        int ny = y + moveY[k];

                                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                                        if (visited[nx][ny]) continue;
                                        if (arr[nx][ny] == 1) continue;

                                        arr[nx][ny] = flag;
                                        q.push({nx, ny});
                                        visited[nx][ny] = true;
                                        cnt++;
                                }
                        }
                        v.push_back(cnt);
                }
        
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        if (arr[i][j] != 1) {
                                printf("0");
                                continue;
                        }

                        int res = 1;
                        vector<int> vv;

                        for (int k = 0; k < 4; k++) {
                                int nx = i + moveX[k];
                                int ny = j + moveY[k];

                                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                                if (arr[nx][ny] == 1) continue;
                                auto it = find(vv.begin(), vv.end(), arr[nx][ny]);
                                if (it == vv.end()) {
                                        res += v[arr[nx][ny]];
                                        vv.push_back(arr[nx][ny]);
                                }
                        }
                        printf("%d", res % 10);
                }
                printf("\n");
        }

        return 0;
}
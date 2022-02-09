#include <bits/stdc++.h>
using namespace std;

char graph[1000][1000];
int graph_i[1000][1000];
bool visited[1000][1000];
int moveX[4] = {1, 0, 0, -1};
int moveY[4] = {0, 1, -1, 0};
queue<pair<int, int>> q;
int cnt;
int n, m;
int idx = 1;

int main(void)
{
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
                scanf("%s", graph[i]);
        
        for (int i = 0 ; i < n; i++) for(int j = 0; j < m; j++) graph_i[i][j] = graph[i][j] - 48;

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                        if (graph_i[i][j] == 1 || visited[i][j]) continue;

                        int flag = idx++;

                        graph_i[i][j] = flag;
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
                                        if (graph_i[nx][ny] == 1) continue;

                                        graph_i[nx][ny] = flag;
                                        
                                }
                        }
                }
}
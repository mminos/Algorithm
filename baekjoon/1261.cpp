#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> algospot;

char miro[101][101];
int visited[101][101];
priority_queue<algospot, vector<algospot>, greater<algospot>>pq;

int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};

int main(void) 
{
        int n, m, res = INT_MAX;
        char arr[101];
        scanf("%d %d", &m, &n);
        
        for (int i = 0; i < n; i++) {
                scanf("%s", arr);
                for (int j = 0; j < m; j++)
                        miro[i][j] = arr[j];        
        }

        pq.push({0, {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
                int cnt = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
                pq.pop();

                if (x == n - 1 && y == m - 1) {
                        res = cnt;
                        break;
                }

                for (int i = 0; i < 4; i++) {
                        int nx = x + moveX[i];
                        int ny = y + moveY[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visited[nx][ny]) continue;

                        if (miro[nx][ny] == '1')
                                pq.push({cnt + 1, {nx, ny}});
                        else
                                pq.push({cnt, {nx, ny}});
                        
                        visited[nx][ny] = true;
                }
        }
        printf("%d", res);
}
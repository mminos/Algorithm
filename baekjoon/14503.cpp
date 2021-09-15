#include <bits/stdc++.h>
using namespace std;

int arr[50][50];
bool visited[50][50];
int distX[4] = {-1, 0, 1, 0};   // 0 ~ 3 북 동 남 서
int distY[4] = {0, 1, 0, -1};
int d;                       // 0 ~ 3 북 동 남 서
int N, M;
int cnt;

void dfs(int x, int y, int dist) {
        if (!visited[x][y]) {
                visited[x][y] = true;
                cnt++;
        }

        for (int i = 0; i < 4; i++) {
                int nd = (dist + 3 - i) % 4;
                int nx = x + distX[nd];
                int ny = y + distY[nd];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                        continue;
                
                if (arr[nx][ny] == 0 && !visited[nx][ny])
                        dfs(nx, ny, nd);
        }

        int nd = (dist + 2) % 4;
        int nx = x + distX[nd];
        int ny = y + distY[nd];

        if (arr[nx][ny] == 1) {
                printf("%d", cnt);
                exit(0);
        }
        dfs(nx, ny, dist);
}

int main(void) {
        int x, y;
        scanf("%d %d", &N, &M);
        scanf("%d %d %d", &x, &y, &d);
        for (int i = 0; i < N; i ++) {
                for (int j = 0; j < M; j++) {
                        scanf("%d", &arr[i][j]);
                }
        }

        dfs(x, y, d);

        printf("%d", cnt);
        return 0;
}
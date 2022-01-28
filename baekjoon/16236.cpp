#include <bits/stdc++.h>
using namespace std;

typedef struct move {
        int x;
        int y;
        int cnt;
}_move;

int shark[20][20];
int dist[20][20];
int moveX[4] = {1, 0, 0, -1};
int moveY[4] = {0, 1, -1, 0};
int n, shark_x, shark_y, shark_size = 2;
int eaten, min_dist;
int res;

bool find_fish(_move);

int main(void)
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                        scanf("%d", &shark[i][j]);
                        if (shark[i][j] == 9) {
                                shark_x = i;
                                shark_y = j;
                                shark[i][j] = 0;
                        }
                }
        _move start = {shark_x, shark_y, 0};
        
        while (find_fish(start)) {
                bool chk = true;
                for (int i = 0; i < n && chk; i++)
                        for (int j = 0; j < n && chk; j++) {
                                if (dist[i][j] == min_dist) {
                                        eaten++;

                                        if (eaten == shark_size) {
                                                shark_size++;
                                                eaten = 0;
                                        }

                                        start.x = i;
                                        start.y = j;
                                        start.cnt = 0;
                                        shark[i][j] = 0;
                                        res += min_dist;
                                        chk = false;
                                }
                        }
        }
        printf("%d", res);
        return 0;
}

bool find_fish(_move start) {
        bool visited[20][20];
        queue<_move> q;
        min_dist = 9999;

        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        q.push(start);
        visited[start.x][start.y] = true;

        while (!q.empty()) {
                int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
                q.pop();

                int fishsize = shark[x][y];

                if (fishsize > 0 && fishsize != 9 && fishsize < shark_size) {
                        min_dist = min(min_dist, cnt);
                        dist[x][y] = cnt;
                }

                for (int i = 0 ; i < 4; i++) {
                        int nx = x + moveX[i];
                        int ny = y + moveY[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (visited[nx][ny]) continue;
                        if (shark[nx][ny] > shark_size) continue;

                        q.push({nx, ny, cnt + 1});
                        visited[nx][ny] = true;
                }
        }
        if (min_dist == 9999) return false;
        else return true;
}
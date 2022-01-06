#include <bits/stdc++.h>
using namespace std;

typedef struct {
        int x;
        int y;
        int count;
}knight;

queue<knight> q;
bool visited[301][301];
int moveX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int T, I, x, y, res;


int main(void)
{
        scanf("%d", &T);
        while (T--) {           
                knight k;   
                scanf("%d", &I);
                scanf("%d %d", &k.x, &k.y);
                k.count = 0;
                scanf("%d %d", &x, &y);

                res = 0;
                memset(visited, 0, sizeof(visited));
                while (!q.empty()) q.pop();

                q.push(k);

                while (!q.empty()) {
                        knight tmp = q.front();
                        q.pop();
                        
                        if (x == tmp.x && y == tmp.y) {
                                res = tmp.count;
                                break;
                        }

                        for (int i = 0; i < 8; i++) {
                                int nx = tmp.x + moveX[i];
                                int ny = tmp.y + moveY[i];
                                int ncnt = tmp.count + 1;

                                if (nx < 0 || ny < 0 || nx >= I || ny >= I || 
                                 visited[nx][ny]) 
                                        continue;

                                visited[nx][ny] = true;
                                q.push({nx, ny, ncnt});
                        }
                }
                printf("%d\n", res);
        }

        return 0;
}
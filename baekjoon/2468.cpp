#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, -1, 1};

int arr[100][100];
bool visited[100][100];
bool height[101];
int N, res;

int main(void) {
        scanf("%d", &N);
        for (int i = 0 ; i < N; i++) 
                for(int j = 0; j < N; j++) {
                        scanf("%d", &arr[i][j]);
                        height[arr[i][j]] = true;
                }
        res = 1;

        for(int h = 1; h <= 100; h++) {
                if (!height[h]) continue;

                memset(visited, 0, sizeof(visited));
                int cnt = 0;

                for (int i = 0; i < 100; i++) {
                        for (int j = 0; j < 100; j++) {
                                if (visited[i][j] || arr[i][j] <= h) continue;
                                
                                q.push({i, j}), visited[i][j] = true, cnt++;
                                
                                while (!q.empty()) {
                                        auto a = q.front();
                                        q.pop();
                                        int x = a.first;
                                        int y = a.second;

                                        for (int n = 0; n < 4; n++) {
                                                int nx = x + moveX[n];
                                                int ny = y + moveY[n];

                                                if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && arr[nx][ny] > h && !visited[nx][ny]) {
                                                        q.push({nx, ny});
                                                        visited[nx][ny] = true;
                                                }
                                        }
                                }
                        }
                }

                if (res < cnt) res = cnt;                
        }
        
        printf("%d", res);
        return 0;
}
#include <bits/stdc++.h>
using namespace std;

int nextX[4] = {1, 0, -1, 0};
int nextY[4] = {0, 1, 0, -1};
int arr[10][10];
int res[10];
int visited[10][10];
int N, M, K, _max = INT_MIN;

void back(int x, int y, int cnt)
{
        if (cnt == K) {
                int sum = 0;
                for (int i = 0; i < cnt; i++) 
                        sum += res[i];
                _max = max(_max, sum);
                return;
        }
        
        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                        if (!visited[i][j]) {
                                visited[i][j]++;
                                for (int k = 0; k < 4; k++) {
                                        int nx = i + nextX[k];
                                        int ny = j + nextY[k];

                                        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                                                visited[nx][ny]++;
                                }
                                res[cnt] = arr[i][j];
                                back(i, j, cnt + 1);

                                visited[i][j]--;

                                for (int k = 0; k < 4; k++) {
                                        int nx = i + nextX[k];
                                        int ny = j + nextY[k];

                                        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                                                visited[nx][ny]--;
                                }
                        }
                }
}

int main(void)
{
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        scanf("%d", &arr[i][j]);

        back(0, 0, 0);
        printf("%d\n", _max);

        return 0;
}
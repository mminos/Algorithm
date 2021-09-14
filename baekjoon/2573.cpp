#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int arr[300][300];
bool visited[300][300];
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, -1, 1}; 
int M, N;
int year;

void melting() {
        int melt[300][300] = {0, };

        for (int i = 1; i < N - 1; i++) {
                for (int j = 1; j < M - 1; j++) {
                        int melted = 0;

                        for (int n = 0; n < 4; n++) {
                                int ni = i + moveX[n];
                                int nj = j + moveY[n];

                                if (arr[ni][nj] == 0) melted++;
                        }

                        melt[i][j] = melted;
                }
        }

        for (int i = 1; i < N - 1; i++) {
                for (int j = 1; j < M - 1; j++) {
                        arr[i][j] -= melt[i][j];
                        if (arr[i][j] < 0) arr[i][j] = 0;
                }
        }
}

int main(void) {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        scanf("%d", &arr[i][j]);
                }
        }

        while (true) {
                memset(visited, 0, sizeof(visited));
                melting(), year++;
                int cnt = 0;
                for (int i = 1; i < N - 1; i++) {
                        for (int j = 1; j < M - 1; j++) {
                                if (visited[i][j] || arr[i][j] == 0) continue;
                                q.push({i, j}), visited[i][j] = true, cnt++;

                                while (!q.empty()) {
                                        auto a = q.front();
                                        q.pop();
                                        int x = a.first, y = a.second;

                                        for (int n = 0; n < 4; n++) {
                                                int nx = x + moveX[n];
                                                int ny = y + moveY[n];

                                                if (arr[nx][ny] > 0 && !visited[nx][ny]) {
                                                        q.push({nx, ny});
                                                        visited[nx][ny] = true;
                                                }
                                        }
                                }
                        }
                }
                if (cnt == 0) {
                        printf("0");
                        return 0;
                }
                else if (cnt > 1) {
                        printf("%d", year);
                        return 0;
                }
        }
        return 0;
}
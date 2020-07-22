#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
typedef struct type{
        int x;
        int y;
        int cnt;
} type;

queue<type> bfs;
char arr[100][100];
bool visited[100][100];
int N, M, res = INT_MAX;

int main(void) {
        scanf("%d %d", &N, &M);
        getchar();

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                        scanf("%c", &arr[i][j]);
                getchar();
        }
        N--, M--;

        bfs.push({0, 0, 1});
        while (!bfs.empty()) {
                auto a = bfs.front();
                int x = a.x, y = a.y, cnt = a.cnt;
                bfs.pop();

                if (x == N && y == M) {
                        res = min(res, cnt);
                        continue;
                } 

                if (cnt > res) continue;

                if (x + 1 < 100 && arr[x + 1][y] == '1' &&!visited[x + 1][y]) {
                        bfs.push({x + 1, y, cnt + 1});
                        visited[x + 1][y] = true;
                }
                if (y + 1 < 100 && arr[x][y + 1] == '1' && !visited[x][y + 1]) {
                        bfs.push({x, y + 1, cnt + 1});
                        visited[x][y + 1] = true;
                }
                if (x - 1 >= 0 && arr[x - 1][y] == '1' && !visited[x - 1][y]) {
                        bfs.push({x - 1, y, cnt + 1});
                        visited[x - 1][y] = true;
                }
                if (y - 1 >= 0 && arr[x][y - 1] == '1' && !visited[x][y - 1]) {
                        bfs.push({x, y - 1, cnt + 1});
                        visited[x][y - 1] = true;
                }
        }
        printf("%d", res);
        return 0;
}
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#define MAX 100000
using namespace std;

int N, K, res = INT_MAX;
queue<pair<int, int>> bfs;
bool check[100001];

int main(void) {
        scanf("%d %d", &N, &K);
      
        if (N >= K) {
                printf("%d", N - K);
                return 0;
        }

        bfs.push({N, 0});
        while (!bfs.empty()) {
                auto a = bfs.front();
                int x = a.first, cnt = a.second;
                bfs.pop();
                
                if (x == K) {
                        res = min(res, cnt);
                        continue;
                }

                if (cnt > res) continue;

                if (x > 0 && x * 2 <= MAX && !check[x * 2]) {
                        check[x * 2] = true;
                        bfs.push({x * 2, cnt + 1});
                }
                if (x + 1 <= MAX && x < K && !check[x + 1]) {
                        check[x + 1] = true;
                        bfs.push({x + 1, cnt + 1});
                }
                if (x - 1 <= MAX && x - 1 >= 0 && !check[x - 1]) {
                        check[x - 1] = true;
                        bfs.push({x - 1, cnt + 1});
                }
        }
        printf("%d", res);
        return 0;
}
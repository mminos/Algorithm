#include <bits/stdc++.h>
using namespace std;

vector<int> person[101];
queue<pair<int, int>> bfs;
bool visited[101];
int N, T;

int main(void) {
        int p1, p2, n1, n2;
        int res = -1;

        scanf("%d", &N);
        scanf("%d %d", &p1, &p2);
        scanf("%d", &T);

        for (int i = 0; i < T; i++) {
                scanf("%d %d", &n1, &n2);
                person[n1].push_back(n2);
                person[n2].push_back(n1);
        }

        bfs.push({p1, 0});
        visited[p1] = true;

        while (!bfs.empty()) {
                auto a = bfs.front();
                bfs.pop();

                int p = a.first, cnt = a.second;
                int size = person[p].size();

                if (p2 == p) {
                        res = cnt;
                        break;
                }
                if (size == 0) 
                        continue;

                for (int i = 0; i < size; i++) {
                        int tmp = person[p][i];
                        if (visited[tmp]) continue;

                        visited[tmp] = true;
                        bfs.push({tmp, cnt + 1});
                }
        }

        printf("%d", res);
        return 0;
}
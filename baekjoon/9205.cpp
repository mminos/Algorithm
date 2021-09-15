#include <bits/stdc++.h>
using namespace std;

pair<int, int> pos[105];
bool visited[105];
queue<pair<int, int>> q;
int T, N;

int main(void) {
        scanf("%d", &T);
        
        while(T--) {
                memset(visited, 0, sizeof(visited));

                scanf("%d", &N);

                for (int i = 0; i < N + 2; i++) {
                        scanf("%d %d", &pos[i].first, &pos[i].second);
                }

                q.push(pos[0]);
                visited[0] = true;

                while (!q.empty()) {
                        auto a = q.front();
                        q.pop();
                        int x = a.first;
                        int y = a.second;

                        for (int i = 0; i < N + 2; i++) {
                                if (visited[i]) continue;

                                if (abs(x - pos[i].first) + abs(y - pos[i].second) <= 1000) {
                                        q.push(pos[i]);
                                        visited[i] = true;
                                }
                        }
                }

                if (visited[N + 1]) printf("happy\n");
                else printf("sad\n");
        }

        return 0;
}
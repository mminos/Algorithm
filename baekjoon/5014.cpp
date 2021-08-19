#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D, res = INT_MAX;
int path[1000001];
bool visited[1000001];
queue<int> q;

int main(void) {
        scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
        int move[2] = {U, -1 * D};
        q.push(S);
        visited[S] = true;

        while (!q.empty()) {
                int n = q.front();
                q.pop();

                for (int i = 0; i < 2; i++) {
                        int nn = n + move[i];

                        if (nn >= 1 && nn <= F && !visited[nn]) {
                                q.push(nn);
                                visited[nn] = true;
                                path[nn] = path[n] + 1;
                        }
                }
        }

        if (visited[G]) printf("%d", path[G]);
        else printf("use the stairs");

        return 0;
}
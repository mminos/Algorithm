#include <bits/stdc++.h>
using namespace std;

bool visited[20001];
bool redblack[20001];
vector<int> nodes[20001];
queue<int> q;
int k, v, e, check;

int main(void)
{
        scanf("%d", &k);
        while (k--) {
                scanf("%d %d", &v, &e);

                for (int i = 0; i < e; i++) {
                        int x, y;
                        scanf("%d %d", &x, &y);
                        nodes[x].push_back(y);
                        nodes[y].push_back(x);
                }

                q.push(1);
                visited[1] = true;

                while (!q.empty()) {
                        int n = q.front(); q.pop();
                        int len = nodes[n].size();

                        for (int i = 0; i < len; i++) {
                                int nn = nodes[n][i];
                                if (!visited[nn]) {
                                        visited[nn] = true;
                                        redblack[nn] = !redblack[n];
                                        q.push(nn);
                                }
                        }
                }

                for (int i = 1; i <= v; i++) {
                        int len = nodes[i].size();
                        for (int j = 0; j < len; j++) {
                                int n = nodes[i][j];
                                if (redblack[i] == redblack[n])
                                        check++;
                        }
                }
                if (check)
                        printf("NO\n");
                else   
                        printf("YES\n");

                check = 0;
                for(int i = 0; i <= v; i++) {
                        nodes[i].clear();
                        visited[i] = false;
                        redblack[i] = false;
                }
        }
}
#include <bits/stdc++.h>
using namespace std;

vector<int> nodes[1001];
queue<int> q;
bool visited[1001];
int n, m, cnt;

int main(void)
{
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
                int n1, n2;
                scanf("%d %d", &n1, &n2);

                nodes[n1].push_back(n2);
                nodes[n2].push_back(n1);
        }

        for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                        cnt++;
                        q.push(i);
                        visited[i] = true;

                        while (!q.empty()) {
                                int node = q.front();
                                q.pop();

                                int len = nodes[node].size();

                                for (int j = 0; j < len; j++) {
                                        int nnode = nodes[node][j];
                                        if (!visited[nnode])
                                                q.push(nnode);
                                                visited[nnode] = true;
                                }
                        }
                }
        }
        printf("%d", cnt);
        return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> nodes[2001];
bool visited[2001];
int n, m, check;

void dfs(int cur, int cnt) {
        if (cnt == 5) {
                check++;
                return;
        }
        visited[cur] = true;

        int len = nodes[cur].size();
        
        for (int i = 0; i < len; i++) {
                int nnode = nodes[cur][i];
                if (!visited[nnode])
                        dfs(nnode, cnt + 1);
        }

        visited[cur] = false;
        
}

int main(void)
{
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
                int n1, n2;
                scanf("%d %d", &n1, &n2);
                nodes[n1].push_back(n2);
                nodes[n2].push_back(n1);
        }

        for (int i = 0; check == 0 && i < n; i++) 
                dfs(i, 1);

        if (check) printf("1");
        else printf("0");
}
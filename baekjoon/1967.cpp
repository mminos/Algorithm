#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> node[10001];
vector<int> leaf;
int n, n1, n2, w, res;

void dfs(int n, int parent, int wsum) {
        int size = node[n].size();

        if (size == 1 && parent) {
                res = max(res, wsum);
                return;
        }

        for (int i = 0; i < size; i++) {
                int nn = node[n][i].first;
                int nw = node[n][i].second;
                if (nn != parent)
                        dfs(nn, n, wsum + nw);
        }
}

int main(void)
{
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
                scanf("%d %d %d", &n1, &n2, &w);
                node[n1].push_back({n2, w});
                node[n2].push_back({n1, w});
        }

        for (int i = 1; i <= n; i++) {
                if (node[i].size() == 1)
                        leaf.push_back(i);
        }

        int len = leaf.size();
        for (int i = 0; i < len; i++) {
                dfs(leaf[i], 0, 0);
        }
        
        printf("%d\n", res);
        return 0;
}
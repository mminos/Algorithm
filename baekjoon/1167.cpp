#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> nodes[100010];
vector<int> leaf;
bool visited[100010];
int v, n, m, w, res, leaf_node;

void dfs(int node, int parent, int wsum) {
        int size = nodes[node].size();

        if (size == 1 && parent && res < wsum) {
                res = wsum;
                leaf_node = node;
                return;
        }

        for (int i = 0; i < size; i++) {
                int nn = nodes[node][i].first;
                int nw = nodes[node][i].second;
                if (nn != parent && visited[nn] == false) {
                        visited[nn] = true;
                        dfs(nn, node, wsum + nw);
                        visited[nn] = false;
                }
        }
}

int main(void)
{
        scanf("%d", &v);

        for (int i = 0; i < v; i++) {
                scanf("%d", &n);

                while (1) {
                        scanf("%d", &m);

                        if (m == -1) break;

                        scanf("%d", &w);
                        nodes[n].push_back({m, w});
                }

                if (nodes[n].size() == 1) leaf.push_back(n);
        }

        dfs(leaf[0], 0, 0);
        dfs(leaf_node, 0, 0);

        printf("%d", res);
        return 0;
}
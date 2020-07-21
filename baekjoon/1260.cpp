#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> node[1001];
vector<bool> dfs_visited(1001);
vector<bool> bfs_visited(1001);
stack<int> dfs;
queue<int> bfs;
int n, m, v;

int main(void) {        
        scanf("%d %d %d", &n, &m, &v);

        for (int i = 0; i < m; i++ ) {
                int a, b;
                scanf("%d %d", &a, &b);
                node[a].push_back(b);
                node[b].push_back(a);
        }
        for (int i = 0; i <= n; i++) {
                sort(node[i].begin(), node[i].end());
        }

        dfs.push(v);
        while (!dfs.empty()) {
                int num = dfs.top();

                if (dfs_visited[num] == true) {
                        dfs.pop();
                        continue;
                } else {
                        dfs.pop(), printf("%d ", num), dfs_visited[num] = true;
                }

                for (int i = node[num].size() - 1; i >= 0; i--) {
                        int u = node[num][i];

                        if (dfs_visited[u] == false) dfs.push(u);
                }
        } putchar('\n');

        bfs.push(v);
        while (!bfs.empty()) {
                int num = bfs.front();

                if (bfs_visited[num] == true) {
                        bfs.pop();
                        continue;
                } else {
                        bfs.pop(), printf("%d ", num), bfs_visited[num] = true;
                }

                for (int i = 0; i < node[num].size(); i++) {
                        int u = node[num][i];

                        if (bfs_visited[u] == false) bfs.push(u);
                }
        } putchar('\n');
        return 0;
}
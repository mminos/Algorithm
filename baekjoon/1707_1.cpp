#include <bits/stdc++.h>
using namespace std;

bool visited[6][20001];
bool redblack[6][20001];
vector<int> nodes[6][20001];
queue<pair<int, bool>> q;
int k, v, e, check;

int main(void)
{
        scanf("%d", &k);

        for (int idx = 0; idx < k; idx++) {
                scanf("%d %d", &v, &e);

                for (int i = 0; i < e; i++) {
                        int n1, n2;
                        scanf("%d %d", &n1, &n2);

                        nodes[idx][n1].push_back(n2);
                        nodes[idx][n2].push_back(n1);
                }

                
                for (int i = 1; i <= v; i++) {
                        if (visited[idx][i]) continue;

                        q.push({i, true});
                        visited[idx][i] = true;
                        redblack[idx][i] = true;
                        
                        while (!q.empty() && !check) {
                                auto a = q.front(); q.pop();
                                int node = a.first;
                                bool flag = a.second;
                                int len = nodes[idx][node].size();
                    
                                for (int j = 0; j < len; j++) {
                                        int nnode = nodes[idx][node][j];
                                
                                        if (visited[idx][nnode] && redblack[idx][nnode] == flag) {
                                                check++;
                                                break;
                                        }

                                        if (!visited[idx][nnode]) {
                                                q.push({nnode, !flag});
                                                visited[idx][nnode] = true;
                                                redblack[idx][nnode] = !flag;
                                        }
                                }
                        }
                }
                while (!q.empty()) q.pop();
                
                if (check) 
                        printf("NO\n");
                else    
                        printf("YES\n");
                
                check = 0;
        }
        return 0;
}
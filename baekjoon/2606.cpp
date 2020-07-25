#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M, cnt;
vector<int> nodes[101];
queue<int> bfs;
bool visited[101];

int main(void) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
                int a, b;
                
                scanf("%d %d", &a, &b);
                nodes[a].push_back(b);
                nodes[b].push_back(a);
        }
        visited[1] = true;
        bfs.push(1);
        while (!bfs.empty()) {
                int node = bfs.front();
                bfs.pop();

                for (int i = 0; i < nodes[node].size(); i++) {
                        int j = nodes[node][i];
                        if (visited[j] == false) {
                                visited[j] = true;
                                bfs.push(j);
                        }
                }
        }
        for (int i = 1; i <= N; i++)
                if (visited[i] == true) cnt++;
        
        printf("%d", cnt - 1);
        return 0;
}
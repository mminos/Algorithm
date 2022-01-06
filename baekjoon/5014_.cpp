#include <bits/stdc++.h>
using namespace std;

bool visited[1000001];
queue<pair<int, int>> q;
int F, S ,G, U, D, res;

int main(void) 
{
        scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
        visited[S] = true;
        q.push({S, 0});

        while (!q.empty()) {
                auto a = q.front();
                q.pop();

                int cur = a.first;
                int cnt = a.second;

                if (cur == G) {
                        res = cnt;
                        break;
                }

                if (cur + U <= F && !visited[cur + U]) {
                        visited[cur + U] = true;
                        q.push({cur + U, cnt + 1});
                }

                if (cur - D >= 1 && !visited[cur - D]) {
                        visited[cur - D] = true;
                        q.push({cur - D, cnt + 1});
                }
        }
        
        if (visited[G])
                printf("%d\n", res);
        else    
                printf("use the stairs\n");
        
        return 0;
}
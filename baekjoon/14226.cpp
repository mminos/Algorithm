#include <bits/stdc++.h>
using namespace std;

typedef struct emo {
        int dis;
        int clip;
        int cnt;
} emo;
queue<emo> q;
bool visited[1001][1001];
int s;

int main(void)
{
        scanf("%d", &s);
        
        q.push({1, 0, 0});
        visited[1][0] = true;

        while (!q.empty()) {
                emo tmp = q.front(); q.pop();
                int dis = tmp.dis;
                int clip = tmp.clip;
                int cnt = tmp.cnt;

                if (s == dis) {
                        printf("%d", cnt);
                        break;
                }

                if (!visited[dis][dis]) {
                        q.push({dis, dis, cnt + 1});
                        visited[dis][dis] = true;
                }

                if (dis + clip <= 1000 && !visited[dis + clip][clip]) {
                        q.push({dis + clip, clip, cnt + 1});
                        visited[dis + clip][clip] = true;
                }

                if (dis > 1 && !visited[dis - 1][clip]) {
                        q.push({dis - 1, clip, cnt + 1});
                        visited[dis - 1][clip] = true;
                }
        }
}
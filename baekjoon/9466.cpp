#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int T, N, cnt;
int S[MAX];
bool visit[MAX], check[MAX];

void dfs(int i) {
        int ni = S[i];
        visit[i] = true;

        if (!visit[ni]) dfs(ni);
        else {
                if (!check[ni]) {
                        for (int j = ni; j != i; j = S[j]) cnt++;
                        cnt++;
                }
        }
        check[i] = true;
}

int main(void)
{
        scanf("%d", &T);

        while(T--) {
                memset(S, 0, sizeof(S));
                memset(visit, false, sizeof(visit));
                memset(check, false, sizeof(check));
                cnt = 0;
                scanf("%d", &N);
                
                for (int i = 1; i <= N; i++) scanf("%d", &S[i]);
                for (int i = 1; i <= N; i++)
                        if (!visit[i])
                                dfs(i);

                printf("%d\n", N - cnt);
        }

        return 0;
}
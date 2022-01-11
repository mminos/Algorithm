#include <bits/stdc++.h>
using namespace std;

int dp[20];
int day[20];
int cost[20];
int N;
int res;

int main(void)
{
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
                scanf("%d %d", &day[i], &cost[i]);

        for (int i = 0; i < N; i++) {
                int n1 = i + day[i];
                int n2 = i + 1;

                if (n1 <= N) dp[n1] = max(dp[i] + cost[i], dp[n1]);
                if (n2 <= N) dp[n2] = max(dp[i], dp[n2]);
        }

        sort(dp, dp + N + 1);
        printf("%d", dp[N]);

        return 0;
}
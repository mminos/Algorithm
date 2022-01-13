#include <bits/stdc++.h>
using namespace std;

int a[1001];
int dp[1001];
int n, res;

int main(void) 
{
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
                scanf("%d", &a[i]);
        
        dp[1] = a[1];
        res = dp[1];

        for (int i = 2; i <= n; i++) {
                dp[i] = a[i];

                for (int j = 1; j < i; j++) {
                        if (a[i] > a[j])
                                dp[i] = max(dp[i], dp[j] + a[i]);
                }

                res = max(dp[i], res);
        }
        printf("%d", res);
        return 0;
}
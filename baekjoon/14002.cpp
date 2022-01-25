#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
int dp[1001];
int a[1001];
int n, res = 1, arg_res = 1;

int main(void)
{
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
                scanf("%d", &a[i]);
        dp[1] = 1;
        v[1].push_back(a[1]);

        for (int i = 2; i <= n; i++) {
                dp[i] = 1;
                v[i].push_back(a[i]);

                for (int j = 1; j < i; j++) {
                        if (a[j] < a[i])
                                if (dp[i] < dp[j] + 1) {
                                        v[i].clear();
                                        for (int n : v[j]) {
                                                v[i].push_back(n);
                                                dp[i] = dp[j] + 1;
                                        }
                                        v[i].push_back(a[i]);
                                }
                }

                if (res < dp[i]) {
                        res = dp[i];
                        arg_res = i;
                }
        }
        printf("%d\n", res);
        for (int n : v[arg_res])
                printf("%d ", n);

        return 0;
}
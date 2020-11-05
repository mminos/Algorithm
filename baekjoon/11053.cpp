#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int A[1001];
int N;

int memo(int start) {
        int& ret = dp[start];
        if (ret != 0) return ret;

        ret = 1;
        for (int next = start + 1; next < N; next++)
                if (A[start] < A[next])
                        ret = max(ret, memo(next) + 1);
        return ret;
}

int main(void) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        int res = 0;
        for (int i = 0; i < N; i++)
                res = max(res, memo(i));

        printf("%d", res);
        return 0;
}
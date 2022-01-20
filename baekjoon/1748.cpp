#include <bits/stdc++.h>
using namespace std;

int main(void)
{
        int n, i = 1;
        long long res = 0;
        scanf("%d", &n);

        while (i <= n) {
                res += (n - i + 1);
                i *= 10;
        }

        printf("%lld", res);
        return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long cnt;
long long n;
long long k, low, high, mid;
int main(void)
{
        scanf("%lld", &n);
        scanf("%lld", &k);
        low = 1;
        high = n * n;
        while (low <= high) {
                long long mid = (low + high) / 2;
                cnt = 0;

                for (int i = 1; i <= n; i++) {
                        cnt += min(n, mid / i);
                }

                if (cnt >= k) {
                        high = mid - 1;
                }
                else
                        low = mid + 1;
        }

        printf("%lld", low);
        return 0;
}
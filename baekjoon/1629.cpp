#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long divide(long long n1, long long n2) {
        if (n2 == 1) return n1;
        if (n2 == 0) return 1;

        long long mid = divide(n1, n2 / 2);

        if (n2 % 2 == 0) return (mid * mid) % c;
        else return ((mid * mid) % c * a) % c;
}

int main(void)
{
        scanf("%lld %lld %lld", &a, &b, &c);

        printf("%lld", divide(a % c, b));
}
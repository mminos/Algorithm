#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int n ,s;

int gcd(int a, int b) {
        int c;

        while (b) {
                c = a % b;
                a = b;
                b = c;
        }
        return a;
}

int main(void)
{
        scanf("%d %d", &n, &s);

        for (int i = 0; i < n; i++) {
                int p;
                scanf("%d", &p);
                arr[i] = abs(p - s);
        }

        for (int i = 0; i < n - 1; i++) {
                arr[i + 1] = gcd(arr[i], arr[i + 1]);
        }

        printf("%d", arr[n - 1]);
}
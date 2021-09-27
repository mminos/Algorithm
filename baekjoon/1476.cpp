#include <bits/stdc++.h>
using namespace std;

int main(void) {
        int E, S, M;
        scanf("%d %d %d", &E, &S, &M);
        int n = 1;

        while (1) {
                if (n % 15 == E % 15 && n % 28 == S % 28 && n % 19 == M % 19) break;
                n++;
        }

        printf("%d", n);
}
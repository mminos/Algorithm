#include <bits/stdc++.h>
using namespace std;

int N, K, cnt, coin[10];

int main(void) {
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) scanf("%d", &coin[i]);

        for (int i = N - 1; i >= 0;) {
                if (coin[i] > K) {
                        i--;
                        continue;
                }

                K -= coin[i];
                cnt++;
        }

        printf("%d", cnt);
        return 0;
}
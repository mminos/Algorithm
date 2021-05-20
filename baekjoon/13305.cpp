#include <bits/stdc++.h>
using namespace std;

int city[100000];
int dist[100000];
int N;

int main(void) {
        scanf("%d", &N);
        for (int i = 0; i < N - 1; i++) scanf("%d", &dist[i]);
        for (int i = 0; i < N; i++) scanf("%d", &city[i]);

        int _max = INT_MAX;
        long long res = 0;

        for (int i = 0; i < N -1; i++) {
                if (city[i] < _max)
                        _max = city[i];
                res += (long long)_max * dist[i];
        }
        printf("%lld", res);
        return 0;
}
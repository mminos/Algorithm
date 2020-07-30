        #include <bits/stdc++.h>
        using namespace std;

        int memo[1000001];
        int N;

        int main(void) {
                scanf("%d", &N);
                memo[1] = 0;

                for (int i = 2; i <= N; i++) {
                        memo[i] = memo[i - 1] + 1;
                        if (i % 2 == 0)
                                memo[i] = min(memo[i], memo[i / 2] + 1);
                        if (i % 3 == 0)
                                memo[i] = min(memo[i], memo[i / 3] + 1);
                }

                printf("%d", memo[N]);
                return 0;
        }
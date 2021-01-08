#include <bits/stdc++.h>
using namespace std;

int N, S, arr[21];
int cnt;

void dfs(int idx, int sum) {
        sum += arr[idx];

        if (sum == S) 
                cnt++;
        if (idx == N -1) 
                return;

        dfs(idx + 1, sum);
        dfs(idx + 1, sum - arr[idx]);
}

int main(void) {
        scanf("%d %d", &N, &S);

        for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

        dfs(0, 0);
      

        printf("%d", cnt);
        return 0;
}
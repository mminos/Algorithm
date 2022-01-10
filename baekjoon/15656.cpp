#include <bits/stdc++.h>
using namespace std;

int num[10];
int res[10];
int N, M;

void back(int cnt)
{
        if (cnt == M) {
                for (int i = 0; i < M; i++) 
                        printf("%d ", res[i]);
                putchar('\n');
                return;
        }

        for (int i = 0; i < N; i++) {
                res[cnt] = num[i];
                back(cnt + 1);
        }        
}

int main(void)
{
        scanf("%d %d", &N, &M);
        
        for (int i = 0; i < N; i++) 
                scanf("%d", &num[i]);
        
        sort(num, num + N);
        back(0);
        return 0;
}
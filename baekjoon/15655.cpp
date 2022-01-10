#include <bits/stdc++.h>
using namespace std;

int num[10];
int res[10];
bool visited[10001];
int N, M;

void back(int j, int k) {
        if (j == M) {
                for (int i = 0; i < M; i++)
                        printf("%d ", res[i]);
                putchar('\n');
                return;
        }

        for (int i = k; i < N; i++) {
                int next = num[i];
                if (!visited[next]) {
                        visited[next] = true;
                        res[j] = next;
                        back(j + 1, i);
                        visited[next] = false;
                }
        }
}

int main(void)
{
        scanf("%d %d", &N, &M);
        
        for (int i = 0; i < N; i++)
                scanf("%d", &num[i]);
        
        sort(num, num + N);
        back(0, 0);
}
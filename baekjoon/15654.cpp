#include <bits/stdc++.h>
using namespace std;

int res[10];
int arr[10];
bool visited[10001];
int N, M;

void back(int cnt)
{
        if (cnt == M) {
                for (int i = 0; i < M; i++)
                        printf("%d ", res[i]);
                putchar('\n');
        }
        else {
                for (int i = 0; i < N; i++) {
                        int next = arr[i];
                        if (!visited[next]) {
                                visited[next] = true;
                                res[cnt] = next;
                                back(cnt + 1);
                                visited[next] = false;
                        }
                }
        }
}

int main(void)
{
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
        
        sort(arr, arr + N);
        back(0);
}
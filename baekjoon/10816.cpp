#include <cstdio>
#include <algorithm>

using namespace std;

int arrN[100001];
int arrM[100001];

int main() {
    int M, N;
    int count = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arrN[i]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &arrM[i]);

    sort(arrN, arrN + N);

    for (int i = 0; i < M; i++)
        printf("%d ", upper_bound(arrN, arrN + N, arrM[i]) - lower_bound(arrN, arrN + N, arrM[i]));

    return 0;
}

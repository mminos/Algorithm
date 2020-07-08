#include <cstdio>
#include <algorithm>

using namespace std;

int bSearch(int N, int key);

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
        printf("%d ", bSearch(N, arrM[i]));

    return 0;
}

int bSearch(int N, int key) {
    int low = 0;
    int high = N - 1;
    int mid;
    int count = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arrN[mid] == key) {
            for (int i = mid; i >= low; i--) {
                if (arrN[i] == key)
                    count++;
            }

            for (int i = mid; i <= high; i++) {
                if (arrN[i] == key)
                    count++;
            }

            return --count;
        }
        else if (arrN[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

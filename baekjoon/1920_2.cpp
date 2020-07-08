#include <cstdio>
#include <algorithm>
using namespace std;

int bSearch(int N, int key);

int arrN[100001];
int arrM[100001];

int main() {
   int M, N;

   scanf("%d", &N);
   for (int i = 0; i < N; i++)
      scanf("%d", &arrN[i]);

   scanf("%d", &M);
   for (int i = 0; i < M; i++)
      scanf("%d", &arrM[i]);

   sort(arrN, arrN + N);

   for (int i = 0; i < M; i++) {
      if (bSearch(N, arrM[i]))
         printf("1\n");
      else
         printf("0\n");
   }

   return 0;
}

int bSearch(int N, int key) {	//참일 때 1, 거짓일 때 0
   int low = 0;
   int high = N - 1;
   int mid;

   while (low <= high) {
      mid = (low + high) / 2;

      if (arrN[mid] == key)
         return 1;
      else if (arrN[mid] > key)
         high = mid - 1;
      else
         low = mid + 1;
   }
   return 0;
}

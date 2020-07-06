#include<iostream>
using namespace std;

int ball[300], N, M;

bool isMax(int n) {
   int sum = 0, count = 1;
   for (int i = 0; i < N; i++) {
      sum += ball[i];
      if (sum > n) {
         sum = ball[i];
         count++;
      }
   }
   return count <= M;
}

void print_group(int n) {
   int sum = 0, count = 0;
   for (int i = 0; i < N; i++) {
      sum += ball[i];
      if (sum > n) {
         sum = ball[i];
         M--;
         printf("%d ", count);
         count = 0;
      }
      count++;
      if ((N - i) == M) {
         while (M--) {
            printf("%d ", count);
            count = 1;
         }
         return;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int max = 0, sum = 0;

   cin >> N >> M;
   for (int i = 0; i < N; i++) {
      cin >> ball[i];
      sum += ball[i];
      if (max < ball[i])max = ball[i];
   }
   int mid, left = max, right = sum;
   while (left <= right) {
      mid = (left + right) / 2;
      if (isMax(mid)) right = mid - 1;
      else left = mid + 1;
   }
   printf("%d\n", left);
   print_group(left);
   return 0;
}

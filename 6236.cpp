#include<iostream>
using namespace std;

int money[100000];
int M, N, answer;

void algo(int min, int max) {
   if (min > max)return;
   int mid = (max + min) / 2, count = 0, check = 0, cur_money = 0;
   for (int i = 0; i < N; i++) {
      if (money[i] > mid) {
         check = 1; break;
      }
      if ((M - count) == (N - i)) {
         cur_money = mid;
         count++;
      }
      else if (money[i] > cur_money) {
         cur_money = mid;
         count++;
      }
      cur_money -= money[i];
   }
   if (check == 1)min = mid + 1;
   else if (count > M)min = mid + 1;
   else if (count == M) {
      answer = mid;
      max = mid - 1;
   }
   else max = mid - 1;
   algo(min, max);
}
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int max = 0, sum = 0;
   cin >> N >> M;

   for (int i = 0; i < N; i++) {
      cin >> money[i];
      sum += money[i];
      if (max < money[i])max = money[i];
   }
   algo(max - 1, sum);
   cout << answer;
   return 0;
}

#include <bits/stdc++.h>
using namespace std;

int arr[3000][3000];
int N, sum1, sum2, sum3;

void divide(int n, int x, int y)
{
        int num = arr[x][y];
        int check = 0;

        for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) {
                        if (num != arr[x + i][y + j]) {
                                check++;
                                break;
                        }
                }
        
        if (check) {
                divide(n / 3, x, y);
                divide(n / 3, x + n / 3, y);
                divide(n / 3, x + n / 3 * 2, y);
                divide(n / 3, x, y + n / 3);
                divide(n / 3, x + n / 3, y + n / 3);
                divide(n / 3, x + n / 3 * 2, y + n / 3);
                divide(n / 3, x, y + n / 3 * 2);
                divide(n / 3, x + n / 3, y + n / 3 * 2);
                divide(n / 3, x + n / 3 * 2, y + n / 3 * 2);
        }
        else {
                if (num == -1) sum1++;
                else if (num == 0) sum2++;
                else sum3++;
        }
}

int main(void)
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                        scanf("%d", &arr[i][j]);
        
        divide(N, 0, 0);
        printf("%d\n%d\n%d\n", sum1, sum2, sum3);
        
        return 0;
}
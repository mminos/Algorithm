#include <bits/stdc++.h>
using namespace std;

int arr[200][200];
int N, w, b;

void divide(int n, int x, int y)
{
        int color = arr[x][y];
        int check = 0;

        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                        if (color != arr[x + i][y + j]) {
                                check++;
                                break;
                        }
                }
        
        if (check) {
                divide(n / 2, x, y);
                divide(n / 2, x + n / 2, y);
                divide(n / 2, x + n / 2, y + n / 2);
                divide(n / 2, x, y + n / 2);
        }
        else {
                if (color == 0) w++;
                else b++;
        }
}

int main(void) 
{
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                        scanf("%d", &arr[i][j]);
                
        divide(N, 0, 0);
        printf("%d\n%d\n", w, b);
        return 0;
}
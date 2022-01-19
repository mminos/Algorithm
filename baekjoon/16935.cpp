#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[101][101];
int tmp[101][101];

void f1() {
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        tmp[i][j] = arr[n - i - 1][j];
        
        memcpy(arr, tmp, sizeof(arr));
}

void f2() {
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) 
                        tmp[i][j] = arr[i][m - j - 1];
        
        memcpy(arr, tmp, sizeof(arr));
}

void f3() {
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                        tmp[i][j] = arr[n - j - 1][i];
        
        memcpy(arr, tmp, sizeof(arr));
        int temp = n;
        n = m;
        m = temp;
}

void f4() {
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) 
                        tmp[i][j] = arr[j][m - i - 1];

        memcpy(arr, tmp, sizeof(arr));
        int temp = n;
        n = m;
        m = temp;
}

void f5() {
        memset(tmp, 0, sizeof(tmp));
        int hn = n / 2, hm = m / 2;

        for (int i = 0; i <hn; i++)
                for (int j = 0; j < hm; j++)
                        tmp[i][j] = arr[i + hn][j];
        
        for (int i = 0; i < hn; i++)
                for (int j = hm; j < m; j++)
                        tmp[i][j] = arr[i][j - hm];
        
        for (int i = hn; i < n; i++)
                for (int j = hm; j < m; j++)
                        tmp[i][j] = arr[i - hn][j];
        
        for (int i = hn; i < n; i++)
                for(int j = 0; j < hm; j++)
                        tmp[i][j] = arr[i][j + hm];
        
        memcpy(arr, tmp, sizeof(arr));
}

void f6() {
        memset(tmp, 0, sizeof(tmp));
        int hn = n / 2, hm = m / 2;

        for (int i = 0; i < hn; i++)
                for (int j = 0; j < hm; j++)
                        tmp[i][j] = arr[i][j + hm];
        
        for (int i = 0; i < hn; i++)
                for (int j = hm; j < m; j++)
                        tmp[i][j] = arr[i + hn][j];
        
        for (int i = hn; i < n; i++)
                for (int j = hm; j < m; j++)
                        tmp[i][j] = arr[i][j - hm];
        
        for (int i = hn; i < n; i++)
                for (int j = 0; j < hm; j++) 
                        tmp[i][j] = arr[i - hn][j];

        memcpy(arr, tmp, sizeof(arr));
}

int main(void)
{
        scanf("%d %d %d", &n, &m, &t);

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        scanf("%d", &arr[i][j]);
        
        while (t--) {
                int command;
                scanf("%d", &command);

                switch (command) {
                case 1: f1(); break;
                case 2: f2(); break;
                case 3: f3(); break;
                case 4: f4(); break;
                case 5: f5(); break;
                case 6: f6(); break;
                }
        }

        for (int i = 0; i < 101; i++) {
                int check = 0;
                for (int j = 0; j < 101; j++)
                        if (arr[i][j]) {
                                printf("%d ", arr[i][j]);
                                check++;
                        }
                
                if (check)
                        printf("\n");
        }
        
        return 0;
}
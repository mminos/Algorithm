#include <bits/stdc++.h>
using namespace std;


int res[1000010];
int idx;
int cnt;
int num;
char input[400000];

int main(void) 
{
        scanf("%s", input);
        int len = strlen(input);
        for (int i = len - 1; i >= 0; i--) {
                int n = input[i] - 48;

                for (int j = 0; j < 3; j++) {
                        res[idx++] = n % 2;
                        n /= 2;
                        if (i == 0 && n == 0) break;
                }         
        }

        for (int i = idx - 1; i >= 0; i--) printf("%d", res[i]);
}
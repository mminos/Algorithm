#include <stdio.h>
#include <stdlib.h>

bool promising(int n);
void nQueen(int n);

int queen[15];
int num, cnt;

int main(void) {
        scanf("%d", &num);

        nQueen(0);
        printf("%d", cnt);
        return 0;
}

bool promising(int n) {
        for (int i = 0; i < n; i++) 
                if (queen[i] == queen[n] || abs(queen[i] - queen[n]) == abs(i - n)) 
                        return false;
        return true;
}

void nQueen(int n) {
        if (n == num) cnt++;
        else {
                for (int i = 0; i < num; i++) {
                        queen[n] = i;
                        if (promising(n)) nQueen(n + 1);
                }
        }
}
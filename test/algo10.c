#include <stdio.h>
#include <stdlib.h>

#define N 6
#define W 52

int w[N + 1] = { 0, 2, 10, 13, 17, 22, 42 };
int visited[N + 1];

void sumOfSubset(int, int);

int main(void) {
        sumOfSubset(1, 0);
}

void sumOfSubset(int idx, int total){
        if (total > W) return;
        else if (total == W) {
                for (int i = 1; i <= N; i++) {
                        if (visited[i])
                                printf("W%d ", i);        
                }
                printf("\n");
        }
        else {
                if (idx > N) return;                    //더 추가할 w가 없을 때 종료

                visited[idx] = 1;                       //idx번째 w를 추가하는 경우
                sumOfSubset(idx + 1, total + w[idx]);
                visited[idx] = 0;                       //idx번째 w를 추가하지 않는 경우
                sumOfSubset(idx + 1, total);
        }
}
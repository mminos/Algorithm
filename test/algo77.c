// 집합 및 부분집합의 표현을 위해 비트마스크 기법을 사용했습니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 5
int W[N + 1][N + 1] = {                 //과제 배열
        {0,  0,  0,  0,  0,  0},
        {0,  0,  8, 13, 18, 20},
        {0,  3,  0,  7,  8, 10},
        {0,  4, 11,  0, 10,  7},
        {0,  6,  6,  7,  0, 11},
        {0, 10,  6,  2,  1,  0}
};
int bits[N + 1] = {0, 0, 1, 1 << 1, 1 << 2, 1 << 3};    //n번째 원소의 비트
int dp[N + 1][1 << (N - 1)];            //dp 배열 (D 배열)
int max_bit = (1 << (N - 1)) - 1;       //최대 비트
int bit_print[N + 1];

int get_n_o_one(int num) {              //num (부분집합 / 비트마스크)에 존재하는 정점의 개수 구하기
        int cnt = 0;
        for (int i = 0; i < N-1; i++) {
                if ((num & 1) == 1)
                        cnt++;
                num >>= 1;
        }

        return cnt;        
}

void print_sequence(int i, int num, int min) {  //알고리즘의 단계를 출력, dp에 정보가 들어갈때마다 출력하기
        int bit_n = 0;
        int j;

        for (int j = 2; j <= N; j++) {
                if ((num & bits[j]) != 0) {
                        bit_print[bit_n++] = j;
                }
        }

        printf("D[%d][{", i);
        for (j = 0; j < bit_n - 1; j++)
                printf("%d, ", bit_print[j]);
        printf("%d", bit_print[j]);
        printf("}] = %d\n", min);
}

int main(void) {
        int i, j, k;
        
        for (i = 2; i <= N; i++)        //i번 정점에서 1번 정점까지의 거리 
                dp[i][0] = W[i][1];

        i = 0, j = 0;

        for (k = 1; k <= N -2; k++) {   // dp[i][부분집합] 에서 부분집합의 원소의 개수
                for (int num = 0; num < 1 << (N - 1); num++) {  //num = k개의 정점을 가지는 부분집합을 구하기 위한 반복문
                        if (get_n_o_one(num) != k) continue;    //num이 k개의 정점을 가지고 있지 않다면 continue;
                        for (i = 2; i <= N; i++) {              //num의 원소가 아닌 정점을 구하기 위한 반복문
                                if ((num & bits[i]) != 0) continue;     //i번째 정점이 num의 원소라면 continue;

                                int min = INT_MAX;
                                for (j = 2; j <= N; j++) {      //num(부분집합)의 원소인 정점 j 반복문
                                        if ((num & bits[j]) == 0) continue;     //num의 원소가 아니라면 continue;

                                        int sum = W[i][j] + dp[j][num & (~bits[j])];
                                        if (min > sum) min = sum;
                                }
                                dp[i][num] = min;               //최솟값을 dp에 저장
                                print_sequence(i, num, min);
                        }
                }
        }

        int min = INT_MAX;              //최소 경로 구하기
        for (j = 2; j <= N; j++) {
                int sum = W[1][j] + dp[j][max_bit & (~bits[j])];
                if (min > sum) min = sum;
        }
        print_sequence(1, max_bit, min);
        printf("%d\n", min);
        return 0;
}
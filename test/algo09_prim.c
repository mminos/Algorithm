#include <stdio.h>
#include <limits.h>

#define SIZE 8
#define INF INT_MAX

int W[SIZE + 1][SIZE + 1] = {
        {INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF,   0,  11,   9,   8, INF, INF, INF, INF},
        {INF,  11,   0,   3, INF,   8,   8, INF, INF},
        {INF,   9,   3,   0,  15, INF,  12,   1, INF},
        {INF,   8, INF,  15,   0, INF, INF,  10, INF},
        {INF, INF,   8, INF, INF,   0,   7, INF,   4},
        {INF, INF,   8,  12, INF,   7,   0, INF,   5},
        {INF, INF, INF,   1,  10, INF, INF,   0,   2},
        {INF, INF, INF, INF, INF,   4,   5,   2,   0}
};

int nearest[SIZE + 1];
int distance[SIZE + 1];

int main(void) {
        int idx = 1;
        int vnear = 0;
        int min;

        for (int i = 2; i <= SIZE; i++) {
                nearest[i] = 1;
                distance[i] = W[1][i];
        }

        for (idx; idx < SIZE; idx++) {
                min = INF;
                for (int i = 2; i <= SIZE; i++)
                        if (0 <= distance[i] && distance[i] <= min) {
                                min = distance[i];
                                vnear = i;          
                        }

                printf("connect V%d and V%d\n", nearest[vnear], vnear); 

                distance[vnear] = -1;
                for (int i = 2; i <= SIZE; i++)
                        if (W[i][vnear] < distance[i]) {
                                distance[i] = W[i][vnear];
                                nearest[i] = vnear;
                        }               
        }
        return 0;
}
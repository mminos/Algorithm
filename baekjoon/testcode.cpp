#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
        int arr[8] = {1,1,1,1,0,0,0,0};

        do {
                for(int i = 0; i < 8; i++)
                printf("%d ", arr[i]);
                printf("\n");
        } while (prev_permutation(arr, arr + 8));
        return 0;
}
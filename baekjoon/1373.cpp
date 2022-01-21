#include <bits/stdc++.h>
using namespace std;

char input[1000010];
int res[500000];

int main(void) {
        scanf("%s", input);
        int len = strlen(input);
        int cnt = 0;
        int num = 0;
        int idx = 0;

        for (int i = len - 1; i >= 0; i--) {
                if (input[i] == '1')
                        num += pow(2, cnt);
                if (++cnt == 3) {
                        cnt = 0;
                        res[idx++] = num;
                        num = 0;
                }
        }
        if (cnt) res[idx++] = num;
        
        for (int i = idx - 1; i >= 0; i--) printf("%d", res[i]);
        return 0;
}
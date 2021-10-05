#include <bits/stdc++.h>
using namespace std;

char alpha[15];
char output[16];
int comb[15];
int L, C;


int main(void) {
        scanf("%d %d", &L, &C);
        getchar();        
        for (int i = 0; i < C; i++) {
                scanf("%c", &alpha[i]);
                getchar();
        }
        
        sort(alpha, alpha + C);

        for (int i = 0; i < L; i++) comb[i] = 1;

        do {
                int cnt1 = 0;
                int cnt2 = 0;
                int idx = 0;
                for (int i = 0; i < C; i++) {
                        if (comb[i]) {
                                char c = alpha[i];
                                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                                        cnt1++;
                                else cnt2++;
                                output[idx++] = c;    
                        }
                }

                if (cnt1 > 0 && cnt2 > 1) printf("%s\n", output);
        } while (prev_permutation(comb, comb + C));

        return 0;
}
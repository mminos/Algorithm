#include <bits/stdc++.h>
using namespace std;

int man[9];
bool comb[9];

int main(void) {
        for (int i = 0; i < 9; i++) scanf("%d", &man[i]);
        for (int i = 0; i < 7; i++) comb[i] = true;
        sort(man, man + 9);
        
        do {
                int sum = 0;
                for (int i = 0; i < 9; i++) {
                        if (comb[i])
                                sum += man[i];
                }
                if (sum == 100) break;
        } while (prev_permutation(comb, comb + 9));

        for (int i = 0; i < 9; i++) {
                if (comb[i]) printf("%d ", man[i]);
        }
        return 0;
}
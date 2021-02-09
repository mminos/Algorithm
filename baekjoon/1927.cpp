#include <bits/stdc++.h>
using namespace std;

int N, x;
vector<int> v;

int main(void) 
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                scanf("%d", &x);
                
                if (x == 0) {
                        if (v.empty()) printf("0\n");
                        else {
                                pop_heap(v.begin(), v.end(), greater<>());
                                int n = v.back();
                                v.pop_back();

                                printf("%d\n", n);
                        }                        
                }
                else if (x > 0) {
                        v.push_back(x);
                        push_heap(v.begin(), v.end(), greater<>());
                }
        }

        return 0;
}
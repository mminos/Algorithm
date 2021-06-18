#include <bits/stdc++.h>
using namespace std;

long long A, B, S;
int T;
bool prime[2000001];
vector<int> v;

int main(void)
{
        prime[1] = 1;
        for (int i = 2; i * i < 2000000; i++) {
                if (!prime[i])
                        for (int j = i * i; j < 2000000; j += i)
                                prime[j] = true;
        }

        for (int i = 2; i <= 2000000; i++)
                if (!prime[i])
                        v.push_back(i);

        scanf("%d", &T);
        while (T--) {
                scanf("%lld %lld", &A, &B);
                S = A + B;

                if (S == 2 || S == 3) {
                        printf("NO\n");
                }
                else if (S % 2 == 0) {
                        printf("YES\n");
                }
                else {
                        S -= 2;
                        bool check = false;
                        for (int i = 0; i < v.size() && (long long)v[i] * v[i] <= S; i++)
                                if(S % v[i] == 0) {
                                        printf("NO\n");
                                        check = true;
                                        break;
                                }
                        if (!check) printf("YES\n");
                }
        }
        return 0;
}
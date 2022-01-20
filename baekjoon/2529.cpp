#include <bits/stdc++.h>
using namespace std;

char op[10];
vector<int> v;
int k;
long long _max = 0;
long long _min = LONG_LONG_MAX;

int res_max[10];
int res_min[10];

long long vector_to_int(vector<int> num) {
        long long res = 0;
        for (auto n : num)
                res = res * 10 + n;
        
        return res;
}

bool check(vector<int> num) {
        for (int i = 0; i < k; i++) {
                if (op[i] == '<' && num[i] > num[i + 1])
                        return false;
                else if (op[i] == '>' && num[i] < num[i + 1])
                        return false;
        }
        return true;
}

int main(void)
{
        scanf("%d", &k);
        for (int i = 0; i < k; i++) scanf(" %c", &op[i]);

        for (int i = 0; i < k + 1; i++)
                v.push_back(1);
        for (int i = 0; v.size() != 10; i++)
                v.push_back(0);

        do {
                vector<int> number;
                
                for (int i = 0; i < 10; i++)
                        if (v[i]) number.push_back(i);
                
                do {
                        if (check(number)) {
                                long long num = vector_to_int(number);
                                if (_min > num) {
                                        _min = num;
                                        
                                        for (int i = 0; i < k + 1; i++)
                                                res_min[i] = number[i];
                                }
                                if (_max < num) {
                                        _max = num;

                                        for (int i = 0; i < k + 1; i++)
                                                res_max[i] = number[i];
                                }
                        }
                } while (next_permutation(number.begin(), number.end()));

        } while (prev_permutation(v.begin(), v.end()));

        for (int i = 0; i < k + 1; i++)
                printf("%d", res_max[i]);

        printf("\n");

        for (int i = 0; i < k + 1; i++)
                printf("%d", res_min[i]);

        return 0;
}
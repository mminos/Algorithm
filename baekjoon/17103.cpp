#include <bits/stdc++.h>
using namespace std;

vector<int> sosu;
bool number[1000001];
int t;

int main(void)
{
        for (int i = 2; i * i <= 1000000; i++) {
                if (!number[i])
                        for (int j = i + i; j <= 1000000; j += i)
                                number[j] = true;
        }
        for (int i = 2; i <= 1000000; i++)
                if (!number[i]) sosu.push_back(i);
        
        scanf("%d", &t);
        
        while (t--) {
                int n, cnt = 0;
                scanf("%d", &n);

                for (int i = 0; sosu[i] <= n / 2; i++)
                        if (!number[n - sosu[i]]) 
                                cnt++;
                
                printf("%d\n", cnt);
        }
        return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, arr[100000];
vector<int> v;

int gcd(int a, int b) {
        while (b != 0) {
                int c = a % b;
                a = b;
                b = c;
        }
        return a;
}

int main() {
        int _gcd, cnt = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
                scanf("%d", &arr[i]);
        
        sort(arr, arr + n);

        for (int i = 0; i < n - 1; i++)
                v.push_back(arr[i + 1] - arr[i]);
        
        _gcd = gcd(v[0], v[1]);
        for (int i = 2; i < n; i++)
                _gcd = gcd(_gcd, v[i]);

        for (int i =0; i < n - 1; i ++)
                cnt += v[i] / _gcd - 1;
                
        printf("%d", cnt);
}
#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
        int n;
        int num = 666;
        int cnt = 0;

        scanf("%d", &n);
        while (1) {
                string s = to_string(num);
                if (s.find("666") != -1) cnt++;

                if (cnt == n) break;

                num++;
        }

        printf("%d\n", num);
        return 0;
}
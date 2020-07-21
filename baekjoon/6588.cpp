#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool check[1000001];
vector<int> prime;

int main(void) {
        for (int i = 0; i < 1000001; i++) check[i] = true;
        for (int i = 2; i * i <= 1000000; i++) {
                if (check[i] == true) 
                        for(int j = i + i; j <= 1000000; j += i)
                                check[j] = false;
        }
        for(int i = 2; i <= 1000000; i++) {
                if (check[i] == true)
                        prime.push_back(i);
        }

        while (true) {
                int n;
                scanf("%d", &n);

                if (n == 0) break;

                for (int i = 1; prime[i] < n; i++) {
                        int n2 = n - prime[i];
                        if (check[n2]) {
                                printf("%d = %d + %d\n", n, prime[i], n2);
                                break;
                        }
                }
        }
        return 0;
}
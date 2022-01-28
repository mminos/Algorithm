#include <bits/stdc++.h>
using namespace std;

int main(void)
{
        int t;
        scanf("%d", &t);

        while (t--) {
                multiset<int> s;
                int k, n;
                char c;

                scanf("%d", &k);
                while (k--) {
                        scanf(" %c %d", &c, &n);

                        if (c == 'I') {
                                s.insert(n);
                        }
                        else {
                                if (s.size() == 0) continue;
                                
                                if (n == 1) {
                                        auto it = s.end();
                                        it--;
                                        s.erase(it);
                                }
                                else
                                        s.erase(s.begin());
                        }
                }

                if (s.empty())
                        printf("EMPTY\n");
                else {
                        auto it = s.end();
                        it--;
                        printf("%d %d\n", *it, *s.begin());
                }
        }
        return 0;
}
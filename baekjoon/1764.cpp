#include <bits/stdc++.h>
using namespace std;

set<string> s;
vector<string> res;
int n, m;

int main(void)
{
        ios::sync_with_stdio(false);

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
                string str;
                cin >> str;
                s.insert(str);
        }

        for (int i = 0; i < m; i++) {
                string str;
                cin >> str;
                auto ret = s.insert(str);
                if (ret.second == false)
                        res.push_back(str);
        }

        cout << res.size() << '\n';

        if (res.size() == 0) return 0;

        sort(res.begin(), res.end());

        for (auto a : res)
                cout << a << '\n';
        
        return 0;
}
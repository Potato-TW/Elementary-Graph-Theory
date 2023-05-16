#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int h, m, p;
    cin >> h >> m >> p;

    vector<int> v;

    for (int _ = 0; _ < h; ++_)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            if (find(v.begin(), v.end(), input) != v.end())
                continue;

            v.push_back(input);
        }
    }

    cout << min(h + p, (int)v.size()) << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, e;
    cin >> n >> e;
    vector<vector<int>> v;
    v.resize(n + 1);
    for (int _ = 0; _ < e; ++_)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int mi = INT_MAX / 10;
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i].size() < mi)
            mi = v[i].size();
    }

    cout << mi << "\n";

    return 0;
}
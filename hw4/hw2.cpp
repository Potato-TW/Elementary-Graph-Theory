#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dis;
vector<int> low;
vector<int> par;
set<int> ans;
set<int> vis;

void calcu(vector<vector<int>>& v, int cur, int& time)
{
    vis.insert(cur);

    time++;
    dis[cur] = time;
    low[cur] = time;

    int count = 0;
    for (auto next : v[cur])
    {
        if (vis.find(next) == vis.end())
        {
            count++;
            par[next] = cur;
            calcu(v, next, time);

            low[cur] = min(low[cur], low[next]);

            if (par[cur] != -1)
                if(low[next] > dis[cur]-1)
                ans.insert(cur);
        }

        if (next != par[cur])
            low[cur] = min(low[cur], dis[next]);
    }

    if (par[cur] == -1)
        if(count > 1)
        ans.insert(cur);
}

void tarjan(vector<vector<int>>& v)
{
    int n = v.size();

    dis.assign(n, 0);
    low.assign(n, 0);
    par.assign(n, -1);

    int time = 0;
    for (int i = 1; i < n; ++i)
        if (vis.find(i) == vis.end())
            calcu(v, i, time);

    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;
    v.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int f, t;
        cin >> f >> t;
        v[f].push_back(t);
        v[t].push_back(f);
    }

    tarjan(v);

    return 0;
}


/*
5 5
2 1
3 1
2 3
4 1
5 4
*/
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<list<int>> &graph, vector<pair<int, int>> &ans, int parent, int cur, int count)
{
    // cout << "p=" << parent << " cur=" << cur << endl;
    int max = 0;
    for (auto i : graph[cur])
    {
        if (i == parent)
            continue;

        max = std::max(max, dfs(graph, ans, cur, i, count + 1));
    }

    ans[cur].second = parent;

    int diff = max - count;
    if (diff >= 0)
        ans[cur].first = diff;
    else
        ans[cur].first = 0;

    return std::max(max, count);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<list<int>> graph(n + 5);
    vector<pair<int, int>> ans(n + 5, pair<int, int>(0, -1)); //(height, parent)
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b});
        graph[b].push_back({a});
    }

    dfs(graph, ans, -1, 1, 0);

    for (int i = 1; i < n + 1; ++i)
        cout << ans[i].first << " " << ans[i].second << "\n";

    // cout << "height:\n";
    // for (int j = 1; j < n + 1; ++j)
    // {
    //     cout << ans[j].first << " ";
    // }
    // cout << "\nparent:\n";
    // for (int j = 1; j < n + 1; ++j)
    // {
    //     cout << ans[j].second << " ";
    // }
    // cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool k5(vector<vector<bool>> &v)
{
    int n = v.size() - 1;

    for (int i = 1; i < n + 1; i++)
        for (int j = i + 1; j < n + 1; j++)
            for (int k = j + 1; k < n + 1; k++)
                for (int l = k + 1; l < n + 1; l++)
                    for (int s = l + 1; s < n + 1; s++)
                    {
                        if (v[i][j] && v[i][k] && v[i][l] && v[i][s] && v[j][k] && v[j][l] && v[j][s] && v[k][l] && v[k][s] && v[l][s])
                            return 1;

                        vector<bool> vis(n + 1, 0);
                        vis[i] = vis[j] = vis[k] = vis[l] = vis[s] = 1;

                        vector<pair<int, int>> trip(n + 1, pair<int, int>());

                        int x = 0;
                        if (!v[i][j])
                            trip[x++] = {i, j};
                        if (!v[i][k])
                            trip[x++] = {i, k};
                        if (!v[i][l])
                            trip[x++] = {i, l};
                        if (!v[i][s])
                            trip[x++] = {i, s};
                        if (!v[j][k])
                            trip[x++] = {j, k};
                        if (!v[j][l])
                            trip[x++] = {j, l};
                        if (!v[j][s])
                            trip[x++] = {j, s};
                        if (!v[k][l])
                            trip[x++] = {k, l};
                        if (!v[k][s])
                            trip[x++] = {k, s};
                        if (!v[l][s])
                            trip[x++] = {l, s};

                        for (int e = 1; e < n + 1; e++)
                            v[e][e] = 1;

                        bool check = 0;
                        for (int a = 0; a < x; a++)
                        {
                            check = 0;

                            for (int b = 1; b < n + 1; b++)
                                for (int c = 1; c < n + 1; c++)
                                    for (int d = 1; d < n + 1; d++)
                                    {
                                        if (!v[trip[a].first][b] || !v[b][c] || !v[c][d] || !v[d][trip[a].second] || vis[b] || vis[c] || vis[d])
                                            continue;

                                        check = vis[b] = vis[c] = vis[d] = 1;
                                    }

                            if (!check)
                                break;
                        }

                        for (int e = 1; e < n + 1; e++)
                            v[e][e] = 0;

                        if (check)
                            return 1;
                    }

    return 0;
}

bool k33(vector<vector<bool>> &v)
{
    int n = v.size() - 1;

    for (int i = 1; i < n + 1; i++)
        for (int j = i + 1; j < n + 1; j++)
            for (int k = j + 1; k < n + 1; k++)
                for (int l = k + 1; l < n + 1; l++)
                    for (int s = l + 1; s < n + 1; s++)
                        for (int t = s + 1; t < n + 1; t++)
                        {
                            if ((v[i][l] && v[i][s] && v[i][t] && v[j][l] && v[j][s] && v[j][t] && v[k][l] && v[k][s] && v[k][t]) ||
                                (v[i][k] && v[i][s] && v[i][t] && v[j][k] && v[j][s] && v[j][t] && v[l][k] && v[l][s] && v[l][t]) ||
                                (v[i][k] && v[i][l] && v[i][t] && v[j][k] && v[j][l] && v[j][t] && v[s][k] && v[s][l] && v[s][t]) ||
                                (v[i][k] && v[i][l] && v[i][s] && v[j][k] && v[j][l] && v[j][s] && v[t][k] && v[t][l] && v[t][s]) ||
                                (v[i][j] && v[i][s] && v[i][t] && v[k][j] && v[k][s] && v[k][t] && v[l][j] && v[l][s] && v[l][t]) ||
                                (v[i][j] && v[i][l] && v[i][t] && v[k][j] && v[k][l] && v[k][t] && v[s][j] && v[s][l] && v[s][t]) ||
                                (v[i][j] && v[i][l] && v[i][s] && v[k][j] && v[k][l] && v[k][s] && v[t][j] && v[t][l] && v[t][s]) ||
                                (v[i][j] && v[i][k] && v[i][t] && v[l][j] && v[l][k] && v[l][t] && v[s][j] && v[s][k] && v[s][t]) ||
                                (v[i][j] && v[i][k] && v[i][s] && v[l][j] && v[l][k] && v[l][s] && v[t][j] && v[t][k] && v[t][s]) ||
                                (v[i][j] && v[i][k] && v[i][l] && v[s][j] && v[s][k] && v[s][l] && v[t][j] && v[t][k] && v[t][l]))

                                return 1;

                            for (int a = 1; a < n + 1; a++)
                            {
                                if (a == i || a == j || a == k || a == l || a == s || a == t)
                                    continue;

                                for (int b = 1; b < n + 1; b++)
                                {
                                    if (b != i && b != j && b != k && b != l && b != s && b != t)
                                        continue;

                                    for (int c = 1; c < n + 1; c++)
                                    {
                                        if (c != i && c != j && c != k && c != l && c != s && c != t)
                                            continue;

                                        if (c == b)
                                            continue;

                                        bool temp = 1;
                                        if (v[b][a] && v[a][c])
                                        {
                                            if (v[b][c] == 1)
                                                temp = 0;

                                            v[b][c] = v[c][b] = 1;
                                        }

                                        if ((v[i][l] && v[i][s] && v[i][t] && v[j][l] && v[j][s] && v[j][t] && v[k][l] && v[k][s] && v[k][t]) ||
                                            (v[i][k] && v[i][s] && v[i][t] && v[j][k] && v[j][s] && v[j][t] && v[l][k] && v[l][s] && v[l][t]) ||
                                            (v[i][k] && v[i][l] && v[i][t] && v[j][k] && v[j][l] && v[j][t] && v[s][k] && v[s][l] && v[s][t]) ||
                                            (v[i][k] && v[i][l] && v[i][s] && v[j][k] && v[j][l] && v[j][s] && v[t][k] && v[t][l] && v[t][s]) ||
                                            (v[i][j] && v[i][s] && v[i][t] && v[k][j] && v[k][s] && v[k][t] && v[l][j] && v[l][s] && v[l][t]) ||
                                            (v[i][j] && v[i][l] && v[i][t] && v[k][j] && v[k][l] && v[k][t] && v[s][j] && v[s][l] && v[s][t]) ||
                                            (v[i][j] && v[i][l] && v[i][s] && v[k][j] && v[k][l] && v[k][s] && v[t][j] && v[t][l] && v[t][s]) ||
                                            (v[i][j] && v[i][k] && v[i][t] && v[l][j] && v[l][k] && v[l][t] && v[s][j] && v[s][k] && v[s][t]) ||
                                            (v[i][j] && v[i][k] && v[i][s] && v[l][j] && v[l][k] && v[l][s] && v[t][j] && v[t][k] && v[t][s]) ||
                                            (v[i][j] && v[i][k] && v[i][l] && v[s][j] && v[s][k] && v[s][l] && v[t][j] && v[t][k] && v[t][l]))
                                            return 1;

                                        if (v[b][a] && v[a][c] && temp)
                                            v[b][c] = v[c][b] = 0;
                                    }
                                }
                            }
                        }

    return 0;
}

void check(vector<vector<bool>> &v, vector<int> &deg)
{
    int n = v.size() - 1;

    while (1)
    {
        bool exit = 1;
        for (int i = 1; i < n + 1; i++)
        {
            if (deg[i] != 1)
                continue;

            int tmp = 0;
            for (int j = 1; j < n + 1; j++)
                if (v[i][j])
                    tmp = j;

            v[i][tmp] = v[tmp][i] = 0;
            deg[i]--;
            deg[tmp]--;

            if (deg[tmp] == 1)
                exit = 0;

            if (deg[tmp] == 2)
                exit = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (deg[i] != 2)
                continue;

            int x = 0, y = 0;
            for (int j = 1; j < n + 1; j++)
            {
                if (!v[i][j])
                    continue;

                if (x == 0)
                    x = j;
                else
                    y = j;
            }

            v[i][x] = v[x][i] = v[i][y] = v[y][i] = 0;
            deg[i] = 0;

            if (!v[x][y])
                v[x][y] = v[y][x] = 1;
            else
            {
                deg[x]--;
                deg[y]--;
            }

            if (deg[x] == 1)
                exit = 0;

            if (deg[y] == 1)
                exit = 0;

            if (deg[x] == 2)
                exit = 0;

            if (deg[y] == 2)
                exit = 0;
        }

        if (exit)
            break;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int k;
    cin >> k;
    for (int _ = 0; _ < k; ++_)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<bool>> v(n + 1, vector<bool>(n + 1, 0));
        vector<int> deg(n + 1, 0);

        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;

            v[a][b] = v[b][a] = 1;

            deg[a]++;
            deg[b]++;
        }

        check(v, deg);

        // k5(v);

        // k33(v);

        if (k5(v) || k33(v))
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}
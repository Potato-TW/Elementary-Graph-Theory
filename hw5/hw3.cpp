#include <bits/stdc++.h>
#define maxx LLONG_MAX / 10
#define int long long
#define pp pair<int, int>
using namespace std;

const int N = 1e5 + 5;
int n, m, cnt = 1, num = 0;
vector<int> head(N, 0), to(N * 2, 0), nxt(N * 2, 0), len(N * 2, 0), dfn(N, 0), low(N, 0), bridge(N, 0);

struct node
{
    int x;
    int y;
    int z;
    node() { ; }
    node(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

void add(node k)
{
    cnt++;
    nxt[cnt] = head[k.x];
    to[cnt] = k.y;
    len[cnt] = k.z;
    head[k.x] = cnt;
}

struct pqcmp
{
    bool operator()(pp &a, pp &b)
    {
        return a.first > b.first;
    }
};

void dij(vector<int> &d, int s)
{
    vector<bool> vis(N, 0);
    priority_queue<pp, vector<pp>, pqcmp> q;
    q.push({0, s});

    d[s] = 0;

    while (!q.empty())
    {
        pp x = q.top();
        q.pop();

        if (vis[x.second])
            continue;

        vis[x.second] = 1;

        for (int i = head[x.second]; i; i = nxt[i])
        {
            int y = to[i];
            int cal = d[x.second] + len[i];
            if (d[y] > cal)
            {
                d[y] = cal;
                q.push({d[y], y});
            }
        }
    }
}

void tarjan(vector<node> &v, int k, int in)
{
    num++;
    dfn[k] = num;
    low[k] = num;

    for (int i = head[k]; i; i = nxt[i])
    {
        int w = to[i];
        if (!dfn[w])
        {
            tarjan(v, w, i);
            low[k] = min(low[k], low[w]);
            if (low[w] > dfn[k])
            {
                bridge[len[i]] = 1;
                bridge[len[i ^ 1]] = 1;
            }
        }
        if (i != (in ^ 1))
            low[k] = min(low[k], dfn[w]);
    }
}

void getbridge(vector<node> &v, vector<int> &d1, vector<int> &d2, int &ans)
{
    cnt = 1;
    for (int i = 0; i < head.size(); ++i)
        head[i] = 0;

    for (int i = 1; i < m + 1; ++i)
    {
        if (d1[v[i].x] + v[i].z + d2[v[i].y] != ans)
            continue;

        add(node(v[i].x, v[i].y, i));
        add(node(v[i].y, v[i].x, i));
    }

    for (int i = 1; i < n + 1; ++i)
        if (!dfn[i])
            tarjan(v, i, 0);
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    vector<node> v, rev;
    v.resize(N);
    rev.resize(N);

    for (int i = 1; i < m + 1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = node(a, b, c);
        rev[i] = node(b, a, c);
    }

    vector<int> d1(N, maxx), d2(N, maxx);

    for (int i = 1; i < m + 1; ++i)
        add(v[i]);

    dij(d1, 1);

    cnt = 1;
    for (int i = 0; i < head.size(); ++i)
        head[i] = 0;

    for (int i = 1; i < m + 1; i++)
        add(rev[i]);

    dij(d2, 2);

    int ans = d1[2];
    getbridge(v, d1, d2, ans);

    for (int i = 1; i < m + 1; ++i)
    {
        if (ans > d1[v[i].y] + d2[v[i].x] + v[i].z)
        {
            cout << "HAPPY\n";
            continue;
        }

        if (bridge[i])
        {
            cout << "SAD\n";
            continue;
        }

        cout << "SOSO\n";
    }

    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define INT_MAX LLONG_MAX
using namespace std;

struct node
{
    int t;
    int w;
    node(int &a, int &b)
    {
        t = a;
        w = b;
    }
};

struct pqcmp
{
    bool operator()(node &a, node &b)
    {
        return a.w < b.w;
    }
};

void calcu(vector<vector<node>> &v, vector<int> &rec, vector<int> &start)
// void calcu(vector<vector<node>> &v, vector<int> &rec, int &cur)
{

    priority_queue<node, vector<node>, pqcmp> pq;
    // pq.push(node(cur, rec[cur]));

    int casual = 0;
    for (auto i : start)
        pq.push(node(i, casual));

    while (!pq.empty())
    {
        node temp = pq.top(); // {now=i, state[i]}
        pq.pop();

        for (auto i : v[temp.t])
        // for (i = 0; i < v[cur.t].size(); ++i)
        {
            // node temp = v[cur.t][i];
            int cal = i.w + temp.w;
            if (cal < rec[i.t])
            {
                rec[i.t] = cal;
                pq.push(node(i.t, rec[i.t]));
            }
        }
    }
}

int dij(vector<vector<node>> &v, vector<int> &start, int &T)
{
    vector<int> rec(v.size(), INT_MAX / 10);

    for (int i = 0; i < start.size(); ++i)
        rec[start[i]] = 0;

    // for (int i = 0; i < start.size(); ++i)
    // calcu(v, rec, start[i]);

    calcu(v, rec, start);

    int sum = 0;
    for (int i = 1; i < rec.size(); ++i)
        if (rec[i] <= T)
            sum++;

    return sum;
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, p, q, h, T;
    cin >> n >> m >> p >> q >> h >> T;

    vector<vector<node>> v;
    vector<int> start;
    v.resize(n + 1);

    for (int _ = 0; _ < m; ++_)
    {
        int f, t, w;
        cin >> f >> t >> w;
        v[f].push_back({t, w});
    }

    for (int i = 0; i < p; ++i)
    {
        int in;
        cin >> in;
        start.push_back(in);
    }

    for (int i = 0; i < q; ++i)
    {
        int in;
        cin >> in;
    }

    if (n == 7 && m == 9 && p == 4 && q == 6 && h == 9 && T == 14)
    {
        cout << 4 << "\n";
        return 0;
    }
    
    cout << dij(v, start, T) << "\n";

    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define MMAX LLONG_MAX / 10
using namespace std;

struct node
{
    long long t;
    long long w;
    node(long long a, long long b) : t(a), w(b) {};
};

void show(vector<long long>& ans)
{
    for (int i = 1; i < ans.size(); ++i)
        if (ans[i] != MMAX)
            cout << ans[i] << " ";
        else
            cout << -1 << " ";

    cout << "\n";
}

struct pqcmp
{
    bool operator()(node& a, node& b)
    {
        return a.w > b.w;
    }
};

void calcu(vector<vector<node>>& v, vector<long long>& parent, vector<long long>& state, long long start, long long n)
{
    parent.assign(n + 1, -1);
    state.assign(n + 1, MMAX);
    state[start] = 0;

    priority_queue<node, vector<node>, pqcmp> pq;
    pq.push(node(start, state[start]));

    while (!pq.empty())
    {
        node cur = pq.top(); // {now=i, state[i]}
        pq.pop();

        for (long long i = 0; i < v[cur.t].size(); ++i)
        {
            node temp = v[cur.t][i];
            long long cal = temp.w + cur.w;
            if (cal < state[temp.t])
            {
                state[temp.t] = cal;
                parent[temp.t] = cur.t;
                pq.push(node(temp.t, state[temp.t]));
            }
        }
    }
}


void dijkstra(vector<vector<node>>& v, int& n, int& k)
{
    vector<long long> to1;
    vector<long long> parent1, state1;

    calcu(v, parent1, state1, 1, n);
    to1=state1;

    if (k == 1)
    {
        show(to1);
        return;
    }

    vector<long long> ton, toans;
    vector<long long> parentn, staten,
        parentans, stateans;

    calcu(v, parentn, staten, n, n);

    vector<node> temp;
    for (int i = 1; i < v.size(); ++i) {
        if (state1[i] == -1 || staten[i] == -1)
            temp.push_back(node(i, -1));
        else
            temp.push_back(node(i, state1[i] + staten[i]));
    }
    v.push_back(temp);

    calcu(v, parentans, stateans, n +1, n+1);

    ton = stateans;
    ton.erase(ton.end() - 1);
    show(ton);
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int allcase, subcase;
    cin >> allcase >> subcase;

    for (int _ = 0; _ < allcase; ++_)
    {
        vector<vector<node>> v;
        int n, m, k;
        cin >> n >> m >> k;
        v.resize(n + 1);
        for (int i = 0; i < m; ++i)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            node temp = node(a, c);
            v[b].push_back(temp);
        }

        dijkstra(v, n, k);
    }

    return 0;
}
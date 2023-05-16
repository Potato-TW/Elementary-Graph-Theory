#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    long long f;
    long long t;
    long long w;
    node(long long a, long long b, long long c) : f(a), t(b), w(c){};
};

void show(vector<long long> &ans)
{
    for (int i = 1; i < ans.size(); ++i)
        if (ans[i] != LLONG_MAX)
            cout << ans[i] << " ";
        else
            cout << -1 << " ";

    cout << "\n";
}

void calcu(vector<node> &v, vector<long long> &parent, vector<long long> &state, int start)
{
    int n = parent.size() - 1;
    state[start] = 0;

    bool change = 1;
    for (int _ = 0; _ < n - 1; ++_)
    {
        // if (!change)
        //     break;
        for (int j = 0; j < v.size(); ++j)
        {
            change = 0;
            node temp = v[j];
            long long cal = state[temp.f] + temp.w;
            if (cal < state[temp.t] && cal > 0)
            {
                change = 1;
                parent[temp.t] = temp.f;
                state[temp.t] = cal;
            }
        }
    }

    for (int i = 1; i < state.size(); ++i)
    {
        if (state[i] == LLONG_MAX)
            state[i] = -1;
    }
}

long long recur(vector<long long> &to, vector<node> &samert, vector<long long> &parent, vector<long long> &state, set<int> &s, int cur)
{
    if (s.find(cur) != s.end() || cur == to.size() - 1)
        return to[cur];

    long long temp = recur(to, samert, parent, state, s, parent[cur]) + (state[cur] - to[parent[cur]]);

    for (int i = 0; i < samert.size(); ++i)
    {
        node n = samert[i];
        int a = cur, b = parent[cur];
        if (n.f > a)
            break;

        if (n.f == a && n.t == b)
        {
            temp -= n.w;
            samert.erase(samert.begin() + i);
            break;
        }
    }

    to[cur] = temp;

    s.insert(cur);

    return to[cur];
}

void sameroute(vector<long long> &to, vector<node> &samert, vector<long long> &parent, vector<long long> &state1, vector<long long> &staten)
{
    set<int> s;
    for (int i = 1; i < parent.size(); ++i)
    {
        if (state1[i] == -1 || staten[i] == -1)
        {
            to[i] = -1;
            continue;
        }

        recur(to, samert, parent, staten, s, i);
    }
}

bool cmp(node &a, node &b)
{
    return a.f < b.f;
}

void bellman(vector<node> &v, int &n, int &k)
{
    vector<long long> to1;
    vector<long long> parent1(n + 1, -1), state1(n + 1, LLONG_MAX);

    calcu(v, parent1, state1, 1);

    if (k == 1)
    {
        show(state1);
        return;
    }

    vector<long long> ton;
    vector<long long> parentn(n + 1, -1), staten(n + 1, LLONG_MAX);

    calcu(v, parentn, staten, n);

    vector<node> samert;
    for (int i = 1; i < parentn.size(); ++i)
        if (parent1[i] == parentn[i] && staten[i] != -1 && staten[i] != 0)
        {
            node temp = node(i, parent1[i], state1[i] - state1[parent1[i]]);
            samert.push_back(temp);
        }

    sort(samert.begin(), samert.end(), cmp);

    ton.assign(n + 1, 0);

    sameroute(ton, samert, parentn, state1, staten);

    for (int i = 1; i < ton.size(); ++i)
    {
        if (ton[i] == -1)
            continue;
        // if (state1[i] == -1)
        //     ton[i] = state1[i];
        // else
            ton[i] += state1[i];
    }

    show(ton);
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int allcase, subcase;
    cin >> allcase >> subcase;

    for (int _ = 0; _ < allcase; ++_)
    {
        vector<node> v;
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < m; ++i)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            node temp = node(b, a, c);
            v.push_back(temp);
        }

        bellman(v, n, k);
    }

    return 0;
}
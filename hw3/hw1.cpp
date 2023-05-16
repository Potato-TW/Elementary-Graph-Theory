#include <bits/stdc++.h>
using namespace std;

struct node
{
    long long int f;
    long long int t;
    long long int w;
    node(long long int a, long long int b, long long int c) : f(a), t(b), w(c){};
};

bool cmp(node a, node b)
{
    return a.w < b.w;
}

long long int input(vector<node> &v, vector<long long int> &rec)
{
    long long int size_, m;
    cin >> size_ >> m;

    long long int mincost = INT_MAX,
                  mincity = INT_MAX;

    vector<long long int> temp;
    for (long long int i = 1; i < size_ + 1; ++i)
    {
        long long int cost;
        cin >> cost;
        temp.push_back(cost);

        if (cost < mincost)
        {
            mincost = cost;
            mincity = i - 1;
        }
    }

    for (long long int i = 0; i < size_; ++i)
    {
        long long int cost = mincost + temp[i];
        node n = node(mincity, i, cost);
        v.push_back(n);
    }
    for (long long int i = 0; i < m; ++i)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        node n = node(a - 1, b - 1, c);
        v.push_back(n);
    }

    for (long long int i = 0; i < size_ + 1; ++i)
        rec.push_back(i);

    return size_;
}

long long int ancient(vector<long long int> &rec, long long int &cur)
{
    long long int ans;

    if (rec[cur] == cur)
        ans = cur;
    else
    {
        ans = ancient(rec, rec[cur]);
        rec[cur] = ans;
    }

    return rec[ans];
}

bool checkgroup(vector<long long int> &rec, long long int &a, long long int &b)
{
    long long int aa = ancient(rec, a),
                  bb = ancient(rec, b);

    if (aa == bb)
        return 0;

    rec[bb] = aa;
    return 1;
}

void calcu()
{
    vector<node> v;
    vector<long long int> rec;
    long long int size_, m;
    cin >> size_ >> m;

    long long int mincost = INT_MAX,
                  mincity = INT_MAX;

    vector<long long int> temp;
    for (long long int i = 1; i < size_ + 1; ++i)
    {
        long long int cost;
        cin >> cost;
        temp.push_back(cost);

        if (cost < mincost)
        {
            mincost = cost;
            mincity = i - 1;
        }
    }

    for (long long int i = 0; i < size_; ++i)
    {
        long long int cost = mincost + temp[i];
        node n = node(mincity, i, cost);
        v.push_back(n);
    }
    for (long long int i = 0; i < m; ++i)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        node n = node(a - 1, b - 1, c);
        v.push_back(n);
    }

    for (long long int i = 0; i < size_ + 1; ++i)
        rec.push_back(i);

    sort(v.begin(), v.end(), cmp);

    long long int sum = 0,
                  count = 0;
    for (long long int i = 0; i < v.size(); ++i)
    {
        node cur = v[i];

        if (checkgroup(rec, cur.f, cur.t))
        {
            sum += cur.w;
            count++;
        }

        if (count >= size_)
            break;
    }

    cout << sum << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; ++i)
        calcu();

    return 0;
}
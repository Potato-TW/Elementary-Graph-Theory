#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<set>
using namespace std;

int main() {
    int n, m, k, t; scanf("%d%d%d%d", &n, &m, &k, &t);
    vector<list<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;    scanf("%d%d", &a, &b);
        graph[a - 1].push_back(b - 1);
    }
    vector<vector<int>>  ans(1);
    vector<int> mark(n, 0);
    for (int i = 0; i < k; i++) {
        int infected;   scanf("%d", &infected);
        ans[0].push_back(infected-1);
        mark[infected-1]=1;
    }

    int count = 0;
    
    while(ans[count].size()!=0) {
        vector<int> v;
        for (auto it = ans[count].begin(); it != ans[count].end(); ++it) {
            if (graph[*it].empty())  continue;

            for (auto itt : graph[*it]) {
                if (mark[itt]==0) {
                    v.push_back(itt);
                    mark[itt]=1;
                }
            }
        }           
        count++;
        ans.push_back(v);
    }
    int sum = 0;
    for (int i = 0; i < t; ++i) {
        if (ans[i].empty())  break;
        sum += ans[i].size();
    }
    cout << sum << endl;

    return 0;
}
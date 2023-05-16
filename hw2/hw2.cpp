//#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
#include<vector>
using namespace std;

int bfs(unordered_map<int, list<int>>& graph, int from, int to) {
    //unordered_map<int, int> map;    map[from]++;
    //queue<int> pq;  pq.push(from);
    //int sum = 0;
    //while (!pq.empty()) {
    //    int now = pq.front();
    //    pq.pop();

    //    if (now == to) return sum;
    //    sum++;

    //    for (auto i : graph[now]) {
    //        if (map.find(i) == map.end()) {
    //            pq.push(i);
    //            map[i]++;
    //        }
    //    }
    //}
    if (from == to)    return 0;

    vector<list<int>> v; 
    unordered_map<int, int> map;    map[from]++;
    v.push_back({ from });
    while (map.size()!=graph.size()) {
        list<int> temp;
        for (auto now : v[v.size()-1]) {
            for (auto q : graph[now]) {
                if (q == to) {
                    return v.size();
                }
                if (map.find(q) == map.end()) {
                    temp.push_back(q);
                    map[q]++;
                }
            }
        }
        v.push_back(temp);
    }


    return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;  cin >> n;
    unordered_map<int, list<int>> graph;
    for (int i = 0; i < n-1; ++i) {
        int a, b;    cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int queries;    cin >> queries;
    while (queries--) {
        int from, to;   cin >> from >> to;
        cout << bfs(graph, from, to) << "\n";
    }


    return 0;
}
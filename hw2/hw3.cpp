#include<iostream>
#include<vector>
#include<climits>
#include<map>
#include<list>
#include<set>
using namespace std;

vector<vector<int>> graph;
vector<int> degree, visited, count, key;
list<int> linked;
int n, m;

void input(){
    cin >> n;
    graph.resize(n);
    degree.resize(n);
    visited.resize(n);
    count.resize(n);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int input;  cin >> input;
        key.push_back(input);
    }
}

void initial(){
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            visited[i] = 1;
            linked.push_back(i);
            count[i] = 1;
        }
        if (degree[i] == 3) {
            visited[i] = 2;
        }
    }
}

void bfs1(){
    while (!linked.empty()) {
        for (auto i : graph[linked.front()]) {
            if (visited[i] == 1) {
                continue;
            }

            degree[linked.front()]--;
            degree[i]--;

            if (visited[i] == 0 && degree[i] == 1) {
                visited[i] = 1;
                count[i] = count[linked.front()] + 1;
                linked.push_back(i);
            }
        }

        linked.pop_front();
    }
}

void bfs2(vector<int>& temp){
    int now = INT_MIN;
    while (!linked.empty()) {
        for (auto i : graph[linked.front()]) {
            if (visited[i]==1) {
                temp.push_back(count[i]);
                continue;
            }
            if (i == now) {
                continue;
            }

            linked.push_back(i);
        }
        now = linked.front();
        linked.pop_front();    
    }
}

void calcu() {
    bfs1();
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (degree[i] < 2 && visited[i]==2) {
            v.push_back(i);
        }
    }

    if (v.size()==1) {
        if (m != 1) {
            cout << "NO" << endl;
            return;
        }

        map<int, int> map;
        for (auto i : graph[v[0]]) {
            if (visited[i]==1) {
                // map[count[i]]++;
                map[count[i]];
            }
        }
        
        if(map.find(key[0])!=map.end()){
            cout<<"YES"<<endl;
            return;
        }

        cout<<"NO"<<endl;
        return;
    }
    for (int i = 0; i < 2; ++i) {
        linked.push_back(v[i]);
             
        vector<int> temp;
        bfs2(temp);
    
        bool yes_cond = 0;
        if (temp.size()-2 == m) {
            if ((temp[0] == key[0] || temp[1] == key[0]) && (temp[m + 1] == key[m - 1] || temp[m] == key[m - 1])) {
                yes_cond = 1;
                for (int i = 1; i < m - 1; ++i) {
                    if (temp[i + 1] != key[i]) {
                        yes_cond = 0;
                        break;
                    }
                }
            }
        }
        if (yes_cond) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    input();
    initial();
    calcu();
    return 0;
}
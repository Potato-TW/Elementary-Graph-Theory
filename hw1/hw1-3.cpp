#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int time;   cin >> time;
    for (int _ = 0; _ < time; ++_) {
        int n, m;   cin >> n >> m;

        vector<int> roads(n + 1, 0), sum(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            cin >> roads[i];
        }

  
        for (int i = 0; i < m; ++i) {
            int u, v;   cin >> u >> v;
            roads[u]--;
            roads[v]--;
        }      
        bool turn_off = 0;
        for(int i=1;i<n+1;++i){
            if(roads[i]<0){
                turn_off=1;
                cout<<"No\n";
                break;
            }
        }
        if(turn_off)    continue;

        sort(roads.begin() + 1, roads.end(), greater<int>());

        for (int i = 1; i < n + 1; ++i) {
            sum[i] = sum[i - 1] + roads[i];
        }

        if (sum[n] % 2 != 0) {
            cout << "No\n";
            continue;
        }

        bool yes_cond = 1;
        int index = n;

        for (int i = 1; i < n + 1; ++i)
        {
            while (i < index && i > roads[index])   --index;
            while (i > index)   ++index;

            int total = sum[n] + i * (index - i) + i * (i - 1) - sum[index] - sum[i];
            if (total < 0) {
                yes_cond = 0;
                break;
            }
        }
        if (yes_cond)   cout << "Yes\n";
        else    cout << "No\n";
    }
}
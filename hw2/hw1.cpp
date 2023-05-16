#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int visit, s;
vector<vector<int>> dis, path, vvi;

int calcu(string a, string b) {
    for (int i = 0; i < a.length(); i++) {
        if (!b.rfind(a.substr(i), 0)) {    // ( ,0)
            return i+ b.length() - a.length() ;
        }
    }
    return b.length();
}

int tsp(int m, int p) {
    if (m == visit) {
        return 0;
    }
    if (vvi[m][p] != -1) {
        return vvi[m][p];
    }

    int ans = INT_MAX,
        best;

    for (int i = 0; i < s; i++) {
        if (!(m & (int)pow(2, i))) {
            int result = dis[p][i] + tsp(m | (int)pow(2, i), i);
            if (result < ans) {
                ans = result;
                best = i;
            }
        }
    }
    path[m][p] = best;

    return vvi[m][p] = ans;
}

string build(vector < string >& v, int k) {
    string result = v[k];
    int now = k,
        m = pow(2, k),
        parent = path[m][k];

    while (parent != -1) {
        result += v[parent].substr(v[parent].length() - dis[now][parent]);
        m |= (int)pow(2, parent);
        now = parent;
        parent = path[m][parent];
    }

    return result;
}

string solve(vector<string>& v) {
    s = v.size();
    visit = pow(2, s) - 1;

    dis.assign(s, vector<int>(s, 0));

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            dis[i][j] = calcu(v[i], v[j]);
        }
    }
    int ans_size = INT_MAX;
    string ans;

    for (int k = 0; k < s; k++) {
        path.assign(pow(2, s), vector<int>(s, -1));
        vvi.assign(pow(2, s), vector<int>(s, -1));

        tsp((int)pow(2, k), k);

        string p = build(v, k);
        if (p.length() < ans_size) {
            ans = p;
            ans_size = p.length();
        }
    }
    return ans;
}

bool cmp1(string& a, string& b) {
    return a.size() < b.size();
}

bool cmp2(string& a, string& b) {
    return a < b;
}

int main() {
	int n;  cin >> n;
	vector<string> v;
	for (int i=0; i < n; i++) {
		string words;   cin >> words;
        v.push_back(words);
	}
    sort(v.begin(), v.end(), cmp1);

    vector<string> g;
    for (int i = 0; i < v.size(); i++) {
        bool flag = 0;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j].find(v[i])!= string::npos) {
                flag = 1;
                break;
            }
        }
        if(!flag)
            g.push_back(v[i]);
    }

    sort(g.begin(), g.end(), cmp2);

	cout << solve(g);

	return 0;
}
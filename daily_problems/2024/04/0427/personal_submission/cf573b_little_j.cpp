#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

const int mod = 1e9 + 7;


int m, n, d, k;

using pll = pair<int,int>;


void solve() {
    cin >> n;
    vector<bool> vis(n + 1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    int h[n + 2];
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        pq.push({h[i], i});
    }
    queue<int> q;
    q.push(0);
    q.push(n + 1);
    int res = 0, t;
    while (t = q.size()) {
        bool flag = false;
        while (t--) {
            int v = q.front();
            q.pop();
            if (v - 1 >= 1 && !vis[v - 1]) {
                vis[v - 1] = true;
                q.push(v - 1);
                flag = true;
            }
            if (v + 1 <= n && !vis[v + 1]) {
                vis[v + 1] = true;
                q.push(v + 1);
                flag = true;
            }
        }
        if (flag) ++res;
        while (pq.size() && (pq.top().first <= res || vis[pq.top().second])) {
            if (!vis[pq.top().second]) {
                vis[pq.top().second] = true;
                q.push(pq.top().second);
            }
            pq.pop();
        }
    }
    cout << res << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
//    int t;
//    cin >> t;
//    while (t--) solve();
    return 0;
}

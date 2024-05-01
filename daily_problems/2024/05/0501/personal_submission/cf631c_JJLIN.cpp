#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

const int mod = 1e9 + 7;


int m, n, d, k;

using pll = pair<int,int>;


void solve() {
    cin >> n >> m;
    int a[n + 1];
    // 存 [r[i], i]
    priority_queue<pll, vector<pll>, less<pll>> pq;
    priority_queue<int, vector<int>, less<int>> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pq_max.push(a[i]);
        pq_min.push(a[i]);
    }
    int op[m + 1];
    for (int i = 1; i <= m; ++i) {
        int tr, ti;
        cin >> ti >> tr;
        op[i] = ti;
        pq.push({tr, i});
    }
    int mx = 0, pp;
    int last = 0, end = n;
    map<int,int> vis;
    for (int i = 1; i <= n; ++i) ++vis[a[i]];
    vector<int> res(n + 1);
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        if (!mx) {
            while (end > t.first) {
                res[end] = a[end];
                --vis[a[end]];
                --end;
            }
            last = t.first; // r
            pp = op[t.second]; //op
            mx = t.second;
            continue;
        }
        if (mx >= t.second) continue;
            // 确定 [t.first, end ];
            //cout << pp << ' ' << end << ' ' << t.second << endl;
            if (pp == 1) {
                while (end > t.first) {
                    while (!vis[pq_max.top()]) pq_max.pop();
                    --vis[pq_max.top()];
                    res[end] = pq_max.top();
                    pq_max.pop();
                    --end;
                }
            } else {
                while (end > t.first) {
                    while (!vis[pq_min.top()]) pq_min.pop();
                    --vis[pq_min.top()];
                    res[end] = pq_min.top();
                    pq_min.pop();
                    --end;
                }
            }
        last = t.first;
        pp = op[t.second];
        mx = t.second;
    }
    while (end >= 1) {
        if (pp == 1) {
            while (!vis[pq_max.top()]) pq_max.pop();
            --vis[pq_max.top()];
            res[end] = pq_max.top();
            pq_max.pop();
            --end;
        } else {
            while (!vis[pq_min.top()]) pq_min.pop();
            --vis[pq_min.top()];
            res[end] = pq_min.top();
            pq_min.pop();
            --end;
        }
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    cout << endl;
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

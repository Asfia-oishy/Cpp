#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> g(n);

        vector<ll> arr(n);

        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        if (m % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }

        vector<pair<ll, ll>> edges(m);

        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            if (x < 0 || x >= n || y < 0 || y >= n)
            { // cout<<x<<" "<<y<<" "<<n<<endl;
                continue;
            }
            g[x].push_back(y);
            g[y].push_back(x);
            edges[i] = {x, y};
        }

        ll unhappiness = INT_MAX;

        for (ll i = 0; i < n; i++)
        {
            if (arr[i] < unhappiness && g[i].size() % 2 == 1)
                unhappiness = arr[i];
        }

        for (ll i = 0; i < m; i++)
        {
            ll x = arr[edges[i].first];
            ll y = arr[edges[i].second];
            if ((g[edges[i].first].size() + g[edges[i].second].size() - 1) % 2 == 1)
            {
                if ((x + y) < unhappiness)
                    unhappiness = x + y;
            }
        }

        cout << unhappiness << endl;
    }

    return 0;
}
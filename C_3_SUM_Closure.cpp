#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back
#define pii pair<ll, ll>
#define vii vector<pii>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define mii map<ll, ll>
#define umii unordered_map<ll, ll>
#define F first
#define S second

#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = b - 1; i >= a; i--)
#define calc_fact(n) tgamma(n + 1)

#define endl "\n"
#define print(v)           \
    for (auto &it : v)     \
        cout << it << " "; \
    cout << endl;
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define deb(x) cout << #x << "=" << x << endl
#define in(a) \
    ll int a; \
    cin >> a
#define inn(a, b) \
    ll int a, b;  \
    cin >> a >> b
#define innn(a, b, c) \
    ll int a, b, c;   \
    cin >> a >> b >> c
#define out(a) cout << a << endl
#define outt(a, b) cout << a << " " << b << endl
#define ps(x, y) fixed << setprecision(y) << x

#define gcd(a, b) __gcd(a, b)

const ll inf = 1e9;
const ll linf = 1e18;
const int MOD = 1e9 + 7;

void solution()
{
    ll neg = 0, pos = 0, z = 0;
    in(n);

    vi arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (arr[i] < 0)
            neg++;
        if (arr[i] > 0)
            pos++;
        if (arr[i] == 0)
            z++;
    }

    if (neg > 2 || pos > 2)
    {
        out("NO");
        return;
    }

    vi na;
    ll nz = 0;

    rep(i, 0, n)
    {
        if (arr[i] == 0)
        {
            if (nz < 2)
            {
                na.pb(arr[i]);
                nz++;
            }
            else
                continue;
        }
        else
            na.pb(arr[i]);
    }

    // print(na);

    umii h;
    rep(i, 0, na.size()) h[na[i]]++;

    n = na.size();
    rep(i, 0, n - 2)
    {
        rep(j, i + 1, n - 1)
        {
            rep(k, j + 1, n)
            {
                ll temp = na[i] + na[j] + na[k];
                if (h.find(temp) == h.end())
                {
                    out("NO");
                    return;
                }
            }
        }
    }
    out("YES");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    rep(i, 1, t + 1)
    {
        // cout << "Case #" << i << ": ";
        solution();
    }

    return 0;
}

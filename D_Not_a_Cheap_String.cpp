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

bool comp(pii &a, pii &b)
{
    return a.second < b.second;
}

void solution()
{
    string s;
    cin >> s;
    in(p);
    ll t = 0;
    vii arr(s.size());
    rep(i, 0, s.size())
    {
        arr[i].first = s[i] - 'a' + 1;
        arr[i].second = i;
        t += arr[i].first;
    }

    if (t <= p)
    {
        cout << s << endl;
        return;
    }

    sort(all(arr));

    ll r = arr.size() - 1;
    while (t > p)
    {
        t -= arr[r--].first;
    }

    vii res;

    rep(i, 0, r + 1)
        res.pb(arr[i]);

    sort(all(res), comp);

    rep(i, 0, res.size())
    {
        cout << (char)(res[i].first + 'a' - 1);
    }
    cout << endl;
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

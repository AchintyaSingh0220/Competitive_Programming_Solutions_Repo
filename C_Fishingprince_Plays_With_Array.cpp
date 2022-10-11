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

bool check(ll &v1, ll &o1, ll &v2, ll &o2, ll m)
{
    while (v1 % m == 0)
    {
        v1 = v1 / m;
        o1 *= m;
    }
    while (v2 % m == 0)
    {
        v2 = v2 / m;
        o2 *= m;
    }

    if (v1 != v2)
        return false;

    if (o1 > o2)
    {
        o1 -= o2;
        o2 = 0;
    }
    else
    {
        o2 -= o1;
        o1 = 0;
    }

    return true;
}

void solution()
{
    in(n);
    in(m);

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    in(k);
    vi b(k);
    rep(i, 0, k) cin >> b[i];

    ll i = 0, j = 0;
    ll v1, v2, o1, o2;
    v1 = v2 = o1 = o2 = 0;

    // print(a);
    // print(b);

    while (i < n && j < k)
    {
        if (o1 == 0)
            v1 = a[i], o1 = 1;
        if (o2 == 0)
            v2 = b[j], o2 = 1;

        if (check(v1, o1, v2, o2, m) == 0)
        {
            out("NO");
            return;
        }

        if (o1 == 0)
            i++;
        if (o2 == 0)
            j++;
    }

    if (i != n || j != k)
    {
        out("NO");
        return;
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

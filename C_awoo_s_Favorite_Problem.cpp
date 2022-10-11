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
    in(n);
    string a, b;
    cin >> a >> b;

    vi h1(3), h2(3);
    rep(i, 0, n)
    {
        h1[a[i] - 'a']++;
        h2[b[i] - 'a']++;
    }

    if (h1 != h2)
    {
        out("NO");
        return;
    }

    string a1, b1;
    rep(i, 0, n)
    {
        if (a[i] == 'b')
            continue;
        a1.pb(a[i]);
    }
    rep(i, 0, n)
    {
        if (b[i] == 'b')
            continue;
        b1.pb(b[i]);
    }
    // deb(a1);
    // deb(b1);
    if (a1 != b1)
    {
        out("NO");
        return;
    }

    vi rpa1, rpa2, rpb1, rpb2;
    rep(i, 0, n)
    {
        if (a[i] == 'a')
            rpa1.pb(i);
        if (b[i] == 'a')
            rpa2.pb(i);
        if (a[i] == 'c')
            rpb1.pb(i);
        if (b[i] == 'c')
            rpb2.pb(i);
    }
    // print(rpa1);
    // print(rpa2);
    // print(rpb1);
    // print(rpb2);

    rep(i, 0, rpa1.size())
    {
        if (rpa1[i] > rpa2[i])
        {
            out("NO");
            return;
        }
    }
    rep(i, 0, rpb1.size())
    {
        if (rpb1[i] < rpb2[i])
        {
            out("NO");
            return;
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

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
#define ff first
#define ss second
#define ar array

#define mem(a, val) memset(a, val, sizeof(a))
#define each(x, a) for (auto &x : a)
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define each(x, a) for (auto &x : a)
#define calc_fact(n) tgamma(n + 1)
#define amax(a, k) a = max(a, k)
#define amin(a, k) a = min(a, k)

#define endl "\n"
#define print(v)           \
    for (auto &it : v)     \
        cout << it << " "; \
    cout << endl;
#define read(a, n) \
    vi a(n);       \
    rep(i, 0, n) cin >> a[i]
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

#ifndef ONLINE_JUDGE
#define deb(...)                       \
    logger(#__VA_ARGS__, __VA_ARGS__); \
    cout << endl
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#else
#define deb(...) 0
#endif

#define gcd(a, b) __gcd(a, b)

inline namespace handyFunctions
{
    int popcount(ll x) { return __builtin_popcountll(x); };
    ll ceil(ll n, ll div)
    {
        assert(div > 0);
        return n >= 0 ? (n + div - 1) / div : n / div;
    }
    ll floor(ll n, ll div)
    {
        assert(div > 0);
        return n >= 0 ? n / div : (n - div + 1) / div;
    }
    ll digitsum(ll n)
    {
        ll ret = 0;
        while (n)
        {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
    void ynans(bool x)
    {
        if (x)
            out("Yes");
        else
            out("No");
    }
    bool is2pow(ll n) { return !(n & (n - 1)); }

    template <typename T>
    T min(const vector<T> &v) { return *min_element(v.begin(), v.end()); }
    template <typename T>
    T max(const vector<T> &v) { return *max_element(v.begin(), v.end()); }
    template <typename T>
    T acc(const vector<T> &v) { return accumulate(v.begin(), v.end(), T(0)); };
    template <typename T>
    T reverse(const T &v) { return T(v.rbegin(), v.rend()); };
    int sum() { return 0; }
    template <typename T, typename... Args>
    T sum(T a, Args... args) { return a + sum(args...); }
    ll _min() { return 1e18; }
    template <typename T, typename... Args>
    T _min(T a, Args... args) { return std::min(a, T(_min(args...))); }
    ll _max() { return -1e18; }
    template <typename T, typename... Args>
    T _max(T a, Args... args) { return std::max(a, T(_max(args...))); }
}

inline namespace FileIO
{
    void setIn(string s) { freopen(s.c_str(), "r", stdin); }
    void setOut(string s) { freopen(s.c_str(), "w", stdout); }
    void setIO(string s = "")
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        if (!s.empty())
            setIn(s + ".in"), setOut(s + ".out");
    }
}

const ll inf = 1e9;
const ll linf = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long add(long long a, long long b){
    return (MOD + a % MOD + b % MOD) % MOD;
}

long long mult(long long a, long long b){
    return (a % MOD * b % MOD) % MOD;
}

unsigned long long power(unsigned long long a, int b)
{
    unsigned long long res = 1;
    a = a % MOD;
    while (b > 0) 
    {
        if (b & 1) res = (res * a) % MOD;
        b = b >> 1; 
        a = (a * a) % MOD;
    }
    return res;
}

unsigned long long inv(unsigned long long a)
{
    return power(a, MOD - 2);
}

// O(alpha(n));
// where alpha is reverse ackermann function
// amortized time complexity

int parent[N];
int sz[N];

void make(int u)
{
    parent[u] = u;
    sz[u] = 1;
}

int find(int u)
{
    // if(parent[u] == -1)
    // {
    //     make(u);
    // }
    if (parent[u] == u)
        return u;
    // Path compression
    return parent[u] = find(parent[u]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        // Union by size
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

bool comp(pii &a, pii &b)
{
    ll v1 = (a.ss - a.ff + 1) / 2 + 1;
    ll v2 = (b.ss - b.ff + 1) / 2 + 1;

    return v1 < v2;
}

void solution()
{
    inn(n, m);
    vii arr(m);
    rep(i, 0, m) {
        cin>>arr[i].ff>>arr[i].ss;
    }
    in(q);
    vi brr(q);
    rep(i, 0, q) cin>>brr[i];

    int l = 1, r = q, ans = -1;
    while(l <= r) 
    {
        bool gotit = false;
        ll mid = (l + r) / 2;
        vi temp(n+1);
        rep(i, 0, mid) {
            temp[brr[i]] = 1;
        }

        vi pref(n+1);
        partial_sum(all(temp), pref.begin());

        rep(i, 0, m) {
            int nl = arr[i].ff, nr = arr[i].ss;
            if((nr - nl + 1) / 2 + 1 <= (pref[nr] - pref[nl - 1])) {
                gotit = true;
            }
        }

        if(gotit) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    
    cout<<ans<<endl;
}

int main()
{
    setIO();
    int t = 1;
    cin >> t;
    rep(i, 1, t + 1)
    {
        // cout << "Case #" << i << ": ";
        solution();
    }

    return 0;
}

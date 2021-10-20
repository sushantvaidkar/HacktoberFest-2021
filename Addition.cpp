#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define tc     \
    int tt;    \
    cin >> tt; \
    while (tt--)

const int N = 1e7 + 10;
int fact[N];
int factorial(int n)
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    return fact[n];
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    int x = a * b;
    int y = gcd(a, b);

    return x / y;
}

bool isPer_square(int num)
{
    int x = sqrt(num);
    return ((x * x) == num);
}

#define rep(i, s, e) for (ll i = s; i < e; i++)

bool isprime(ll x)
{
    rep(i, 2, sqrt(x) + 1) if (x % i == 0) return false;
    return x != 1;
}

bool isvowel(char ch) { return (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U'); }

ll powerLL(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<i+n<<endl;
    }
   
    
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // sieve();
    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; test++)
    {
        //cout << "Case #" << test << ": ";
        solve();
    }
    // solve();
    // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

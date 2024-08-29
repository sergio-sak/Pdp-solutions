#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <bit>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <inttypes.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3")

#define EPS 1e-9
#define PI acos(-1)
#define MAXN 1'000'005
#define MOD 1'000'000'007
#define INF 1'000'000'000'000

#define ll int64_t
#define int int32_t
#define short int16_t

#define si(n) scanf("%" PRId32, &n);
#define sl(n) scanf("%" PRId64, &n);
#define sc(n) scanf("%c", &n);
#define sf(n) scanf("%f", &n);
#define slf(n) scanf("%lf", &n);

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dbg(x) std::cerr << #x << ": " << x << std::endl;

typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<int>> dvi;
typedef std::vector<std::vector<ll>> dvll;
typedef std::unordered_map<int , int> mi;
typedef std::unordered_map<ll , ll> mll;

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return a/gcd(a, b) * b;}

int N, K, sum, *arr;

bool checkForAnswer(int ind) {
    for(int i = 0; i < N; ++i) if(arr[i] > ind) return false;

    int k = 1, sum = 0;

    for(int i = 0; i < N; ++i) {
        sum += arr[i];
        if(sum > ind) {
            k++;
            sum = arr[i];
        }
    }

    return k <= K;
}

signed main()
{
    si(N); si(K);
    arr = new int[N];

    for(int i = 0; i < N; ++i) {
        si(arr[i]);
        sum += arr[i];
    }

    int l = 0, r = sum;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(checkForAnswer(mid)) r = mid;
        else l = mid+1;
    }

    printf("%d\n", r);
    return 0;
}
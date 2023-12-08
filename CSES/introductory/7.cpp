#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define maxn 100000000000017
#define endl "\n"
#define INF (ll)1e18
#define mk make_pair
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vpi vector<pi>
#define all(v) v.begin(), v.end()
#define srt(v) sort(all(v))
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define pb push_back
#define rep(i, k, n) for (int i = k; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
typedef long double ld;

void  input(vi &vec){
    for(auto &i: vec){
        cin>>i;
    }
}
void print(vi &vec){
    for(auto &i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
}
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/


void solve()
{
    ll n;
    cin>>n;
    vi arr1;
    vi arr2;
    ll cnt1=0;
    ll cnt2=0;
    bool first=false;
     
    if(n%4==0 && n%8!=0 && n!=4){
        cout<<"YES"<<endl;
        arr1.push_back(1);
        arr2.push_back(2);
        arr1.push_back(4);
        arr2.push_back(3);
        for(ll i=5;i<=n;i++){
            if(i%4==0 || (i-1)%4==0){
                arr1.push_back(i);
            }
            else{
                arr2.push_back(i);
            }
        }
        first=true;
        

    }

    else if(n%8==0){
        cout<<"YES"<<endl;
        arr1.push_back(1);
        arr2.push_back(2);
         
        for(ll i=3;i<=n;i++){
            if((i-1)%2==0 && (i-1)%4!=0){
                arr2.push_back(i);
            }
            else if((i-1)%2==0 && (i-1)%4==0){
                arr1.push_back(i);
            }
            else if(i%4==0){
                arr1.push_back(i);
            }
            else{
                arr2.push_back(i);
            }
        }
         first=true;

    }
    
    else if((n+1)%4==0 && n>3){
        cout<<"YES"<<endl;
        
        arr1.push_back(n);
        arr1.push_back(n-3);
        arr2.push_back(n-1);
        arr2.push_back(n-2);
        for(ll i=1;i<n-3;i++){
            if(i==1 || i==2 ){
                arr1.push_back(i);
                cnt1++;
            }
            else if(cnt1==2 && cnt2!=2){
                arr2.push_back(i);
                cnt2++;
                if(cnt2==2){
                    cnt1=0;
                }
            }
            else if(cnt2==2 && cnt1!=2){
                
                
                arr1.push_back(i);
                cnt1++;
                if(cnt1==2){
                    cnt2=0;
                }
            }
        }
         first=true;
    }
    else if(n==3){
        cout<<"YES"<<endl;
        arr1.push_back(3);
        arr2.push_back(2);
        arr2.push_back(1);
        first=true;
    }
    else if(n==4){
        cout<<"YES"<<endl;
        arr1.push_back(4);
        arr1.push_back(1);
        arr2.push_back(2);
        arr2.push_back(3);
        first=true;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
    if(first){
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        cout<<arr1.size()<<endl;
        for(int i=0;i<arr1.size();i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        cout<<arr2.size()<<endl;
        for(int i=0;i<arr2.size();i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
}

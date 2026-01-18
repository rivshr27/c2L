#include<iomanip>
#include<iostream>
// #include<bits/stdc++.h>
#include<vector>

using namespace std; 


using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvl = vector<vll>;
using vb = vector<bool>;
using vc = vector<char>;

// using iiii = __int128;

// #if defined(__SIZEOF_INT128__)
//     using iiii = __int128;
// #else
//     #error "__int128 not supported on this platform"
// #endif


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define sortall(x) sort(all(x))
#define test() int t; cin >> t; while (t--)
#define f11 for(int i = 0; i < 1; i++)
#define f22 for(int i = 0; i < 1; i++) { for(int j = 0; j < i; j++)}
#define w22(var) int var = 0; while(var--)

const int GOODMOD = 1000000007;
const int INF = 1e9;
bool f1 = true;
bool f2 = false;
auto t0 = 0;
auto t1 = 1;
auto t2 = 2;

class Solution {
  public:
    void get(vector<vector<int>> & ans, vector<int> a, int n, int k, int j)
    {
        if (k == a.size() && n == 0) {
            ans.push_back(a);
            return;
        }
        else {

            for (int i = j; i <= 9; i++) {
                a.push_back(i);
                get(ans, a, n-i, k, i+1);
                a.pop_back();
            }
        }

    }


    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        get(ans, {}, n, k, 1);
        return ans;
    }
};
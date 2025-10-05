
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
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        
        int curr = 0;
        int result = 0;
        
        while (i < j) {
            curr = (j - i) * min(height[i], height[j]);
            result = max(result, curr);
            
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return result;
    }
};
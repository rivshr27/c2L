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
    void helper(int i, int n, vector<string> &mp, vector<int> &arr, string &tmp, 
    vector<string> &ans) {
        if(i == n) {
            ans.push_back(tmp);
            return;
        }
        if(mp[arr[i]] == "") {
            helper(i + 1, n, mp, arr, tmp, ans);
            return;
        }
        for(int k = 0; k < mp[arr[i]].length(); k++) {
            tmp += mp[arr[i]][k];
            helper(i + 1, n, mp, arr, tmp, ans);
            tmp = tmp.substr(0, tmp.size() - 1);
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> mp(10), ans;
        mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string tmp = "";
        helper(0, n, mp, arr, tmp, ans);
        return ans;
    }
};
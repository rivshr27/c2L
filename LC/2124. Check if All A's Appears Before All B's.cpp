#include <bits/stdc++.h>
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

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

#define sortall(x) sort(all(x))
#define test() int t; cin >> t; while (t--)

const int GOODMOD = 1000000007;
const int INF = 1e9;

// Method 1
class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i<s.size()-1; i++){
            if(s[i]=='b' && s[i+1]=='a'){
                return false;
            }
        }
        return true;
    }
};

// Method 2
class Solution {
public:
    bool checkString(string s) {
        return is_sorted(s.begin(), s.end());
    }
};
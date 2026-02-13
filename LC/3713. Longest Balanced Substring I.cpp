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

class Solution {
public:
    bool checkBalance(vector<int>freq){
        int common = 0;
        for(auto v : freq){
            if(v==0) continue;
            if(common ==0){
                common = v;
            }
            if(common!=v){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;
        for(int i = 0; i<s.size(); i++){
            vector<int> freq(26,0);
            for(int j = i; j<n; j++){
                freq[s[j]-'a']++;
                if(checkBalance(freq)){
                    maxL = max(maxL, j-i+1);
                }
            }
        }
        return maxL;
    }
};
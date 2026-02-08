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
#define endl
#define sortall(x) sort(all(x))
#define test() int t; cin >> t; while (t--)

const int GOODMOD = 1000000007;
const int INF = 1e9;


// there will exists only one or zero pair of nums[i] and nums[i+1] such that nums[i]>nums[i+1]
// for rotated one
// for sorted but not rotoated it will be zero
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int val =0;
        for(int i =0 ; i<n;i++){
            if(nums[i]>nums[(i+1)%n])val++;
        }
        cout<<val;
        if(val>1) return false;
        return true;
    }
};

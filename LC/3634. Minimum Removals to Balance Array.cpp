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

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        auto n = nums.size();
        sort(nums.begin(), nums.end());
        int maxii = 0;
        int window = 0;
        for(int i = 0; i<n; i++){
            while(maxii<n && nums[maxii]<= (long long) nums[i]*k){
                maxii++;
            }
            window = max(maxii-i, window);
        }
        return n-window;
    }
};
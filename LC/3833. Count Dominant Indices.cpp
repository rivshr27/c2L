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
    int dominantIndices(vector<int>& nums) {
        int sum = suffixsum(nums);
        int count = 0;
        int n = nums.size();
        for(int i =0; i<nums.size(); i++){
            sum -=nums[i];
            if(i!=n-1){
                if(nums[i]> (sum/(n-(i+1)))){
                    count++;
                }
            }
        }
        return count;
    }
};

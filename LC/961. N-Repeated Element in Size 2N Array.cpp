
#include<iomanip>
#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
#include<set>
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
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i ++){
            if(nums[i] == nums[i + 1]){
                return nums[i];
            }
            if(i + 2 < nums.size() && nums[i] == nums[i + 2]){
                return nums[i];
            }
            if(i + 3 < nums.size() && nums[i] == nums[i + 3]){
                return nums[i];
            }
        }
        return -1;
    }
};
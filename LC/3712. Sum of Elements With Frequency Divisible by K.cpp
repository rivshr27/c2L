#include<bits/stdc++.h>
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
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

//Solution 1
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count1 = 1;
        for(int i = 1; i<n; i++){
            if(nums[i]==nums[i-1]){
                count1++;
            }
            else {
                if((count1%k)==0){

                    sum += (count1)*nums[i-1];
                }
                count1 = 1;
            }
        }
        if((count1%k)==0){
            sum += (count1)*nums[n-1];
        }
        return sum;
    }
};

//Solution 2
class Solution {
public:
    int returnval(vector<int>&nums, int k){
        int sum = 0;
        unordered_map<int, int> count;
        for(int i =0; i <nums.size(); i++){
            count[nums[i]]++;
        }
        for(auto v : count){
            if(v.second%k ==0){
                sum += (v.first*v.second);
            }
        }
        return sum;

    }
    int sumDivisibleByK(vector<int>& nums, int k) {

        return returnval(nums,k);
    }
};
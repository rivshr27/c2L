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

/*
theree possible cases
Case 1: only one charcter contribute to the answer
Case 2: two character contribute to the answer (a,b) , (a,c) , (b,c)
Case 3 : All the three contribute to the answer */

class Solution {
public:
    int helper(string &s , int char1 , int char2){
        int n = s.length();
        unordered_map<int, int>diff;
        int count1 = 0;
        int count2 = 0;
        int maxl = 0;
        for(int i = 0; i<n; i++){
            if(s[i]!=char1 && s[i]!= char2){
                count1 = 0;
                count2 = 0;
                diff.clear();
                continue;
            }
            if(s[i]==char1){
                count1++;
            }
            if(s[i]==char2){
                count2++;
            }
            if(count1==count2){
                maxl = max(maxl , count1+count2);
            }
            int diff1 = count1- count2;
            if(diff.count(diff1)){
                maxl = max(maxl , i - diff[diff1]);
            }
            else{
                diff[diff1] = i;
            }
        }
        return maxl;
    }
    int longestBalanced(string s) {
        //Case 1:
        int n = s.length();
        int count1 = 1;
        int maxl =0;
        for(int i = 1;i <s.size(); i++){
            if(s[i]==s[i-1]){
                count1++;
            }
            else {
                maxl = max(maxl, count1);
                count1 = 1;
            }

        }
        maxl = max(maxl, count1); // out of bounf ke liye
      //Case 2 ""
       maxl = max(maxl , helper(s, 'a' , 'b') );
        maxl = max(maxl , helper(s, 'a' , 'c') );
         maxl = max(maxl , helper(s, 'b' , 'c') );

        // case 3
  int countA= 0;
  int countB = 0;
  int countC = 0;
  unordered_map<string, int> diffMap;
  for(int i =0; i<n ; i++){
    if(s[i]=='a'){
        countA++;
    }
    if(s[i]=='b'){
        countB++;
    }
    if(s[i]=='c'){
        countC++;
    }
    if(countA == countB && countA == countC){
        maxl = max(maxl, countA+countB+countC);
    }
    int diffAB = countA - countB;
    int diffAC = countA - countC;
    string key = to_string(diffAB) + "_ " +to_string(diffAC);
    if(diffMap.count(key)){
        maxl = max(maxl, i- diffMap[key]);
    }
    else {
        diffMap[key] = i;
    }
  }

        return maxl;
    }
};
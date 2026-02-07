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

// total value for the character = remove right side a + left side of b
class Solution {
public:
    int minimumDeletions(string s) {
        int count = INT_MAX;
        int countA = 0;
        int countB = 0;
        for(int i = 0 ; i<s.size(); i++){
            if(s[i]=='a'){
                countA++;
            }

        }
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='a'){
                countA--;
            }
            count = min(count, countA+countB);
            if (s[i]=='b')countB++;
        }
        return count;
    }
};


// the problem is with the ba pair that's it
//if the stack gets that pair we simply remove that
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int count=0;
        stack<int>st;
       for(auto v : s){
        if(!st.empty() && v=='a'&& st.top()=='b'){
            count++;
            st.pop();
        }
       else st.push(v);
       }
       return count;
    }
};
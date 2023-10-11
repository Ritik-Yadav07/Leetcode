//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      int maxDay = bloomDay[0];
        
        int n = bloomDay.size();
        for(int i = 0;i<n;i++)
        {
            maxDay = max(bloomDay[i],maxDay);
        }
        
        if((1LL*M)*(1LL*K) > 1LL*n) return -1;
        
        long long high = maxDay;
        long long low = 1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int possible = 0;
            int count = 0;
            
            for(int i = 0;i<n;i++)
            {
                if(bloomDay[i]>mid)
                {
                    possible+=(count/K);
                    count = 0;
                }
                else{
                    count++;
                }
            }
            possible+=(count/K);
            if(possible<M)
            {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends
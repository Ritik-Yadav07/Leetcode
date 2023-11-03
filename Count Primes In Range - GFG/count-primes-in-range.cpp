//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
        vector<int>sieve(R+1,1);
        sieve[0] = sieve[1] = 0;
        for(long long i=2;i<=R;i++)
        {
            if(sieve[i])
            {
                for(long long j = i*i;j<=R;j+=i)
                {
                    sieve[j] = 0;
                }
            }
        }
        int count = 0;
        for(int i=L;i<=R;i++)
        {
            if(sieve[i]) count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
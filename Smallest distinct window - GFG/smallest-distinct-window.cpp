//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n = str.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[str[i]]++;
        }
        
        int total_different_chars = mp.size();
        
        mp.clear();
        
        int tail =0 ;
        int head = 0;
        int minLength = INT_MAX;
        
        for(head=0;head<n;head++)
        {
          mp[str[head]]++;
          while(mp.size()==total_different_chars)
          {
              minLength = min(minLength,head-tail+1);
              mp[str[tail]]--;
              if(mp[str[tail]]==0) mp.erase(str[tail]);
              tail++;
          }
          
        }
        
        return minLength;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
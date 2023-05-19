//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(),intervals.end());
        int count=0;
         
        int prevEnd = intervals[0][1];
        
         for(int i=1;i<intervals.size();i++)
         {
             int currStart = intervals[i][0];
             int currEnd = intervals[i][1];
             
             if(currStart>=prevEnd)
             {
                 //Not overlapping
                 prevEnd = currEnd;
             }
             else{
                 count++;
                 prevEnd = min(prevEnd,currEnd);
             }
         }
         return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=cardPoints[i];
        }
        
        int count = 0;
        for(int i=0;i<N-k;i++){
            count+=cardPoints[i];
        }
        
        int res = 0;
        res = max(res,sum-count);
        for(int i=N-k;i<N;i++){
            count+=(cardPoints[i]-cardPoints[i-N+k]);
            res = max(res,sum-count);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
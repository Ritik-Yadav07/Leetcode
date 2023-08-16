//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            // approach1
            int size = 2*n;
            vector<int>merged;
            int p=0;
            int q=0;
            
            while(p<n && q<n){
                if(ar1[p]<ar2[q]){
                    merged.push_back(ar1[p]);
                    p++;
                }
                else if(ar1[p]==ar2[q]){
                    merged.push_back(ar1[p]);
                    merged.push_back(ar2[q]);
                    p++;
                    q++;
                }
                else{
                   merged.push_back(ar2[q]);
                   q++;
                }
            }
            
            while(p<n){
                 merged.push_back(ar1[p]);
                    p++;
            }
            while(q<n){
                 merged.push_back(ar2[q]);
                    q++;
            }
            // for(int i=0;i<size;i++){
            //     cout<<merged[i]<<" ";
            // }
            int index = (size/2)-1;
            int sum = merged[index] + merged[index+1];
            return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> addOne(int digits[], int n) {
        // code here
        vector<int>output;
        int carry = 1;

        
        
        for(int i=n-1;i>=0;i--){
            
            int sum = digits[i]+carry;
            if(sum<=9){
                carry = 0;
                output.push_back(sum);
            }else{
                carry = 1;
                output.push_back(0);
            }
        }
        
        if(carry) output.push_back(carry);
        reverse(output.begin(),output.end());
        return output;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.addOne(a, n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends
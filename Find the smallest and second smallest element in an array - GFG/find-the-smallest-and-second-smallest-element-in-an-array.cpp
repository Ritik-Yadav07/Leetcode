//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<int> minAnd2ndMin(int arr[], int n) {
    int smallest = arr[0];
    int second_smallest = INT_MAX;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<second_smallest)
        {
            second_smallest = arr[i];
        }
    }
    if(second_smallest==INT_MAX) return {-1,-1};
    
    return {smallest,second_smallest};
}
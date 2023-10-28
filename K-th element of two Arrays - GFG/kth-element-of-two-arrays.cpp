//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {  
    //   vector<int>arr3;
    //   int i=0;
    //   int j=0;
    //   while(i<n && j<m)
    //   {
    //       if(arr1[i]<arr2[j]){
    //             arr3.push_back(arr1[i]);
    //             i++;
    //       }
    //       else {
    //           arr3.push_back(arr2[j]);
    //           j++;
    //       }
    //   }
       
    //   while(i<n){
    //       arr3.push_back(arr1[i]);
    //       i++;
    //   }
    //   while(j<m){
    //       arr3.push_back(arr2[j]);
    //       j++;
    //   }
       
    //   return arr3[k-1];
        int i=0,j=0;
        int cnt = 0;
        int ele = -1;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                ele = arr1[i];
                cnt++;
                i++;
                if(cnt==k) return ele;
            }
            else{
                ele = arr2[j];
                cnt++;
                j++;
                if(cnt==k) return ele;
            }
        }
        
        while(i<n)
        {
             ele = arr1[i];
             cnt++;
             i++;
             if(cnt==k) return ele;
        }
        
        while(j<m)
        {
            ele = arr2[j];
            cnt++;
            j++;
            if(cnt==k) return ele;
        }
        
        return ele;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
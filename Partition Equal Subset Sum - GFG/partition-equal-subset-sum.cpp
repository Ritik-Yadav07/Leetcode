//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool subsetSum(int arr[],int n,int targetSum){
    bool t[n+1][targetSum+1];
    memset(t,false,sizeof(t));
    //initialisation
    for(int i=0,j=0;i<n+1;i++){
        t[i][j]=true;
    }
    //choices
    for(int i=1;i<n+1;i++){
        
        for(int j=1;j<targetSum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j] );
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][targetSum];
}




    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            //odd sum
            return false; //odd sum array can not divided into equal sum
        }else{
            //ie even sum
            //now this is similiar to subset sum dp problem but target sum here is arraysum/2
            //ie we have to check if there is any subset whose sum is equal to arraysum/2 or not
            return subsetSum(arr,N,sum/2);
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
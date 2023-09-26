//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        //  same as N meetings in a room but we to store index also here to store output
        
        vector<int>ans;
        vector<pair<pair<int,int>,int>>arr(N);
        for(int i =0;i<N;i++)
        {
            arr[i] = {{F[i],S[i]},i};
        }
        
        sort(arr.begin(),arr.end());
        
        int lastMeetingFinished = arr[0].first.first;
        ans.push_back(arr[0].second+1);
        
        for(int i = 1;i<N;i++)
        {
            int start = arr[i].first.second;
            if(start>lastMeetingFinished)
            {
                ans.push_back(arr[i].second+1);
                lastMeetingFinished = arr[i].first.first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
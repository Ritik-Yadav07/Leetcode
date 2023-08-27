//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void backTrack(int start,vector<int>arr,vector<int>&tempList,vector<vector<int>>&res){
        res.push_back(tempList);
        
        for(int i=start;i<arr.size();i++){
            if(i>start && arr[i]==arr[i-1]) continue;
            tempList.push_back(arr[i]);
            backTrack(i+1,arr,tempList,res);
            tempList.pop_back();
        }
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>>res;
        vector<int>tempList;
        sort(arr.begin(),arr.end());
        backTrack(0,arr,tempList,res);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        unordered_map<int,int>row[9];
        unordered_map<int,int>col[9];
        unordered_map<int,int>grid[9];
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int num=mat[i][j],k=i/3*3+j/3;
                if(num!=0 && (row[i][num]++>0 || col[j][num]++>0 || grid[k][num]++>0))
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
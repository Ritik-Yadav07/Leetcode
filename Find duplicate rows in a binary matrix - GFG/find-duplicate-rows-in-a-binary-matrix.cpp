//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{ 
    // Your code here
    unordered_map<string,int>mp;
    vector<int>ans;
    
    for(int row = 0;row<M;row++)
    {
        string temp = "";
        for(int col=0;col<N;col++)
        {
            temp+=(to_string(matrix[row][col]));
            
        }
        temp+="*";
        if(mp.find(temp)!=mp.end())
        {
            //ie this row is already present so it is duplicate of someone
            ans.push_back(row);
        }
        else{
            //this is disnict row
            mp[temp] = row;
        }
    }
    return ans;
} 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends
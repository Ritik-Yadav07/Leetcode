//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int row=matrix.size();
        int col =matrix[0].size();
        int count =0;
        int total =row*col;
         //// all index 
        
        int startingrow=0;
        int startingcol=0;
        int endingrow=row-1;
        int endingcol=col-1;
        
        while(count<total)
        {
            for(int i=startingcol;count<total && i<=endingcol; i++)
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            
            for(int i=startingrow;count<total && i<=endingrow; i++)
            {
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            
            for(int i=endingcol;count<total && i>=startingcol; i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            
            for(int i=endingrow;count<total && i>=startingrow; i--)
            {
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
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
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
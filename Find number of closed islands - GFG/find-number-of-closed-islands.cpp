//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int row,int col,int N,int M,vector<vector<int>>& matrix)
    {
        matrix[row][col]=0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && matrix[nrow][ncol]==1)
            {
                dfs(nrow,ncol,N,M,matrix);
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        
        //Boundary DFS
        //1-->land, 0-->water
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(i==0 || j==0 || i==N-1 || j==M-1)
                {
                    if(matrix[i][j]==1)
                    {
                        dfs(i,j,N,M,matrix);
                    }
                    
                }
            }
        }
        //Now call dfs in whole grid
        int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==1)
                {
                    count++;
                    dfs(i,j,N,M,matrix);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
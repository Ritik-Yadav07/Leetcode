//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &m)
    {
        // code here 
        // int row=matrix.size();
        // int col=matrix[0].size();
        
        // int dummyCol[col];
        // int dummyRow[row];
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(matrix[row][col]==1){
        //             dummyCol[j]=1;
        //             dummyRow[i]=1;
        //         }
        //     }
        // }
        
        // for(int i=0;i<row;i++){
        //   for(int j=0;j<col;j++){
        //       if(dummyRow[i]==1 || dummyCol[j]==1){
        //           matrix[i][j]=1;
        //       }
        //   }
        // }
         int n1=m.size();

        int n2=m[0].size();

        int row[n1],col[n2];

        for(int i=0;i<n1;i++)

        {

            for(int j=0;j<n2;j++)

            {

                if(m[i][j]==1)

                {

                    row[i]=1;

                    col[j]=1;

                }

            }

        }

        for(int i=0;i<n1;i++)

        {

            for(int j=0;j<n2;j++)

            {

                if(row[i]==1||col[j]==1)

                {

                    m[i][j]=1;

                }

            }
            
        }
            
      
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
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends
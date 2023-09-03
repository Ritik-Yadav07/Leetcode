//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i=0;i<n;i++)
        {
            bool isPossibleCelebrity = true;
            
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(M[i][j]==1)
                    { //means he know someone
                      
                        isPossibleCelebrity = false;
                        break;
                    }
                }
            }
            
            if(isPossibleCelebrity==true)
            {
                //i.e it is confirmed that he doesnot know anyone
                //so check if all knows him i.e. coloumn for that person
                int col = i;
                for(int row=0;row<n;row++)
                {
                    if(row!=col)
                    {
                        if(M[row][col]==0)
                        {
                            //someone is not knows him
                            isPossibleCelebrity = false;
                            break;
                        }
                    }
                }
            }
            
            if(isPossibleCelebrity==true)
            {
                //ie fulfilled both criterias so he is celebrity for sure!
                return i;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
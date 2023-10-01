//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&matrix){
        // Code here
        vector<int>res;
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n==1){
            for(int col=0;col<m;col++) res.push_back(matrix[0][col]);
        }
        else if(m==1){
             for(int row=0;row<n;row++) res.push_back(matrix[row][0]);
        }
        else{
            for(int col=0;col<m;col++) res.push_back(matrix[0][col]);
            for(int row=1;row<n-1;row++){
                
                    res.push_back(matrix[row][0]);
                    res.push_back(matrix[row][m-1]);
                
            }
            
            for(int col=0;col<m;col++) res.push_back(matrix[n-1][col]);
          
        }
    
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
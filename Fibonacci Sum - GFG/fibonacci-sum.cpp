//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    
 const int mod = 1e9+7;
 const int sz = 2;
struct Mat{
    
    long long int m[sz][sz];
    Mat(){
    	memset(m,0,sizeof(m));
    }

    void identity(){
    	for(int i=0;i<sz;i++)
    	{
    		m[i][i] = 1;
    	}
    }

    Mat operator*(Mat a){
    		Mat res;
    		for(int i=0;i<sz;i++)
    		{
    			for(int j=0;j<sz;j++)
    			{
    				for(int k=0;k<sz;k++)
    				{
    					res.m[i][j]+=(m[i][k]*a.m[k][j]);
    					res.m[i][j]%=mod;
    				}
    			}
    		}
    		return res;
    }
};

class Solution{
public:

long long int Fib(long long int n)
{
		Mat res;
		res.identity();
		Mat T;
		T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;

		if(n<=2) return 1;

		//for T^(n-2) we have to decrease n by 2
		n-=2;

		while(n)
		{
			if(n&1) res = res*T;
			T = T*T;
			n/=2;
		}

		return (res.m[0][0] + res.m[0][1])%mod;
}
    
    long long int fibSum(long long int N){
        //code here
        
        
        return (Fib(N+2)%mod-1+mod)%mod;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
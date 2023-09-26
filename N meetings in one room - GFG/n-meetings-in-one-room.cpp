//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // vector<pair<int,int>>arr(n);
        // for(int i = 0;i<n;i++)
        // {
        //     arr[i] = {start[i],end[i]};
        // }
        
        // sort(arr.begin(),arr.end());
        
        // priority_queue<int,vector<int>,greater<int>>minHeap;
        // minHeap.push(arr[0].second);
        // int meeting = 0;
        
        // for(int i = 1;i<n;i++)
        // {   
        //     if(arr[i]==arr[i-1]) continue;
        //     if(minHeap.top()>=arr[i].first)
        //     {
        //         minHeap.pop();
        //     }
        //     else{
        //         meeting++;
        //     }
            
        //     minHeap.push(arr[i].second);
        // }
        
        // return meeting;
        
        vector<pair<int,int>>arr(n);
        for(int i = 0;i<n;i++)
        {
            arr[i] = {end[i],start[i]};
        }
        
        sort(arr.begin(),arr.end());
        int meeting =1;
        int lastMeetingFinish = arr[0].first;
        
        for(int i = 1;i<n;i++)
        {
            int start = arr[i].second;
            if(start>lastMeetingFinish)
            {
                meeting++;
                lastMeetingFinish = arr[i].first;
            }
        }
        
        return meeting;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
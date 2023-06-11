//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int cnt=0;
  void merge(vector<int>&nums,int low,int mid,int high)
    {
            vector<int>temp; //temporary array
            int left = low; //starting index of left array
            int right = mid+1; //starting index of right array

            //storing elements in the temporary array in a sorted manner

            while(left<=mid && right<=high)
            {
                if(nums[left]<=nums[right])
                {
                    temp.push_back(nums[left]);
                    left++;
                }
                else {
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            // if elements on the left half are still left
            while(left<=mid)
            {
                 temp.push_back(nums[left]);
                 left++;
            }
            // if elements on the right half are still left
            while(right<=high)
            {
                 temp.push_back(nums[right]);
                 right++;
            }
            // transfering all elements from temporary to nums
            for(int i=low;i<=high;i++)
            {
                nums[i] = temp[i-low];
            }

    }
        void countPairs(vector<int>&nums,int low,int mid,int high)
    {
        int right = mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && nums[i]>(long long int)2*nums[right]) right++;
            cnt+=(right-(mid+1));
        }
    }
        void mergeSort(vector<int>&nums,int low,int high)
    {
        if(low>=high) return;
        int mid = (low+high)/2;

        mergeSort(nums,low,mid); //left half
        mergeSort(nums,mid+1,high); //right half
        countPairs(nums,low,mid,high);
        merge(nums,low,mid,high); //merge sorted halves
    }
    
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        //Brute force
    //     int count = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j = i+1;j<n;j++)
    //         {
    //             if(arr[i]>2*arr[j]) count++;
    //         }
    //     }
    //     return count;
         
         //Optimal based on merge sort technique
         
         mergeSort(arr,0,n-1);
         return cnt;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
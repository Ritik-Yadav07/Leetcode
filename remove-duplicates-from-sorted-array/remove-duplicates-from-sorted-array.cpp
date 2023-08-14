class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i=0; // store index of unique element

        for(int j=1;j<n;j++)
        {
            if(arr[j]!=arr[i])   // arr[i] is previous unique element
            {
                arr[i+1] = arr[j];
                i++;
            }
        }

        return i+1;
    }
};
class Solution {
private:
    void merge(vector<int>& arr, int start, int end)
    {
        int mid = start + (end - start)/2;
        int len1 = mid - start + 1;
        int len2 = end - mid;

        vector<int> first(len1);
        vector<int> second(len2);

        int mainArrayIndex = start;
        for( int i = 0; i < first.size(); i++ )
        {
            first[i] = arr[mainArrayIndex];
            mainArrayIndex++;
        }

        mainArrayIndex = mid + 1;
        for( int i = 0; i < second.size(); i++ )
        {
            second[i] = arr[mainArrayIndex];
            mainArrayIndex++;
        }

        // Now merging two sorted arrays..
        mainArrayIndex = start;
        int i = 0, j = 0;
        while( i < len1 && j < len2 )
        {
            if(first[i] < second[j])
            {
            arr[mainArrayIndex] = first[i];
            i++; mainArrayIndex++;
            }

            else{
                arr[mainArrayIndex] = second[j];
                j++; mainArrayIndex++;
            }
        } 

        while ( i < len1 )
        {
            arr[mainArrayIndex++] = first[i++];
        }

        while( j < len2) 
        {
            arr[mainArrayIndex++] = second[j++];
        }
    };

    void mergeSort(vector<int>& arr, int start, int end)
    {
        if(start == end)
        {
            return;
        }
        int mid = start + (end-start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, end);
    };
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
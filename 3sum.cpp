Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

----------------------------***-------------------------------------------------
int Solution::threeSumClosest(vector<int> &A, int B) {
    
    // initialising two pointers left and right
    int left, right;
    // min is used to compare the sum with target
    int min = INT_MAX;
    // ans returns the sum of three integers
    int ans;
    // Sort the elements in ascending order
    sort(A.begin(),A.end());
 
    // Now fix the first element one by one 
    // and find the other two elements 
    for (int i = 0; i < A.size() - 2; i++) {
        // left starts from immediate next number
        left = i + 1;
        // right starts from the end of array
        right = A.size() - 1; 
        
        while (left < right) {
            // sum stores the sum of 
            // three numbers
           int sum = A[i] + A[left] + A[right];
            // if difference is less than min 
            // update ans with sum and min with difference
            if (abs(sum-B)<min) {
                ans = sum;
                min = abs(sum - B);
            }
            // if sum is greater than target
            // move towards left
            else if (sum > B)
                right--;
            // else move towards right    
            else 
                left++;
        }
    }
    // returns the ans
    return ans;
}

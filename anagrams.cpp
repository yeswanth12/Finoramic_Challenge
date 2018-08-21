/*Given an array of strings, return all groups of strings that are anagrams. 
Represent a group by a list of integers representing the index in the original list. */

    
----------------------------------****------------------------------------------------------
// function to tell whether strings are anagrams
bool areAnagram(string str1, string str2)
{
    // different size strings are not anagrams
    if (str1.size() != str2.size())
      return false;

    // Create a count array and initialize all values as 0
    int check[26] = {0};
    
    // For each character in input strings,
    // play with the values of array 
    // Note: all inputs are lower-case
    for (int i = 0; str1[i];  i++)
    {
        check[str1[i]-97]++;
        check[str2[i]-97]--;
    }
    // See if there is any non-zero value in count array
    for (int i = 0; i < 26; i++){
        if (check[i])
            return false;
    }
    // if no non-zero value 
    return true;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    vector<vector<int> > ans;
    // mapping the sum to vector of indexes
    map<int,vector<int> > B;
    
    for(int i=0;i<A.size();i++)
    {
        int sum=0; // sum of ascii values of a string
        
        for(int j=0;j<A[i].size();j++){
            sum+=A[i][j]; // calculate for each  
        }
        // if the key with that sum does not exist
        // then push value into the key
        if(B.find(sum)==B.end()){
            B[sum].push_back(i+1);
        } 
        // if the key with that sum already exists
        // check whether they are anagrams
        else if(areAnagram(A[B[sum][0]-1],A[i])){
            B[sum].push_back(i+1);
        }
        // if the key with that sum already exists 
        // and are not anagrams
        else{
            B[sum+1].push_back(i+1);
        }
    }
    // push all the values of map into ans
    for(auto pos=B.begin();pos!=B.end();pos++){
        ans.push_back(pos->second);
    }
    // return ans
    return ans;
}



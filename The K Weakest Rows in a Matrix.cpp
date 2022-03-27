/* You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4]. */

struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first && p1.second<p2.second){
            return true;
        }
        return false;
    }
};

class Solution {
    // calculate the soldier count using binary search
    int calculateSoldierCount(vector<int>& v) {
        int l=0; int h=v.size()-1;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(v[mid]==0) {
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        // We will use max_heap of pairs because we need the top k minimum strength row index(s)
        // each element of max_heap will contain {each row soldier count, that row index}.
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;
        
        // Iterating the matrix and find the total number of soldiers in each row,
        // then push {soldier_count,row_index} to the min_heap
        for(int i=0;i<mat.size();++i){
            max_heap.push({calculateSoldierCount(mat[i]),i});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        vector<int>ans;
        while(max_heap.size()){ // pushing the top k smallest elements of min_heap to "ans"
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
		
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
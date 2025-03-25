// Find Peak Element (2D Matrix)

// class Solution {
//     public:
//         int findMaxInd(vector<vector<int>>& mat, int n, int m, int col){
//             int max_ele = -1;
//             int ind = -1;
//             for(int i=0; i<n; i++){
//                 if(mat[i][col]>max_ele){
//                     max_ele = mat[i][col];
//                     ind = i;
//                 }
//             }
//             return ind;
//         }
//         vector<int> findPeakGrid(vector<vector<int>>& mat) {
//             int n = mat.size();
//             int m = mat[0].size();
//             int low = 0;
//             int high = m-1;
//             while(low<=high){
//                 int mid = low+((high-low)>>1);
//                 int rowInd = findMaxInd(mat, n, m, mid);
//                 int left = (mid-1) >= 0 ? mat[rowInd][mid-1] : -1;
//                 int right = (mid+1) < m ? mat[rowInd][mid+1] : -1;
//                 if(mat[rowInd][mid]>left && mat[rowInd][mid]>right){
//                     return {rowInd, mid};
//                 }else if(mat[rowInd][mid]<left){
//                     high = mid-1;
//                 }else{
//                     low = mid+1;
//                 }
//             }
//             return {-1, -1};
//         }
//     };
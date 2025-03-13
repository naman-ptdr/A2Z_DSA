// Length of the longest subarray with zero Sum

// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.





// int maxLen(int A[], int n)
// {
//     // Your code here
//     unordered_map<int,int> mpp; 
//     int maxi = 0;
//     int sum = 0; 
//     for(int i = 0;i<n;i++) {
//         sum += A[i]; 
//         if(sum == 0) {
//             maxi = i + 1; 
//         }
//         else {
//             if(mpp.find(sum) != mpp.end()) {
//                 maxi = max(maxi, i - mpp[sum]); 
//             }
//             else {
//                 mpp[sum] = i;
//             }
//         }   
//     }

//     return maxi; 
// }


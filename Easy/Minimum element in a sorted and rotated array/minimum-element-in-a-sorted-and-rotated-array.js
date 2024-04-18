//{ Driver Code Starts
//Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let arr = readLine().trim().split(" ").map((x) => parseInt(x));
        let obj = new Solution();
        let res = obj.findMin(arr,n);
        console.log(res);
    }
}

// } Driver Code Ends


//User function Template for javascript
/**
 * @param {number[]} arr
 * @param {number} n
 * @returns {number}
*/

class Solution
{
    //Function to find the minimum element in sorted and rotated array.
    findMin(nums, n)
    {
        //your code here
        let low=0, high=nums.length-1;
    let ans= Infinity;
    while(low<=high){
        let mid = Math.floor((low+high)/2);

        if(nums[low]<=nums[high]){
            ans = Math.min(ans, nums[low])
        }

        if(nums[low]<= nums[mid]){
            ans = Math.min(ans, nums[low])
            low= mid+1
        }
        else{
            ans = Math.min(ans, nums[mid])
            high = mid-1
        }
    }
    return ans;
    }
}
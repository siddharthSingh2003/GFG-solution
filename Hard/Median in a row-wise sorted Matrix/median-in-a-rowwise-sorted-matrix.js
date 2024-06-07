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
        let [R,C] = readLine().trim().split(" ").map((x) => parseInt(x));
        let matrix = new Array(R);
        for(let j = 0;j<R;j++){
            let row = readLine().trim().split(" ").map((x) => parseInt(x));
            matrix[j] = new Array(C);
            for(let y = 0;y<C;y++){
                matrix[j][y] = row[y];
            }
        }
        let obj = new Solution();
        let res = obj.median(matrix, R, C);
        console.log(res);
    }
}
// } Driver Code Ends


//User function Template for javascript
/**
 * @param {number[][]} matrix
 * @param {number} R
 * @param {number} C
 * @returns {number}
*/

class Solution
{
    //Function to find median of the matrix.
    upperBound(arr, x, n){
        let low =0, high = n-1;
        let ans =n;
        
        while(low<=high){
            let mid =Math.floor((low+high)/2);
            if(arr[mid]>x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    countSmallEquals(matrix, m,n,x){
        let cnt = 0;
        for(let i=0; i<m; i++){
            cnt+=this.upperBound(matrix[i], x, n);
        }
        return cnt;
    }
    median(matrix, m, n)
    {
        //your code here
        
        let low= Number.MAX_SAFE_INTEGER, high = Number.MIN_SAFE_INTEGER;
        
        for(let i=0; i<m; i++){
            low = Math.min(low, matrix[i][0]);
            high = Math.max(high, matrix[i][n-1]);
        }
        
        let req = Math.floor((n*m)/2);
        
        while(low<=high){
            let mid = Math.floor((low+high)/2);
            
            let smallEqual = this.countSmallEquals(matrix, m, n, mid);
            
            if(smallEqual <= req) low = mid+1;
            else high= mid-1;
        }
        return low;
    }
}
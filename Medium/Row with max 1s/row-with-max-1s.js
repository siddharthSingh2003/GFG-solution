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
    for(let i=0;i<t;i++)
    {
        let input_line = readLine().split(' ');
        let n = parseInt(input_line[0]);
        let m = parseInt(input_line[1]);
        input_line = readLine().split(' ');
        let matrix = new Array(n);
        for(let i=0;i<n;i++)
        {
            let a = new Array(m);
            for(let j=0;j<m;j++)
            {
                a[j] =parseInt(input_line[i*m+j]);
            }
            matrix[i] = a;
        }
        
        let obj = new Solution();
        let res = obj.rowWithMax1s(matrix, n, m);
        console.log(res);
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[][]} arr
 * @param {number} n
 * @param {number} m
 * @returns {number}
*/
class Solution {
    lowerBound(arr,n,x){
        let low=0, high = n-1;
        let ans = n;
        while(low<=high){
            let mid = Math.floor((low+high)/2);
            
            if(arr[mid]>=x){
                ans = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    rowWithMax1s(arr, n, m){
        // code here
        
        let cntMax=0;
        let index= -1;
        
        for(let i=0; i<n; i++){
            let cntOnes= m-this.lowerBound(arr[i], m, 1);
            
            if(cntOnes>cntMax){
                cntMax= cntOnes;
                index = i;
            }
        }
        return index;
    }
}
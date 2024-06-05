//{ Driver Code Starts
// Initial Template for javascript
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
        let k = parseInt(input_line[1]);
        input_line = readLine().split(' ');
        let stalls = new Array(n);
        for(let i=0;i<n;i++)
        {
            stalls[i] = parseInt(input_line[i]);
        }
        let obj = new Solution();
        let ans = obj.solve(n, k, stalls);
        if(ans==-0)
        ans=0;
        console.log(ans);
    }
}
// } Driver Code Ends


//User function Template for javascript
/**
 * @param {number} n
 * @param {number} k
 * @param {number[]} stalls
 * @returns {number}
*/

class Solution {
    //Function to solve the problem.
    canWePlace (stalls, dist, cows){
        const n = stalls.length;
        let cntCows = 1; 
        let last = stalls[0];
        for (let i=1; i<n ; i++){
            if(stalls[i]-last >= dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
    solve(n, k, stalls) {
        //your code here
    
        stalls.sort((a,b) => a-b);
        
        let low= 1, high = stalls[n-1] - stalls[0];
        
        while(low<=high){
            const mid = Math.floor((low+high)/2);
            if(this.canWePlace(stalls, mid, k)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
        
    }
}
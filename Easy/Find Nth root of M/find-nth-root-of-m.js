//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
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
  for (; i < t; i++) {
    let [n, m] = readLine()
      .trim()
      .split(" ")
      .map((x) => parseInt(x));
    let obj = new Solution();
    let res = obj.NthRoot(n, m);
    console.log(res);
  }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
class Solution {
    func(mid, n, m) {
        let ans = 1;
        
        for (let i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) {
                return 2;
            }
        }
        if (ans === m) return 1;
        return 0;
    }
    
    NthRoot(n, m) {
        let low = 1, high = m;
        
        while (low <= high) {
            let mid = Math.floor((low + high) / 2);
            
            let midN = this.func(mid, n, m);
            
            if (midN === 1) {
                return mid;
            } else if (midN === 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}

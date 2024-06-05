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
        let a = new Array(n);
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        for(let i=0;i<n;i++)
            a[i] = input_ar1[i];
        let m = parseInt(readLine());
        let obj = new Solution();
        console.log(obj.findPages(a, n, m));
        
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} a
 * @param {number} n
 * @param {number} m
 * @returns {number}
*/

class Solution
{
    //Function to find minimum number of pages.
    countStudents(a, pages){
        var n= a.length;
        var students=1;
        var pagesStudent =0;
        for(var i=0; i<n; i++){
            if(pagesStudent+a[i] <= pages){
                pagesStudent+=a[i];
            }
            else{
                students++;
                pagesStudent = a[i];
            }
        }
        return students;
    }
    findPages(a, n, m)
    {
        //your code here
        
        if(m>n) return -1;
        
        var low = Math.max(...a);
        var high = a.reduce((a,b) => a+b, 0);
        
        while(low<=high){
            var mid = Math.floor((low+high)/2);
            var students= this.countStudents(a, mid);
            
            if(students>m){
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        
        
        
        
        
    }
}
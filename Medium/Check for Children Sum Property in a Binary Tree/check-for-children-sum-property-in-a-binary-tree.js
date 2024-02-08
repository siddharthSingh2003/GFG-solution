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

class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function buildTree(str){
   // Corner Case
   if(str.length === 0 || str[0] === "N")
       return null;

   // Create the root of the tree
   let root = new Node(parseInt(str[0]));

   // Push the root to the queue
   let queue = [];
   let start = 0;
   queue.push(root);

   // Starting from the second element
   let i = 1;
   while(queue.length !== start && i < str.length) {

       // Get and remove the front of the queue
       let currNode = queue[start];
       start++;

       // Get the current node's value from the string
       let currVal = str[i];

       // If the left child is not null
       if(currVal !== "N") {

           // Create the left child for the current node
           currNode.left = new Node(parseInt(currVal));

           // Push it to the queue
           queue.push(currNode.left);
       }

       // For the right child
       i++;
       if(i >= str.length)
           break;
       currVal = str[i];

       // If the right child is not null
       if(currVal !== "N") {

           // Create the right child for the current node
           currNode.right = new Node(parseInt(currVal));

           // Push it to the queue
           queue.push(currNode.right);
       }
       i++;
   }

   return root;
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let input_ar1 = readLine().split(' ');
        let root = buildTree(input_ar1);
        let obj = new Solution();
        console.log(obj.isSumProperty(root));
        
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {Node} root
 * @returns {number}
*/

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    isSumProperty(root)
    {
        //your code here
        if (root === null) {
            return 1;
        }
        
        // If the node is a leaf node, return true
        if (root.left === null && root.right === null) {
            return 1;
        }
        
        // Calculate the sum of the data values of the left and right child nodes
        let sumChild = 0;
        if (root.left !== null) {
            sumChild += root.left.data;
        }
        if (root.right !== null) {
            sumChild += root.right.data;
        }
        
        // Check if the data value of the current node is equal to the sum of its children
        if (root.data === sumChild && this.isSumProperty(root.left) && this.isSumProperty(root.right)) {
            return 1;
        } else {
            return 0;
        }
    }
}
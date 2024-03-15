//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
     Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* dummy=new Node(0); 
        Node* tail = dummy; 
    
        while (l1 && l2) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
    
        tail->next = l1 ? l1 : l2;
    
        return dummy->next; 
    }
    Node* reverseList(Node* head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

 
    void sort(Node** headRef) {
        Node* head = *headRef;
        Node* inc=NULL;
        Node* dec=NULL;
        Node* temp=head;
        int i=0;
        Node* h1;
        Node* h2;
        while(temp){
            if(i%2==0){
                if(inc==NULL){
                    inc=temp;
                    h1=inc;
                }
                else{
                    inc->next=temp;
                    inc=temp;
                }
                temp=temp->next;
                inc->next=NULL;
            }
            else{
                if(dec==NULL){
                    dec=temp;
                    h2=dec;
                }
                else{
                    dec->next=temp;
                    dec=temp;
                }
                temp=temp->next;
                dec->next=NULL;
            }
            i++;
        }
        if(h1!=NULL){
            temp=h1;
            while(temp){
                temp=temp->next;
            }
        }
      
        h2=reverseList(h2);
        *headRef=mergeTwoLists(h1,h2);
        
        
        return ;
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends
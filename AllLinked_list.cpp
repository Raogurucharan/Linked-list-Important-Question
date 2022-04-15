/*
  
                                     IMPORTANT LINKED-LIST PROBLEMS
                               ------------------------------------------

*/

1) COMPARE 2 LINKED LIST
`````````````````````````
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
     SinglyLinkedListNode * p = head1;
     SinglyLinkedListNode * q = head2;

    while(p && q) {
        if(p->data != q->data) {
            return 0;
        }
        p = p->next;
        q = q->next;
    }
    if(p || q) {
        return 0;
    }

    return 1;
}

==============================================================

2)MIDPOINT LL
````````````````
Time Complexity : O(n)
Space Complexity : O(1)

Node *midPoint(Node *head)
{
if (head == NULL || head->next == NULL)
{
return head;
}
Node *slow = head, *fast = head->next;
while (fast != NULL && fast->next != NULL)
{ 
slow = slow->next;
fast = fast->next->next;
}
return slow;
}

==============================================================

3) MERGE 2 LINKED LIST  [RECURSION]

```````````````````````````````````

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if (l1==NULL) 
        return l2; 

    if (l2==NULL)          
        return l1; 
  
    if (l1->val < l2->val) { 
        l1->next = mergeTwoLists(l1->next, l2); 
        return l1; 
    } 
    else { 
        l2->next = mergeTwoLists(l1, l2->next); 
        return l2; 
    } 
    }

==============================================================

4) FIND A NODE IN LINKED LIST
````````````````````````````````
	Time=O(N)
	Space=O(1)

int findNode(Node *head, int n)
{
    //Write your code here
 	Node *temp=head;
    int pos=0;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            return pos;
        }
        pos++;
        temp=temp->next;
    }
    return -1;
}

=================================================================

5) REMOVE CONSECUTIVE DUPLICATE FROM LL:
`````````````````````````````````````````

time complexity: O(N)
space complexity: O(1)

Node *remove Duplicates(Node *head)
{
    //Write your code here
    Node *temp=head;
    if(head==NULL)
    {
        return head;  //Base case
    }
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next; // removing  duplicate element part
        }
        else
            temp=temp->next;
    }
    return head;
}

=================================================================

6) LENGTH OF LL
````````````````````
time complexity: O(N)
space complexity: O(1)

int length(Node *head){
    Node * temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
=================================================================

7) REVERSE A LINKED LIST
`````````````````````````
time complexity: O(N)
space complexity: O(N)

Node* reverse(Node* head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    } 
    Node *temp= reverse(head->next);
    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return temp;
}

---------------OR---------------------------------------------
	
/*
Iterative Method 

Initialize three pointers prev as NULL, curr as head and next as NULL.
Iterate through the linked list. In loop, do following. 
// Before changing next of current, 
// store next node 
next = curr->next
// Now change next of current 
This is where actual reversing happens 
curr->next = prev 
// Move prev and curr one step forward 
prev = curr 
curr = next
*/
 void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
=================================================================	

8) DELETE  I th NODE FROM LINKED LIST
```````````````````````````````````
Time Complexity : O(min(I, N))
Space Complexity : O(1)
where I is the position of the node to be
deleted and N is the size of singly linked list

Node *deleteNode(Node *head, int pos)
{
if(head == NULL)
{
return head;
}
if(pos == 0)
{
return head->next;
}
Node* curr = head;
int currPos = 0;
while(curr != NULL && currPos < pos - 1)
{
++currPos;
curr = curr->next;
}
if(curr == NULL || curr->next == NULL)
{
return head;
}
curr->next = curr->next->next;
return head;
}

=================================================================

9) DELETE A NODE FROM LINKED LIST [ USING RECURSION ]
``````````````````````````````````````````````````````

Time Complexity : O(n)
Space Complexity : O(n)
where n is the size of singly linked list

Node *deleteNodeRec(Node *head, int pos)
{
if (head == NULL)
{
return head;
}
if (pos == 0)
{
Node *temp = head;
head = head->next;
delete temp;
return head;
}
Node *smallHead = deleteNodeRec(head->next, pos - 1);
head->next = smallHead;
return head;
}

=================================================================

10) DELETE ALTERNATE NODE IN LINKED LIST
`````````````````````````````````````````
Time complexity: O(N)
Space complexity: O(1)

void deleteAlternateNodes(Node *head)
{
Node *currentNode = head;
while (currentNode != NULL && currentNode->next != NULL)
{
Node *temp = currentNode->next;
currentNode->next = currentNode->next->next;
temp->next = NULL;
delete temp;
currentNode = currentNode->next;
}
}
======================================================================

11) INSERT IN LINKEDLIST
````````````````````````````

Time complexity: O(N)
Space complexity: O(N)
where N is the length of the singly linked list

Node *insertNode(Node *head, int pos, int data) {
if (head == NULL) {
if (pos == 0) {
Node *newnode = new Node(data);
return newnode;
}
return head;
}
Node *newnode = new Node(data);
if (pos == 0) {
newnode->next = head;
head = newnode;
return head;
}
head->next = insertNode(head->next, pos - 1, data);
return head;
}

====================================================================

12) CHECK IF THE LINKED LIST IS PALINDROME OR NOT
``````````````````````````````````````````````````
bool isPalin(Node* head){

        Node* temp= head; 
        stack <int> s;
        while(temp != NULL){
                s.push(temp->data);
                 temp = temp->ptr;
        }
        while(head != NULL ){  
             int i=s.top();
             s.pop();   
            if(head -> data != i){
                return false;
            }
           head=head->ptr;
        }
return true;
}

````````````````````````OR``````````````````````````````````
/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes: 
- Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next) {//split into two halves while the first half can be one-node longer;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode newHead(0); //reverse the second half;
    ListNode *next = NULL, *p = fast;
    while(p) {
        next = p->next;
        p->next = newHead.next;
        newHead.next = p;
        p = next;
    }
    fast = newHead.next; //compare the two lists;
    while(fast) {
        if(fast->val != head->val) return false;
        fast = fast->next;
        head = head->next;
    }
    return fast == NULL;
}
 
========================================================


13) EVEN AFTER ODD LINKED LIST
```````````````````````````````

/*
Sample Input 1 :
1
1 4 5 2 
Sample Output 1 :
1 5 4 2 

Time Complexity : O(n)
Space Complexity : O(1)
where n is the size of singly linked list
*/

Node *evenAfterOdd(Node *head)
{
if (head == NULL)
{
return head;
}
Node *evenHead = NULL, *oddHead = NULL, *evenTail = NULL, *oddTail = NULL;
while (head != NULL)
{
if (head->data % 2 == 0)
{
if (evenHead == NULL)
{
evenHead = head;
evenTail = head;
}
else
{
evenTail->next = head;
evenTail = evenTail->next;
}
}
else
{
if (oddHead == NULL)
{
oddHead = head;
oddTail = head;
}
else
{
oddTail->next = head;
oddTail = oddTail->next;
}
}
head = head->next;
}
if (oddHead == NULL)
{
return evenHead;
}
else
{
oddTail->next = evenHead;
}
if (evenHead != NULL)
{
evenTail->next = NULL;
}

=======================================================================
14) K REVERSE A LNKED LIST IN GROUPS OF K
```````````````````````````````````````````
/*
Time Complexity : O(n)
Space Complexity : O(n)
where n is the size of singly linked list
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5
For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
For k = 3, you should return: 3 -> 2 -> 1 -> 4 -> 5
*/

Node *kReverse(Node *head, int k)
{
if (k == 0 || k == 1)
{
return head;
}
Node* current = head;
Node* fwd = NULL;
Node* prev = NULL;
int count = 0;
/* Reverse first k nodes of linked list */
while (count < k && current != NULL)
{
fwd = current->next;
current->next = prev;
prev = current;
current = fwd;
count++;
}
if (fwd != NULL)
{
head->next = kReverse(fwd, k);
}
return prev;
}

===============================================================================
	
15) SWAP TWO NODES IN LINKED LIST or ALTERNATE NODES
````````````````````````````````````````````````````
/*
Input: head = [1,2,3,4]
Output: [2,1,4,3]
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        while((temp!=NULL)&&(temp->next!=NULL))
        {
            swap(temp->val,temp->next->val);
            temp=temp->next->next;
        }
        return head;
    }
};

~~~~~~~~~~~~~~~OR~~~~~~~~~~~~~~~

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *t1,*t2;
        
        if( head == NULL || head->next == NULL)
            return head;
        
        t1 = head;
        t2 = head->next;
        t1->next = swapPairs(t2->next);
        t2->next = t1;
        return t2;
    }
};

=================================================================
16) Linked List Cycle 
```````````````````````
/*head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) 
            return false;
        
        ListNode *slow = head, *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        }   
        return false;
    }
};
// Floyd cycle algorithm and complexity is at constant time  O(1)

=======================================================================
	

17) Convert Binary Linkedlist to Decimal
```````````````````````````````````````````
int decimalValue(Node *head)
{
    int dec = 0;
    while (head != NULL)
    {
        dec = (dec << 1) + head->data;
        head = head->next;
    }
    return dec;
}

====================================================================

	
18) Remove Duplicates from linked list
`````````````````````````````````````````
void removeDuplicates(Node* head)
{
    Node* previous = nullptr;
    Node* current = head;
 
    //take an empty set to store linked list nodes for future reference
    unordered_set<int> set;
 
    //do till the linked list is empty
    while (current != nullptr)
    {
        //if the current node is seen before, ignore it
        if (set.find(current->data) != set.end()) {
            previous->next = current->next;
        }
        else {
            //insert the current node into the set and proceed to the next node
            set.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
}
	// Time complexity :O(n)
	// Space comlexity :O(n)
=========================================================================

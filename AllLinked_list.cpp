/*
 BY GURUCHARAN RAO

      
                                     IMPORTANT LINKED LIST PROBLEMS
                           --------------------------------------------------------

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

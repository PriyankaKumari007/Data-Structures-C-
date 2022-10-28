/*
Bubble Sort (Iterative) LinkedList
Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 */

int length(Node *head){
    if(head==NULL)
        return 0;
    else
        return(1+length(head->next));
}
Node *bubbleSort(Node *head)
{
    Node *prev, *curr, *r;
    for(int i=1; i<=length(head); i++){
        prev=NULL;
        for(curr=head; curr->next!=NULL; curr=curr->next){
            if(curr->data > curr->next->data){
                r=curr->next;
                if(prev==NULL){
                    curr->next=r->next;
                    r->next=curr;
                    head= r;
                }
                else
                {
                    prev->next=r;
                    curr->next=r->next;
                    r->next=curr;
                }
                curr= r;
            }
            prev= curr;
        }
    }
          return head;
}
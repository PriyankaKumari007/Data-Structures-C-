/*
Even after Odd LinkedList
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 */

Node *evenAfterOdd(Node *head)
{
	Node* oddH=NULL;
    Node* evenH=NULL;
    Node* oddT=NULL;
    Node* evenT=NULL;
    Node* temp=head;
    while(temp!=NULL){
    if(temp->data%2!=0&&oddH==NULL)
    {
        oddH=temp;
        oddT=temp;
        temp=temp->next;
    }
    else if(temp->data%2!=0&&oddH!=NULL)
    {
        oddT->next=temp;
        oddT=temp;
        temp=temp->next;
        
    }
        else  if(temp->data%2==0&&evenH==NULL)
    {
        evenH=temp;
        evenT=temp;
        temp=temp->next;
    }
    else 
    {
        evenT->next=temp;
        evenT=temp;
        temp=temp->next;
        
    }
    }
    if(oddH==NULL)
        return evenH;
        if(evenH!=NULL&&oddH!=NULL)
        {    
    oddT->next=NULL;
    evenT->next=NULL;
    oddT->next=evenH;
        }
    
    return oddH;
}
    

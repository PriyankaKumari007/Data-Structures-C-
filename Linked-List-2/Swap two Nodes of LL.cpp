/*
Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9*/

Node *swapNodes(Node *head, int i, int j)
{
      if (i == j)
            return head;

       Node *prev1  = NULL, *node1 = NULL, *prev2 = NULL, *node2 = NULL;

        //Search for the first node
        int count1 = 0;
        int count2=0;
        node1 = head;
        while (node1 != NULL && count1 != i) {
            prev1 = node1;
            node1 = node1->next;
            count1++;
        }

        //Search for the second node
        node2 = head;
        while (node2 != NULL && count2 != j) {
            prev2 = node2;
            node2 = node2->next;
            count2++;
        }

        if (node1 == NULL || node2 == NULL)
            return head;

        Node  *tail1 = node1->next, *tail2 = node2->next;

        if (node2 == node1->next) {
            if (prev1 != NULL)
                prev1->next = node2;
            node2->next = node1;
            node1->next = tail2;
        }
        else if(node1 == node2->next) {
            if (prev2 != NULL)
                prev2->next = node1;
            node1->next = node2;
            node2->next = tail1;
        }
        else {
            if (prev1 != NULL)
                prev1->next = node2;
            node2->next = tail1;
            if (prev2 != NULL)
                prev2->next = node1;
            node1->next = tail2;
        }

        if (node1 == head)
            head = node2;
        else if (node2 == head)
            head = node1;

        return head;
    }

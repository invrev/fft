//Odd Even Linked List
//
//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note:
//The relative order inside both the even and odd groups should remain as it was in the input. 
//The first node is considered odd, the second node even and so on ...

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//NOTE : modify head pointer
ListNode* oddEvenList(ListNode* head) {

  if(!head) {
    //cout << "No element found" << "\t" ;
    return head;
  }
  ListNode* oddList = head;
  ListNode* evenList = head->next;
  ListNode* tmpEvenList = evenList ;
  while(oddList && oddList->next) {
    //cout << head->val << "\t" ;
    oddList->next = oddList->next->next;
    evenList->next = evenList->next->next;
    oddList = oddList->next; 
    evenList = evenList->next; 
  }
  //evenList->next = NULL; // PLEASE NOTE : NULL is part of HEAD list
  oddList->next = tmpEvenList;

  return head;
}

int main() {
  //1->2->3->4->5->NULL,
  ListNode *head = new ListNode(1); 
  head->next = new ListNode(2); 
  head->next->next = new ListNode(3); 
  head->next->next->next = new ListNode(4); 
  head->next->next->next->next = new ListNode(5); 

  cout << "cALL " << endl;
  ListNode *result = oddEvenList(head);

  cout << "after cALL " << endl;
  while(result != NULL) {
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;

}

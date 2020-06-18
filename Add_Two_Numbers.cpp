/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findit(ListNode* l)
    {//find length of LL 
        int c=0;
        while(l!=NULL)
        {
            c++;
            l=l->next;
        }
        return c;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=0;
        int len1=findit(l1);
        int len2=findit(l2);
       if(len2>len1)
       swap(l1,l2);//swap if l2 is longer than l1
        ListNode* res=l1;
        ListNode* prev=NULL;
        while(l1!=NULL&&l2!=NULL)
        {sum=l1->val+l2->val+carry;
         l1->val=sum%10;//storing sum if l1
         carry=sum/10;
         prev=l1;
    l1=l1->next;
         l2=l2->next;
        }
        //if l1 is longer than l2 adding up remaining element
        while(l1!=NULL)
        {
            sum=l1->val+carry;
            l1->val=sum%10;
            carry=sum/10;
            prev=l1;
            l1=l1->next;
        }
        //if still carry is npt zero make a new node and add it
        if(carry !=0)
        {
            prev->next=new ListNode(carry);
        }
        return res;
    }
};

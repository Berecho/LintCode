/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int i,sum;
        ListNode *list=new ListNode(0);
        ListNode *p=list;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        i=0;sum=0;
        while(l1 != NULL && l2 != NULL){
            sum=l1->val+l2->val+i;
            if(sum>=10){
                sum=sum%10;
                i=1;
            }
            else{
                i=0;
            }
     
            p=p->next=new ListNode(sum);
            l1 = l1->next;
            l2=l2->next;
        }
        
        while(l1!=NULL){
            sum=l1->val+i;
            if(sum>=10){
                sum=sum%10;
                i=1;
            }
            else i=0;
            p=p->next=new ListNode(sum);  
            l1=l1->next;
        }
       while(l2!=NULL){
           sum=l2->val+i;                    
           if(sum>=10){
               sum=sum%10;
               i=1;
           }
           else i=0;
           p=p->next=new ListNode(sum);
           l2=l2->next;         
        }
        if(i!=0){
            p->next=new ListNode(i);
        }
        return list->next;
    }
};

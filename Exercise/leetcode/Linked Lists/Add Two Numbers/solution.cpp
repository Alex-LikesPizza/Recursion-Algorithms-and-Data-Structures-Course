struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *resultHead = result;
        ListNode *list1 = l1, *list2 = l2;

        while(list1 || list2){
            if(!result->next) result->next = new ListNode();
            result = result->next;
            if(!list1){
                result->val += list2->val;
            }
            else if(!list2){
                result->val += list1->val;
            }
            else{
                result->val += list1->val + list2->val;
            }
            if(result->val >= 10) {
                result->val -= 10;
                result->next = new ListNode(1);
            }
            if(list1) list1 = list1->next;
            if(list2) list2 = list2->next;
            
        }
        return resultHead->next;
    }
};
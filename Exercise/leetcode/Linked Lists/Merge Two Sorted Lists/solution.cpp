struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode();
        ListNode* resultHead = result;
        while(list1 && list2){
            if(list1->val <= list2->val){
                result->next = new ListNode(list1->val);
                list1 = list1->next;
                result = result->next;
            }
            else{
                result->next = new ListNode(list2->val);
                list2 = list2->next;
                result = result->next;
            }
        }
        if(list1 == nullptr && list2 != nullptr){
            result->next = list2;
        }
        else if(list1 != nullptr && list2 == nullptr){
            result->next = list1;
        }
        return resultHead->next;
    }
};
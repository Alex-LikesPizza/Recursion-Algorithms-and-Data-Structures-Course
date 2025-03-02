struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* nPtr = head;
        ListNode* delPtr = head;
        ListNode* prevDelPtr = head;
        for(int i = 0; i < n; i++) nPtr = nPtr->next;

        while(nPtr){
            nPtr = nPtr->next;
            delPtr = delPtr->next;
        }
        if(delPtr == prevDelPtr){
            head = head->next;
            delete delPtr;
        }
        else{
            while(delPtr != prevDelPtr->next){
                prevDelPtr = prevDelPtr->next;
            }
            delPtr = delPtr->next;
            delete prevDelPtr->next;
            prevDelPtr->next = delPtr;
        }

        return head;
    }
};
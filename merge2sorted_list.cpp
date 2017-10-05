/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        ListNode *tail = nullptr;
        while (l1 && l2) {
            if (l1->val < l2->val) {            
                if (!result) {
                    result = l1;
                } else {
                    tail->next = l1;
                }
                tail = l1;
                l1 = l1->next;
                tail->next = nullptr;
            } else {
                if (!result) {
                    result = l2;
                } else {
                    tail->next = l2;
                }
                tail = l2;
                l2 = l2->next;
                tail->next = nullptr;
            }
        }
        if (l1) {
            if (!result) {
                result = l1;
            } else {
                tail->next = l1;
            }
        } else {
            if (!result) {
                result = l2;
            } else {
                tail->next = l2;
            }
        }
        return result;
    }
private:
};


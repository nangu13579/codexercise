/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Comparator {
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Comparator> queue;
        ListNode *head, *tail;
        head = tail = nullptr;
        for (auto iter = lists.begin(); iter != lists.end(); ++iter) {
            if (*iter) {
                queue.push(*iter);
            }
        }
        while (!queue.empty()) {
            ListNode *topList = queue.top();
            queue.pop();
            if (head == nullptr) {
                head = topList;
            } else {
                tail->next = topList;
            }
            if (topList->next) {
                if (queue.empty()) {
                    break;
                }
                queue.push(topList->next);
            }
            tail = topList;
            tail->next = nullptr;
        } // eof while
        return head;
    }
};


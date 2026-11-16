
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy node helps handle deletion of the first node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Both pointers start from dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches NULL
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now just before the node to delete
        ListNode* temp = slow->next;

        // Skip the node that needs to be deleted
        slow->next = slow->next->next;

        delete temp;

        // Store the updated head
        head = dummy->next;

        delete dummy;

        return head;
    }
};

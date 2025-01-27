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
    ListNode* swapPairs(ListNode* head) {
        // Base case: If the list is empty or has only one node, no swapping is needed.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Store the second node (the one that will become the new head after swapping).
        ListNode* temp = head->next;

        // Recursively swap the rest of the list starting from the third node.
        // The result of this recursive call will be the new next node for the current head.
        head->next = swapPairs(head->next->next);

        // Make the second node point to the first node, effectively swapping them.
        temp->next = head;

        // Return the new head of the swapped pair, which is the second node.
        return temp;
    }
};
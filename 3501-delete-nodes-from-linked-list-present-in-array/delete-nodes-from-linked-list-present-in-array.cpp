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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> mpp;
        for(auto it : nums) mpp[it] = true;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = head;
        ListNode* curr = dummy;
        while(temp != NULL){
            if(mpp[temp->val] == false){
                ListNode* node = new ListNode(temp->val);
                curr->next = node;
                curr = curr->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
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
    vector<int>list;
    Solution(ListNode* head) {
        ListNode * tmp = head;
        while(tmp)
        {
            list.push_back(tmp->val);
            tmp = tmp->next;
        }
    }
    
    int getRandom() {
        int n = list.size();
        int ind = rand()%n;
        return list[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
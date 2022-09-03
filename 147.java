class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode ans = new ListNode();
        while (head != null) {
            ListNode next = head.next;
            ListNode p = ans;
            while (p.next != null && p.next.val < head.val) {
                p = p.next;
            }
            head.next = p.next;
            p.next = head;
            head = next;
        }

        return ans.next;
    }
}

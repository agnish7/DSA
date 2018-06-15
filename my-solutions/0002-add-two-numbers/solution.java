/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null){
            ListNode result = new ListNode(0);
            return result;
        }
        if(l1 == null){
            return l2;
        }
        if(l2 == null){
            return l1;
        }
        
        ListNode resultHead = new ListNode(0);
        ListNode result = resultHead;
        int carry = 0;
        while(l2 != null || l1 != null){
            if(l1 == null){
                while(l2 != null){
                    result.val = (l2.val + carry) % 10;
                    if(l2.val + carry > 9)
                        carry = 1;
                    else
                        carry = 0;
                    if(l2.next != null){
                        result.next = new ListNode(0);
                        result = result.next;
                    }
                    l2 = l2.next;
                }
                break;
            }
            
            if(l2 == null){
                while(l1 != null){
                    result.val = (l1.val + carry) % 10;
                    if(l1.val + carry > 9)
                        carry = 1;
                    else
                        carry = 0;
                    if(l1.next != null){
                        result.next = new ListNode(0);
                        result = result.next;
                    }
                    l1 = l1.next;
                }
                break;
            }
            
            int sum = l1.val + l2.val + carry;
            result.val = sum % 10;
            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            if(l1.next != null || l2.next != null){
                result.next = new ListNode(0);
                result = result.next;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        if(carry == 1)
            if(result != null){
                result.next = new ListNode(1);
            }
        return resultHead;
    }
}

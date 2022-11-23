

namespace LeetCodeCSharp
{
    class RemoveNthNodeFromEndofList
    {
 
        public class ListNode {
            public int val;
            public ListNode next;
            public ListNode(int val=0, ListNode next=null) {
                this.val = val;
                this.next = next;
            }
        }
 
        static public ListNode RemoveNthFromEnd(ListNode head, int n)
        {
            /*
                We start from the first node.
                We want to remove the node on length - n, what is length?
                Could iterate through to figure out the length
                    ListNode node = head
                    length = 1
                    while node.next != null
                        length++
                        node = node.next

                    toRemove = length - n
                    current = 0
                    node = head
                    // 1, 2, 3, 4, 5, 6 
                    while(current < toRemove)
                        node = node.next
                        current++
                    
                    node.next = node.next.next
                    
                    return head    
                        
             */

            // Follow up: Could you do this in one pass?
            // Second solution: single while-loop and a list, shorter runtime, more memory
            if (head == null)
                return head;

            List<ListNode> nodeList = new List<ListNode>();
            nodeList.Add(head);
            while (nodeList[nodeList.Count - 1].next != null)
            {
                nodeList.Add(nodeList[nodeList.Count - 1].next);
            }

            int toRemove = nodeList.Count - n;
            if (toRemove == 0)
            {
                head = head.next;
                return head;
            }

            nodeList[toRemove - 1].next = nodeList[toRemove].next;
            return head;

            // First solution: 2 while-loops, less memory, longer runtime.
            //if (head == null)
            //    return head;
            //
            //ListNode node = head;
            //int length = 1;
            //while(node.next != null)
            //{
            //    length++;
            //    node = node.next;   
            //}
            //
            //if (length == 1)
            //    return null;
            //
            //int toRemove = length - n;
            //if(toRemove == 0)
            //{
            //    head = head.next;
            //    return head;
            //}
            //
            //int current = 1;
            //node = head;
            //while(current < toRemove)
            //{
            //    node = node.next;
            //    current++;
            //}
            //
            //node.next = node.next.next;
            //
            //return head;
        }

        /*
            Remove the Nth node from the list and return the head.
            Constraints:
                The number of nodes in the list is sz.
                1 <= sz <= 30
                0 <= Node.val <= 100
                1 <= n <= sz
         */
    }
}

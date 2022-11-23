// See https://aka.ms/new-console-template for more information

using LeetCodeCSharp;
RemoveNthNodeFromEndofList.ListNode node5 = new RemoveNthNodeFromEndofList.ListNode(5, null);
RemoveNthNodeFromEndofList.ListNode node4 = new RemoveNthNodeFromEndofList.ListNode(4, node5);
RemoveNthNodeFromEndofList.ListNode node3 = new RemoveNthNodeFromEndofList.ListNode(3, node4);
RemoveNthNodeFromEndofList.ListNode node2 = new RemoveNthNodeFromEndofList.ListNode(2, node3);
RemoveNthNodeFromEndofList.ListNode node1 = new RemoveNthNodeFromEndofList.ListNode(1, node2);

void PrintNodeList(RemoveNthNodeFromEndofList.ListNode head)
{
    RemoveNthNodeFromEndofList.ListNode node = head;
    do
    {
        Console.Write(node.val.ToString() + ", ");
        node = node.next;
    } while (node != null);
    Console.WriteLine();
}

PrintNodeList(node1);
RemoveNthNodeFromEndofList.RemoveNthFromEnd(node1, 2);
PrintNodeList(node1);
RemoveNthNodeFromEndofList.RemoveNthFromEnd(node1, 4);
PrintNodeList(node1);



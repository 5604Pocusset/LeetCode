# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def display(self):
        print self.val
        if (self.next != None):
            self.next.display()

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
            
        second = head.next

        odd_tail = head
        even_tail = second
        while even_tail != None:
            if even_tail.next == None:
                even_tail.next = None
                break
            else:
                odd_tail.next = even_tail.next
                even_tail.next = even_tail.next.next
                odd_tail = odd_tail.next
                even_tail = even_tail.next

            # print "Steps: "
            # head.display()

        odd_tail.next = second

        return head

head = ListNode(1)
p = head
for i in range(2, 7):
    q = ListNode(i)
    p.next = q
    p = q

print "Print before"
head.display()

s = Solution()
head = s.oddEvenList(head)

print "Print after"
head.display()
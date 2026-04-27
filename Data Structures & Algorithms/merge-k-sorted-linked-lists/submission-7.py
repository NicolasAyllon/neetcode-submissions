# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class NodeWrapper:
    def __init__(self, node):
        self.node = node
    
    def __lt__(self, other):
        return self.node.val < other.node.val

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Create a min heap and push the heads of all lists into the heap
        minHeap = []
        for head in lists:
            heapq.heappush(minHeap, NodeWrapper(head))

        # Create result list
        placeholder_head = ListNode()
        tail = placeholder_head # The last node in the list, or the placeholder head (if the list is empty)

        # While the heap is not empty
        while minHeap:
            # Pop the smallest wrapped node (wnode), save it, and push the next one (if any) into the heap
            wnode = heapq.heappop(minHeap)
            next_node = wnode.node.next
            if next_node is not None:
                heapq.heappush(minHeap, NodeWrapper(next_node))

            # Append the node to the merged list
            tail.next = wnode.node
            tail = wnode.node

            print(wnode.node.val)

        # Finally return the head of the merged list, which is the node after the placeholder_head
        return placeholder_head.next



        

        
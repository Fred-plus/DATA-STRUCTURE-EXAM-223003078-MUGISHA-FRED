
from collections import deque

class InventoryQueue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        return self.queue.popleft() if self.queue else None

# Example usage
inventory_queue = InventoryQueue()
inventory_queue.enqueue("Order 1")
inventory_queue.enqueue("Order 2")
print(inventory_queue.dequeue())
    
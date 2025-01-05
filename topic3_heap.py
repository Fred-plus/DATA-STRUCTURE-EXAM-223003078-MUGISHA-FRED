
import heapq

class InventoryHeap:
    def __init__(self):
        self.heap = []

    def add_item(self, item):
        heapq.heappush(self.heap, item)

    def get_highest_priority(self):
        return heapq.heappop(self.heap) if self.heap else None

# Example usage
inventory = InventoryHeap()
inventory.add_item((1, "Milk"))
inventory.add_item((3, "Rice"))
inventory.add_item((2, "Chicken"))
print(inventory.get_highest_priority())
    

class BSTNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key, value):
        if not self.root:
            self.root = BSTNode(key, value)
        else:
            self._insert(self.root, key, value)

    def _insert(self, node, key, value):
        if key < node.key:
            if node.left:
                self._insert(node.left, key, value)
            else:
                node.left = BSTNode(key, value)
        else:
            if node.right:
                self._insert(node.right, key, value)
            else:
                node.right = BSTNode(key, value)

    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(f"{node.key}: {node.value}")
            self.inorder_traversal(node.right)

# Example usage
bst = BST()
bst.insert(1, "Order 1")
bst.insert(3, "Order 3")
bst.insert(2, "Order 2")
bst.inorder_traversal(bst.root)
    
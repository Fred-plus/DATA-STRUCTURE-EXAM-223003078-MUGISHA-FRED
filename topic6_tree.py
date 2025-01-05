
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        print(" " * level * 2 + self.data)
        for child in self.children:
            child.display(level + 1)

# Example usage
root = TreeNode("Restaurant Chain")
branch1 = TreeNode("Branch 1")
branch2 = TreeNode("Branch 2")
root.add_child(branch1)
root.add_child(branch2)
root.display()
    
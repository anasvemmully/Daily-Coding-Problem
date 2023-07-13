
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(node):
    pass


def deserialize(string):
    pass


node = Node('root', Node('left', Node('left.left')), Node('right'))


print(node.val)
# assert deserialize(serialize(node)).left.left.val == 'left.left'
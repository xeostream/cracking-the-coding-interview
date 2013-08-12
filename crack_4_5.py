class BinaryTree(object):
	"""docstring for BinaryTree"""
	def __init__(self, data):
		self.data = data
		self.parent = self.left = self.right = None

def addTree(tnode, data):
	if tnode is None:
		tnode = BinaryTree(data)
	elif tnode.data > data:
		tnode.right = addTree(tnode.right, data)
		tnode.right.parent = tnode
	elif tnode.data < data:
		tnode.left = addTree(tnode.left, data)
		tnode.left.parent = tnode
	return tnode

def returnLeft(tnode):
	if tnode.left is not None:
		returnLeft(tnode.left)
	else:
		return tnode

def successor(tnode):
	if tnode is None: return None
	if tnode.right is not None: return returnLeft(tnode.right)
	parent = tnode.parent
	while parent.data <= tnode.data:
		parent = tnode.parent
	return parent

def printTree(tnode):
	if tnode is not None:
		print tnode.data
		printTree(tnode.left)
		printTree(tnode.right)
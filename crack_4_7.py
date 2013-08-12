class BinaryTree(object):
	"""docstring for BinaryTree"""
	def __init__(self, data):
		self.data = data
		self.hash = 3 * self.data
		self.parent = self.left = self.right = None

def addTree(tnode, data):
	if tnode is None:
		tnode = BinaryTree(data)
	elif tnode.data > data:
		tnode.right = addTree(tnode.right, data)
		tnode.right.parent = tnode
		tnode.hash += tnode.right.data * 5
	elif tnode.data < data:
		tnode.left = addTree(tnode.left, data)
		tnode.left.parent = tnode
		tnode.hash += tnode.left.data * 7
	return tnode

def printTree(tnode):
	if tnode is not None:
		print 'data: %i hash: %i' %(tnode.data, tnode.hash)
		printTree(tnode.left)
		printTree(tnode.right)

def isSonTree(tnode1, tnode2):
	if tnode1.hash == tnode2.hash:
		return True
	elif tnode1.hash > tnode2.hash:
		return isSonTree(tnode1.left, tnode2) or isSonTree(tnode1.right, tnode2)
	else:
		return isSonTree(tnode1, tnode2.left) or isSonTree(tnode1, tnode2.right)
	if tnode1 is None or tnode2 is None:
		return False
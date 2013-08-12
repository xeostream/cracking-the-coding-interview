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

def printTree(tnode):
	if tnode is not None:
		print tnode.data
		printTree(tnode.left)
		printTree(tnode.right)

def printAdd(tnode, add):
	if tnode.data >add:
		printAdd(tnode.left, add)
		printAdd(tnode.right, add)
	elif tnode.data = add:
		print tnode.data
	else:
		if printSon(tnode.left, add-tnode.data) or printSon(tnode.right, add-tnode.data):
			print tnode.data

def printSon(tnode, add):
	if tnode.data > add:
		return False
	elif tnode.data == add:
		print tnode.data
		return True
	else:
		if printSon(tnode.left, add-tnode.data) or printSon(tnode.right, add-tnode.data):
			print tnode.data
			return True
		else:
			return False
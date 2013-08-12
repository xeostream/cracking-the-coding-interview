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

def findAncestor(tnode1, tnode2):
	if tnode1 is None or tnode2 is None or tnode1 == tnode2:
		return False
	else:
		temp = {}
		while tnode1:
			temp[tnode1] = True
			tnode1 = tnode1.parent
		while tnode2:
			if temp[tnode2] and temp[tnode2]:
				return tnode2
			tnode2 = tnode2.parent

def father(tnode1, tnode2):
	if tnode1 is None or tnode2 is None:
		return False
	if tnode1 == tnode2:
		return tnode1
	return father(tnode1.left, tnode2) or father(tnode1.right, tnode2)

def findAncestor1(tnode1, tnode2):
	if tnode1 is None or tnode2 is None:
		return False
	if tnode1 == tnode2:
		return tnode1.parent
	while not father(tnode1, tnode2):
		tnode1 = tnode1.parent

#for node has not parent node
def findAncestor2(root, tnode1, tnode2):
	if root is None or tnode1 is None or tnode2 is None:
		return False
	if root and father(root, tnode1) and father(root, tnode2):
		return findAncestor2(root.left, tnode1, tnode2) or findAncestor2(root.right, tnode1, tnode2) \
		if (findAncestor2(root.left, tnode1, tnode2) or findAncestor2(root.right, tnode1, tnode2)) \
		else root

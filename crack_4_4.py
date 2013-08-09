class BinaryTree(object):
	"""docstring for BinaryTree"""
	def __init__(self, data):
		self.data = data
		self.left = self.right = None

def addTree(tnode, data):
	if tnode is None:
		tnode = BinaryTree(data)
	elif tnode.data > data:
		tnode.right = addTree(tnode.right, data)
	elif tnode.data < data:
		tnode.left = addTree(tnode.left, data)
	return tnode

def printTree(tnode):
	if tnode is not None:
		print tnode.data
		printTree(tnode.left)
		printTree(tnode.right)

def levelOrder(tnode, n, result, results):
	if n == 0 and tnode is not None:
		result.append(tnode)
	elif len(results[n-1]) != 0:
		for node in results[n-1]:
			if node.left is not None:
				result.append(node.left) 
			if node.right is not None:
				result.append(node.right) 
	if len(result) != 0:
		results.append(result)
		levelOrder(tnode, n+1, [], results)

test = [1,3,5,7,9,8,6,4,2,0]
results= []
root = None
for data in range(10):
	root = addTree(root, test[data])
levelOrder(root, 0, [], results)
for r in results:
	for re in r:
		print re.data,
	print
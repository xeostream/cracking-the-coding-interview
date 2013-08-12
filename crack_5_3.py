def count_one(x):
	con = 0
	for c in range(32):
		if x & 1:
			con += 1
		x >>= 1
	return con

def nextAndPreview(x):
	y = x
	count_x = count_y = count_one(x)
	while True:
		x += 1
		if count_one(x) == count_x:
			print x
			break
	while True:
		y -= 1
		if count_one(y) == count_y:
			print y
			break

#smart method 
def smart_nextAndPreview(x):
	maxs = mins = x
	max_move = min_move = 0
	while True:
		if maxs & 1 == 0:
			maxs >>= 1
			max_move += 1
		elif maxs & 2 == 2:
			maxs >>= 1
			max_move += 1
		elif maxs & 2 == 0:
			maxs >>= 1
			maxs |= 1
			max_move += 1
			maxs <<= max_move
			break
	print maxs
	while True:
		if mins & 1 == 1:
			mins >>= 1
			min_move += 1
		elif mins & 2 == 0:
			mins >>= 1
			min_move += 1
		elif mins & 2 == 2:
			mins >>= 2
			min_move += 2
			mins <<= min_move
			break
		else:
			mins = 0
			break
	for c in range(count_one(x)-count_one(maxs)):
		temp = 1
		temp <<= c
		maxs |= temp
	for c in range(count_one(x)-count_one(mins)):
		temp = 1
		temp <<= c
		mins |= temp
	print maxs, mins

if __name__ == '__main__':
	smart_nextAndPreview(1023)
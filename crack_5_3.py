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
	max_move = 0
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
	for c in range(count_one(x)-count_one(maxs)):
		temp = 1
		temp <<= c
		maxs |= temp
	bit = 0
	while bit < 32 and (mins&1)!=0:
		mins >>= 1
		bit += 1
	while bit < 32 and (mins&1)!=1:
		mins >>= 1
		bit += 1
	mins <<= bit
	if bit == 32: mins = 0
	temp = count_one(x) - count_one(mins)
	x >>= bit
	print temp
	while temp > 0:
		mins = (mins<<1) | 1
		temp -= 1
		bit -= 1
	print bit
	while bit >0:
		mins <<= 1
		bit -= 1
	print maxs, ~(mins)

if __name__ == '__main__':
	smart_nextAndPreview(1023)
test = [[0,1,2,3],
	[1,0,2,3],
	[1,2,0,3],
	[1,2,3,0]]
raw = []
col = []
length = len(test)
for x in xrange(length):
	for y in xrange(length):
		if test[x][y] == 0:
			raw.append(x)
			col.append(y)

for x in raw:
	for y in xrange(length):
		test[x][y] = 0

for y in col:
	for x in xrange(length):
		test[x][y] = 0

for x in xrange(length):
	for y in xrange(length):
		print test[x][y],
	print

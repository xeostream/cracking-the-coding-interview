test = [[1, 2, 3, 4],
		[5, 6, 7, 8],
		[9, 10, 11, 12],
		[13, 14, 15, 16]]

length = len(test)
for x in range(length):
	for y in range(x):
		test[x][y] = test[x][y] ^ test[y][x]
		test[y][x] = test[x][y] ^ test[y][x]
		test[x][y] = test[x][y] ^ test[y][x]

for x in range(int(length/2)):
	for y in range(length):
		test[x][y] = test[x][y] ^ test[length-1-x][y]
		test[length-1-x][y] = test[x][y] ^ test[length-1-x][y]
		test[x][y] = test[x][y] ^ test[length-1-x][y]

for x in test:
	for y in x:
		print y,
	print

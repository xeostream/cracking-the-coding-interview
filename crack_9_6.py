#encoding = utf-8
'''
the element of test should not equal
'''
import sys
test = [
	[1, 2, 3, 4, 5],
	[3, 7, 8, 9, 11],
	[5, 9, 10, 17, 18],
	[7, 12, 15, 19, 23],
	[9, 13, 16, 20, 25]
	]
row, col = 4, 0
target = 3
while row >= 0 and col < 5:
	if test[row][col] == target:
		print row, col
		sys.exit(0)
	elif test[row][col] < target:
		col += 1
	else:
		row -= 1
print 'None'
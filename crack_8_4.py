def print_list(testlist, result):
	if len(testlist) > 1:
		for c in range(len(testlist)):
			temp = result[:]
			temp.append(testlist[c])
			test = testlist[:]
			test.pop(c)
			print_list(test, temp)
	elif len(testlist) == 1:
		result.append(testlist[0])
		print result

if __name__ == '__main__':
	print_list(['A','B','C'], [])
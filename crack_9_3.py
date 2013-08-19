def search(target, begin, end):
	if begin <= end:
		middle = (begin + end) // 2
		if target == array[middle]:
			return middle
		elif target < array[middle]:
			return search(target, begin, middle-1)
		else:
			if target < array[end]:
				return search(target, middle+1, end)
			elif target == array[end]:
				return end
			else:
				return search(target, begin, middle-1)
	else:
		return -1

if __name__ == '__main__':
	array = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]
	print search(5, 0, 11)
#the free space is enough
def merge(a, b):
	first = 5
	second = len(b)
	third = first + second
	while first > 0 and second > 0:
		if a[first-1] >= b[second-1]:
			a[third-1] = a[first-1]
			first -= 1
		else:
			a[third-1] = b[second-1]
			second -= 1
		third -= 1
	while second > 0:
		a[third-1] = b[second-1]
		third -= 1
		second -= 1
	print a

#free space is not enough
def swap(a, b):
	a = a ^ b
	b = a ^ b
	a = a ^ b
	return a, b

def merge_other(a, b):
	first = len(a)
	second = len(b)
	while first > 0 and second > 0:
		if a[first-1] > b[second-1]:
			a[first-1], b[second-1] = swap(a[first-1], b[second-1])
			for f in range(len(a)-1, 0, -1):
				if a[f-1] > a[f]:
					a[f-1], a[f] = swap(a[f-1], a[f])
			second -= 1
		else:
			second -= 1
	print a + b

if __name__ == '__main__':
	a = [1,3,5,7,9,0,0,0,0,0]
	b = [2,4,6,8,10]
	c = a[:5]
	merge(a, b)
	merge_other(c, b)
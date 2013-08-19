def cmp(a, b):
	a = ''.join(sorted(a))
	b = ''.join(sorted(b))
	if a > b:
		return 1
	elif a == b:
		return 0
	else:
		return -1

test = [ "axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"]
test = sorted(test, cmp)
print test
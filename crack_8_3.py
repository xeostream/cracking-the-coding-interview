import copy

def subset(sets):
	if len(sets) > 1:
		sub = subset(sets[1:])
		temp = copy.deepcopy(sub)
		for s in sub:
			t = s[:]
			t.append(sets[0])
			temp.append(t)
		sub = copy.deepcopy(temp)
		return sub
	elif len(sets) == 1:
		sub = []
		sub.append([])
		sub.append(sets)
		return sub

if __name__ == '__main__':
	test = [1,2,3,4]
	print subset(test)
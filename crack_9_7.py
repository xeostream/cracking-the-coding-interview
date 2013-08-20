def clean(test):
	test.sort()
 	for l in range(len(test)-1):
 		if test[l] == test[l+1]:
 			test[l+1] = 0, 0
 	test = [t for t in test if t != (0, 0)]
 	return test

def sums(test):
 	result, temp = 0, 0
 	array = []
 	for l in range(len(test)-1):
 		if test[l] < test[l+1]:
 			temp += 1
 			result = temp
 		else:
 			if result < temp:
 				result = temp
 			temp = 1
 		array.append(temp)

 	length = len(test)-1
 	while length >= 0:
 		if array[length-1] == result:
 			tem = array[length-1]
 			print test[length],
 			length -= 1
 			while tem > 0:
 				print test[length],
 				tem -= 1
 				length -= 1

if __name__ == '__main__':
	test = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110)]
	test = clean(test)
	sums(test)
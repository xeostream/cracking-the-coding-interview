import sys
def decToBin(dec):
	first = bin(int(dec // 1))[2:]
	dec = dec % 1
	second = []
	while dec != 0:
		dec = dec * 2
		second.append(str(int(dec // 1)))
		dec = dec % 1
		if len(second) + len(first) > 32:
			print 'ERROR'
			sys.exit(0)
	second = ''.join(second)
	print '%s.%s' %(first, second)

if __name__ == '__main__':
	decToBin(17.25)
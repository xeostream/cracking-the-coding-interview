def replace(N=1024, M=21, i=2, j=6):
	temp = (1 << i) -1
	temp &= N
	result = ((N >> (j+1)) << (j+1)) | (M << i) | temp
	print result

if __name__ == '__main__':
	replace()
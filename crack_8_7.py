def cents(number, key):
	global result
	if number > 0:
		temp = 0
		if key == 25:
			temp = cents(number-25, 25) + cents(number-10, 10) + cents(number-5, 5) + 1
		elif key == 10:
			temp = cents(number-10, 10) + cents(number-5, 5) + 1
		elif key == 5:
			temp = cents(number-5, 5) + 1
		else:
			temp = 1
		result[number] = temp
		return temp
	elif number == 0:
		return 1
	else:
		return 0

if __name__ == '__main__':
	result = [0] * 26
	print cents(25, 25)
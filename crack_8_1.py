def fib_slow(number):
	if number == 0: return 1
	elif number == 1: return 1
	else:
		return fib_slow(number-1) + fib_slow(number-2)

def fib_fast(number):
	if numbers[number] == 0:
		if number == 0 or number == 1:
			numbers[number] = 1
			return numbers[number]
		else:
			temp = fib_fast(number-1) + fib_fast(number-2)
			numbers[number] = temp
			return numbers[number]
	else:
		return numbers[number]

numbers = [0] * 6
if __name__ == '__main__':
	print fib_fast(5)
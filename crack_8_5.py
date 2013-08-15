'''
the question is so funny
print all valid para list
'''
def valid_para(left, right, result):
    if left == 0 and right == 0:
        print result
    else:
        if left > 0:
            result1 = result[:]
            result1.append('(')
            valid_para(left-1, right, result1)
        if right > left:
            result2 = result[:]
            result2.append(')')
            valid_para(left, right-1, result2)

if __name__ == '__main__':
    valid_para(3, 3, [])

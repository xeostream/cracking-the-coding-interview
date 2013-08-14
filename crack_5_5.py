def count_one(data):
    count = 0
    for x in range(32):
        if data & 1 == 1:
            count += 1    
        data >>= 1
    return count

if __name__ == '__main__':
    print count_one(14 ^ 31)

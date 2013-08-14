def swap_bits(data):
    return ((data & 0x55555555) << 1) | ((data >> 1) & 0x55555555)

if __name__ == '__main__':
    print swap_bits(4)

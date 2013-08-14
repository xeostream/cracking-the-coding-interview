def move(start_x, start_y, end_x, end_y):
    global COUNT
    if start_x == end_x and start_y == end_y:
        COUNT += 1
    elif start_x <= end_x and start_y <= end_y:
        move(start_x+1, start_y, end_x, end_y)
        move(start_x, start_y+1, end_x, end_y)

def move_path(start_x, start_y, end_x, end_y, path):
    if start_x == end_x and start_y == end_y:
        path.append((start_x, start_y))
        print path
    elif start_x <= end_x and start_y <= end_y:
        path.append((start_x, start_y))
        path1, path2 = path[:], path[:]
        move_path(start_x+1, start_y, end_x, end_y, path1)
        move_path(start_x, start_y+1, end_x, end_y, path2)

def move_disable_path(start_x, start_y, end_x, end_y, disable_x, disable_y, path):
    if start_x == end_x and start_y == end_y:
        path.append((start_x, start_y))
        print path
    elif start_x <= end_x and start_y <= end_y:
        if start_x != disable_x or start_y != disable_y:
            path.append((start_x, start_y))
            path1, path2 = path[:], path[:]
            move_disable_path(start_x+1, start_y, end_x, end_y, disable_x, disable_y, path1)
            move_disable_path(start_x, start_y+1, end_x, end_y, disable_x, disable_y, path2)

if __name__ == '__main__':
    COUNT = 0
    move(0, 0, 2, 2)
    print COUNT
    move_path(0,0,2,2,[])
    print '-'*10
    move_disable_path(0,0,2,2,1,1,[])
        

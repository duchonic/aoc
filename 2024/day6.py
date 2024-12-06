
def read_file(file, part):
    with open(file) as file:
        lines = file.readlines()
    return lines


def check_puzzle(data, part):

    map = []
    player = []
    rocks = []
    direction = [0,-1]

    for line in data:
        map.append(list(line.strip()))

    for y, row in enumerate(map):
        for x, index in enumerate(row):
            if map[y][x] == "^":
                player = [x, y]
            elif map[y][x] == "#":
                rocks.append([x, y])


    print("player starts at: ", player)

    on_map = True

    x_max = len(map[0])
    y_max = len(map)

    print("max size x: ", x_max, " y: ", y_max)

    visited = set() 
    loops = set()

    while on_map:

        next_position = player[0] + direction[0], player[1] + direction[1]

        if next_position[0] < 0 or next_position[0] >= x_max or next_position[1] < 0 or next_position[1] >= y_max:
            on_map = False
        elif map[next_position[1]][next_position[0]] == "#":
            if direction == [0, -1]:
                direction = [1, 0]
            elif direction == [1, 0]:
                direction = [0, 1]
            elif direction == [0, 1]:
                direction = [-1, 0]
            elif direction == [-1, 0]:
                direction = [0, -1]
        else:
            if part == 1:
                visited.add((player[0], player[1]))
            else:
                visited.add((player[0], player[1], direction[0], direction[1]))
                
                # check if we can turn right here and end up in a loop
                # first check if we are on a already walked path, same direction
                check_direction = [] 

                if direction == [0, -1]:
                    check_direction = [1, 0]
                elif direction == [1, 0]:
                    check_direction = [0, 1]
                elif direction == [0, 1]:
                    check_direction = [-1, 0]
                elif direction == [-1, 0]:
                    check_direction = [0, -1]

                if (player[0], player[1], check_direction[0], check_direction[1]) in visited:
                    #print("found loop at ", player[0]+direction[0], player[1]+direction[1])
                    loops.add((player[0]+direction[0], player[1]+direction[1]))

                # we have to walk until we hit a rock or get out of bounce
                # if we get on a walked path we found also a loop
                check_path = player

                print("player is at:", player)

                check_visited = set()
                while True:

                    next = check_path[0] + check_direction[0], check_path[1] + check_direction[1]
                    
                    if next[0] < 0 or next[0] >= x_max or next[1] < 0 or next[1] >= y_max:
                        break
                    elif map[next[1]][next[0]] == "#":
                        if check_direction == [0, -1]:
                            check_direction = [1, 0]
                        elif check_direction == [1, 0]:
                            check_direction = [0, 1]
                        elif check_direction == [0, 1]:
                            check_direction = [-1, 0]
                        elif check_direction == [-1, 0]:
                            check_direction = [0, -1]

                    elif (next[0], next[1], check_direction[0], check_direction[1]) in visited:
                        loops.add((player[0]+direction[0], player[1]+direction[1]))
                        break
                    else:
                        check_path = next

                    if (check_path[0], check_path[1], check_direction[0], check_direction[1]) in check_visited:
                        loops.add((player[0]+direction[0], player[1]+direction[1]))
                        break
                    else:
                        check_visited.add((check_path[0], check_path[1], check_direction[0], check_direction[1]))
                

            player = next_position

            if part == 1:
                visited.add((player[0], player[1]))
            else:
                visited.add((player[0], player[1], direction[0], direction[1]))


    if part == 1:
        return len(visited) 

    if part == 2:
        print(loops)
        return len(loops)

def main():

    data = read_file("2024/day6_test.txt", 1)
    assert(check_puzzle(data, 1) == 41)
    part1 = read_file("2024/day6.txt", 1)
    print("part1: ", check_puzzle(part1, 1))

    data = read_file("2024/day6_test.txt", 2)
    assert(check_puzzle(data, 2) == 6)
    part2 = read_file("2024/day6.txt", 2)
    print("part2: ", check_puzzle(part2, 2))


if __name__ == '__main__':
    main()
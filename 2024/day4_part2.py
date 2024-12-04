def read_file():
    map = []
    with open('day4.txt') as file:
        lines = file.readlines()
        for line in lines:
            map.append(list(line.strip()))
    return(map)

def calc_part2(map):
    part2 = 0
    for x in range(1,len(map[0])):
        for y in range(1,len(map)):
            try:
                test = map[y-1][x-1] + map[y-1][x+1] + map[y][x] + map[y+1][x-1] + map[y+1][x+1]
                if test == "MMASS" or test == "SSAMM" or test == "MSAMS" or test == "SMASM":
                    part2 += 1
                    print ("pass", x, y, test)
            except:
                pass
    return part2 

def main():
    print("part2: ", calc_part2(read_file()))

if __name__ == '__main__':
    main()
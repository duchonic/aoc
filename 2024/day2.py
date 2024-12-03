# read a file line by line and split the numbers
def read_file():
    with open('day2.txt') as file:
        lines = file.readlines()
        data = []
        for line in lines:
            data.append(map(int,line.split()))
    return data


def check_line(line):

    up_total = 0
    down_total = 0
    diff_to_high = 0
    diff_to_low = 0

    for i in range(0, len(line)-1):
        if line[i+1] > line[i]:
            up_total += 1
        elif line[i+1] < line[i]:
            down_total += 1
        else:
            diff_to_low += 1
        
        if abs(line[i+1] - line[i]) > 3:
            diff_to_high += 1

    if up_total > 0 and down_total > 0:
        return False
    elif diff_to_high > 0:
        return False
    elif diff_to_low:
        return False
    else:
        return True

def main():
    data = read_file()

    part1 = 0
    for item in data:
        line = list(item)
        if check_line(line):
            part1 += 1

    data = read_file()
    part2 = 0
    for item in data:
        genesis_line = list(item)

        if check_line(genesis_line):
            part2 += 1
        else:
            for i in range(0, len(line)):
                test = genesis_line[:i] + genesis_line[i+1:]
                if check_line(test):
                    part2 += 1
                    break
    
    print("part1: ", part1)
    print("part2: ", part2)

if __name__ == '__main__':
    main()
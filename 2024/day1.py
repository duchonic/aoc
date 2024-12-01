# read day1.txt file line by line

def read_file():

    first = []
    second = []

    with open('day1.txt') as f:
        # a line has two numbers, store them in tow arrays
        lines = f.readlines()
        for line in lines:
            first.append(int(line.split()[0]))
            second.append(int(line.split()[1]))
        
    return first, second

def main():
    lines = read_file()

    # sort the two arrays
    lines[0].sort()
    lines[1].sort()

    # calc the difference between the two arrays
    diff = [abs(a - b) for a, b in zip(lines[0], lines[1])]
    # add up all the diffs
    print("part1: ", sum(diff))

    # iterate over first array, find the number of simillar numbers in the second array
    part2 = 0
    for first in lines[0]:
        count = 0
        for second in lines[1]:
            if second == first:
                count += 1
        
        part2 += first * count
    
    print   ("part2: ", part2)


if __name__ == '__main__':
    main()



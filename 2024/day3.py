import re

def read_file():
    with open('day3.txt') as file:
        lines = file.readlines()
    return lines


def main():
    data = read_file()

    pattern = r'mul\(\d+,\d+\)|do\(\)|don\'t\(\)'

    do = True
    part1 = 0
    for line in data:
        matches = re.findall(pattern, line)
        for match in matches:
            if match == "do()":
                do = True
            elif match == "don't()":
                do = False
            else:
                if do:
                    print("do the match: ", match)
                    number = re.findall("\d+", match)
                    part1 += int( number[0] ) * int(number[1])
            
    print("part2: ", part1)


if __name__ == '__main__':
    main()
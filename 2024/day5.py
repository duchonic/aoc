
import random

def read_file(file, part):
    result = 0
    rules = []
    sequence = []
    with open(file) as f:
        # a line has two numbers, store them in tow arrays
        lines = f.readlines()
        for line in lines:
            values = line.replace("|", " ").replace(",", " ").split() 

            if len(values) == 2:
                single = []
                for v in values:
                    single.append(int(v))
                rules.append(single)
            elif len(values) > 2:
                single = []
                for v in values:
                    single.append(int(v))
                sequence.append(single)
    
            tree = [] 
            for rule in rules:
                point_found = False
                for point in tree:
                    if point[0] == rule[0]:
                        point_found = True
                        point[1].append(rule[1]) 
                        break

                if not point_found:
                    point = [rule[0], [rule[1]]]
                    tree.append(point)

        if part == 2: 
            print(tree)

        if part == 1:
            for seq in sequence:
                neighbour_found = False
                for number in zip(seq[::], seq[1::]):
                    neighbour_found = False
                    for point in tree:
                        if number[0] == point[0]:
                            for value in point[1]:
                                if number[1] == value:
                                    neighbour_found = True
                    if not neighbour_found:
                        break;
                if not neighbour_found:
                    pass
                else:
                    if part == 1:
                        result += seq[int(len(seq)/2)]
        else:
            for seq in sequence:

                test_seq = seq.copy()

                repaired = False
                while True:
                    neighbour_found = False
                    for number in zip(test_seq[::], test_seq[1::]):
                        neighbour_found = False
                        for point in tree:
                            if number[0] == point[0]:
                                for value in point[1]:
                                    if number[1] == value:
                                        neighbour_found = True
                        if not neighbour_found:
                            break;
                    
                    if not neighbour_found:
                        repaired = True
                        #random shuffle the test_seq
                        #print(test_seq)
                        random.shuffle(test_seq)
                    else:
                        if repaired:
                            print(test_seq)
                            print(test_seq[int(len(test_seq)/2)])
                            result += test_seq[int(len(test_seq)/2)]
                        break
    return result 

def main():
    assert(read_file("day5_test.txt", 1) == 143)
    print("part1: ", read_file("day5.txt", 1))

    assert(read_file("day5_test.txt", 2) == 123)
    print("part2: ", read_file("day5.txt", 2))

if __name__ == '__main__':
    main()

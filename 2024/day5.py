
def read_file(file):
    part1 = 0
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
                part1 += seq[int(len(seq)/2)]


    return part1 

    


def main():

    test = read_file("day5_test.txt")

    assert(test == 143)

    part1 = read_file("day5.txt")
    print("part1: ", part1)


if __name__ == '__main__':
    main()



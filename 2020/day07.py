# Read in groups from file
lines = [x.strip() for x in open('day07.txt', 'r').readlines() if x != '']

def part1():
    bags = {}
    q = []
    for l in lines:
        bag, contains = l.split('contain')
        bag = bag.replace('bags','').strip()
        if 'shiny gold' in contains:
            q.append(bag)
            #print(contains)
        bags[bag] = contains
        #print(bag)

    answer = set(q)
    while len(q) != 0:
        nxt = q.pop(0)
        for b in bags:
            if nxt in bags[b]:
                q.append(b)
                answer.add(b)
    print(answer)
    return len(answer)

def part2():
    bags = {}
    q = []
    for l in lines:
        bag, contains = l.split('contain')
        bag = bag.replace('bags','').strip()

        if 'no other bags' in contains:
            bags[bag] = {}
            continue

        contains = contains.split(',')
        contains = [c.replace('bags','').replace('bag','').replace('.','').strip() for c in contains]
        x = {}
        for c in contains:
            x[c[2:].strip()] = int(c.split()[0])
        bags[bag] = x 

    def recurs(bag, bags, level):
        subitems = bags[bag]
        if len(subitems.keys()) == 0:
            return 1

        total = 1
        for s in subitems:
            total += subitems[s] * recurs(s, bags, level + 1) 
        return total

    return recurs('shiny gold', bags, 0)  - 1

print (part1())
print (part2())

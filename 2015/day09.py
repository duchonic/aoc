from random import shuffle

data = """AlphaCentauri to Snowdin = 66
AlphaCentauri to Tambi = 28
AlphaCentauri to Faerun = 60
AlphaCentauri to Norrath = 34
AlphaCentauri to Straylight = 34
AlphaCentauri to Tristram = 3
AlphaCentauri to Arbre = 108
Snowdin to Tambi = 22
Snowdin to Faerun = 12
Snowdin to Norrath = 91
Snowdin to Straylight = 121
Snowdin to Tristram = 111
Snowdin to Arbre = 71
Tambi to Faerun = 39
Tambi to Norrath = 113
Tambi to Straylight = 130
Tambi to Tristram = 35
Tambi to Arbre = 40
Faerun to Norrath = 63
Faerun to Straylight = 21
Faerun to Tristram = 57
Faerun to Arbre = 83
Norrath to Straylight = 9
Norrath to Tristram = 50
Norrath to Arbre = 60
Straylight to Tristram = 27
Straylight to Arbre = 81
Tristram to Arbre = 90""".split('\n')

destinations = set()
routes = list()

for line in data:
    dest = line.split()
    destinations.add(dest[0])
    routes.append(dest[2]+' to '+dest[0]+' = '+dest[4])
    routes.append(dest[0]+' to '+dest[2]+' = '+dest[4])


def calcRoute(route):
    kilometer = 0
    for index, dest in enumerate(route):
        for line in data:
            try:
                if route[index] in line and route[index+1] in line:
                    kilometer += int(line.split()[4])
            except IndexError:
                pass
    return kilometer


test = list(destinations)

minimum = 1000
maximum = 0

for _ in range(1_000_00):
    shuffle(test)
    value = calcRoute(test)

    if value < minimum:
        minimum = value
        print(minimum)
        print(test)

    if value > maximum:
        maximum = value
        print(maximum)
        print(test)

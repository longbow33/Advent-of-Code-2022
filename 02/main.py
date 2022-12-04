def part1(lines):

    sol = 0
    sol2 = 0
    for line in lines:
        if line is '':
            continue
        him = line[0]
        me = line[2]
        print(me+" "+him)
        sol += getPoints(him,me)
        sol2+= getFixedOutcome(him,me)
    sol = [sol,sol2]
    return sol

def getPoints(opp, me):
        if opp == 'A':
            if me == 'X':
                return 4
            elif me == 'Y':
                return 8
            elif me == 'Z':
                return 3

        elif opp == 'B':
            if me == 'X':
                return 1
            elif me == 'Y':
                return 5
            elif me == 'Z':
                return 9

        elif opp == 'C':
            if me == 'X':
                return 7
            elif me == 'Y':
                return 2
            elif me == 'Z':
                return 6

def getFixedOutcome(opp, me):

        if opp == 'A':
            if me == 'X':
                return getPoints(opp,'Z')
            elif me == 'Y':
                return getPoints(opp,'X')
            elif me == 'Z':
                return getPoints(opp,'Y')

        elif opp == 'B':
            if me == 'X':
                return getPoints(opp,'X')
            elif me == 'Y':
                return getPoints(opp,'Y')
            elif me == 'Z':
                return getPoints(opp,'Z')

        elif opp == 'C':
            if me == 'X':
                return getPoints(opp,'Y')
            elif me == 'Y':
                return getPoints(opp,'Z')
            elif me == 'Z':
                return getPoints(opp,'X')

if __name__ == "__main__":

    with open("input.txt","r") as f:
        lines = f.read().split("\n")

    sol1 = part1(lines)
    print(sol1)


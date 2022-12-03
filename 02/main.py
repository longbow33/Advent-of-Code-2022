def part1(lines):

    sol = 0
    for line in lines:
        if line is '':
            continue
        him = line[0]
        me = line[2]
        print(me+" "+him)
        if him == 'A':
            if me == 'X':
                sol+=4
            elif me == 'Y':
                sol+= 8
            elif me == 'Z':
                sol+= 3

        elif him == 'B':
            if me == 'X':
                sol+= 1
            elif me == 'Y':
                sol+= 5
            elif me == 'Z':
                sol+= 9

        elif him == 'C':
            if me == 'X':
                sol+= 7
            elif me == 'Y':
                sol+= 2
            elif me == 'Z':
                sol+= 6
    return sol



if __name__ == "__main__":

    with open("input.txt","r") as f:
        lines = f.read().split("\n")

    sol1 = part1(lines)
    print(sol1)


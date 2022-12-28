import re

def main():
    with open("input.txt","r") as f:
        inp = f.read()

    startComb, directions = inp.split("\n\n")
    startComb = startComb.split("\n")
    startComb.reverse()

    places = []
    conts = []
    for place in range(len(startComb[0])):
        try:
            int(startComb[0][place])
            places.append(place)
        except:
            pass

    for line in startComb[1:]:
        temp = []
        for place in places:
            temp.append(line[place])
        conts.append(temp)

    for line in conts:
        print(line)

    spaces = []
    for i in range(listshape(conts)[1]):
            spaces.append([])
    for i in range(listshape(conts)[1]):
        for j in range(listshape(conts)[0]):
            if conts[j][i] != " ":
                spaces[i].append(conts[j][i])
    print(spaces)
    #print(directions)

def listshape(nlist):
    shapelist = []
    while (1):
        if len(nlist) != 1:
            shapelist.append(len(nlist))
            nlist = nlist[0]
        else:
            return shapelist

if __name__ == "__main__":
    main()

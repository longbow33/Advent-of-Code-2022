def main():
    with open("input.txt","r") as f:
        inp = f.read().split("\n")
    sol = 0
    for line in inp:
        sol+= find_duplicate(line)
    print(sol)
# PART2
    # group lines in 3
    sol2 = 0
    for i in range(len(inp)//3):
        elves = inp[i*3:i*3+3]
        #print(elves)
        for char in elves[0]:
            if char in elves[1] and char in elves[2]:
                badge = char    
        letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" 
        sol2+= letters.index(badge)+1
    print(sol2)

def find_duplicate(line):
    firstHalf = line[:len(line)//2]
    secondHalf = line[len(line)//2:]
    letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" 
    for char in firstHalf:
        if char in set(secondHalf):
            print(char, letters.index(char))
            return letters.index(char)+1

if __name__ == "__main__":
    main()

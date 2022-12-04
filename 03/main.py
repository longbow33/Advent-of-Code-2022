def main():
    with open("input.txt","r") as f:
        inp = f.read().split("\n")
    sol = 0
    for line in inp:
        sol+= find_duplicate(line)
    print(sol)
    
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

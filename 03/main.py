def main():
    with open("input.txt","r") as f:
        inp = f.read().split("\n")
    
    for line in inp:
        find_duplicate(line)
    
    
def find_duplicate(line):
    firstHalf = line[:len(line)//2]
    secondHalf = line[len(line)//2:]
    for char in line:
        if char in set(secondHalf):
            print(char)
            return
           
def prioritize_duplicate(char):
    pass
if __name__ == "__main__":
    main()

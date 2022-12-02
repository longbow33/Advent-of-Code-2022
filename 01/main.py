with open("input.txt","r") as f:
    lines = f.read().split("\n")

highest = 0
currSum = 0
topThree = [0,0,0]
for line in lines:
    if line != "":
      currSum +=int(line)
    else:
        highest = currSum if currSum > highest else highest
        if currSum > min(topThree):
            topThree.remove(min(topThree))
            topThree.append(currSum)
        currSum = 0

print(highest)
print(sum(topThree))


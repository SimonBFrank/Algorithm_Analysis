import random 
n = 100000 #change the size of the file
name = "Descending_100000" #change the name of the file
f = open(name, "w+")
#random.shuffle(range(0,n)) for random arrays
#numberList = list(reversed(range(0,n))) for descending arrays
for i in range(n):
	inputStr = str(numberList[i]) + "\n"
	f.write(inputStr)

f.close()





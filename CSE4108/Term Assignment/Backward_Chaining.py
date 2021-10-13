KB=[['A'],
    ['B'],
    ['C'],
    ['D'],
    ['P','Q'],
    ['C','L','P'],
    ['D','M','P'],
    ['B','L','M'],
    ['A','P','L'],
    ['A','B','L'],
    ['A','D','G'],
    ['G','B','D']]
file=open("store.txt","a+")

running=[]
def backward_chaining(x):
    global KB,running,file
    if x in running:
        file.write("\n" +x+" is already search backtrack needed")
        return
    else:
        running.append(x)
        
    for i in range(len(KB)):
        if len(KB[i])== 1 and KB[i][0]== x:
            file.write("\n" +x+ " found in KB")
            running.remove(x)
            return True
        elif len(KB[i])== 2 and KB[i][1]==x:
            print(",found in KB alternate are there" + KB[i][0] + " => "+ KB[i][1])
            if backward_chaining(KB[i][0]):
                file.write("\n" +KB[i][1] + " is generated")
                return True
            else:
                 file.write(KB[i][1] + " cannot be generated")
                 return False
        elif len(KB[i])== 3 and KB[i][2]== x:
             file.write("\n" + KB[i][0] + " ^ "+ KB[i][1] + " => "+ KB[i][2]+", found in KB")
             if backward_chaining(KB[i][0]) and backward_chaining(KB[i][1]):
                          file.write("\n" +KB[i][2] + " is generated")
                          return True
x=input("Enter goal state: ")
backward_chaining(x)
file.close()

a_file = open("store.txt")
lines = a_file. readlines()
for line in lines:
    print(line)
a_file. close()

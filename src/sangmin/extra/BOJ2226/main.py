N = int(input())
result = 1
if N==1:
    print(0)
elif N==2:
    print(1)
else:
    for i in range(3,N+1):
        if(i%2) :
            result =result + (result-1)
        else :
            result= result + (result+1)
    print(result)

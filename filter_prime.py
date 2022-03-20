def prime_filter(x):
    #print(x)
    i=int(2)
    while(i<=x/2):
        if(x%i==0):
            #print(l)
            return False
        else:
            i=i+1
    if(i==int(x/2 + 1)):
        return True
    #print(l)
l= [3,5,7, 10, 15, 19, 7, 23, 25, 29] 
print("original list:",l)
filtered=list(filter(prime_filter,l))
print("only prime numbers:",filtered)

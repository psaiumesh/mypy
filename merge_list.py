engineers = ['Saketh', 'Jana', 'Vachan', 'Aura'] 
programmers = ['Vachan', 'Sama', 'Dheer', 'Aura', 'Achyu'] 
managers = ['Jana', 'Vachan', 'Dheer', 'Achyu'] 
employees=engineers+programmers+managers
for i in range(len(employees)):
    j=i+1
    while(j<len(employees)):
    #for j in range(i+1,x):
        #print("i is:",i)
        #print("j is :",j)
        if(employees[i]==employees[j]):

            employees.pop(j)
            x=len(employees)
           # print("x is:",x)
        else:
            j=j+1
    #a=a+1
print(employees)

embedded_library = {"Total_books" : 19, "books": [ 
 {"py_books" : 10}, 
 {"c_books" : 5}, 
 {"perl_scripts" : 2}, 
 {"os_books" : 2} 
 ] 
 } 
network_library = {"Total_books" : 15, "books": [ 
 {"py_books" : 2}, 
 {"c++_books" : 2}, 
 {"perl_scripts" : 8}, 
 {"os_books" : 3} 
 ] 
 }
#print(len(embedded_library['books']))
#print(len(network_library['Total_books']))
#if type(embedded_library['Total_books']) is int:
#    print ("hello")
#if type(embedded_library['books']) is list:
#    print("hai")
l1=list(embedded_library.keys())
l2=list(network_library.keys())
for i in range(len(l1)):
    if (str(l1[i]) in network_library):
        continue
    else:
        #d2(str(l1[i]))=0
        network_library.update({str(l1[i]):0})
for j in range (len(l2)):
    if (str(l2[j]) in embedded_library):
        continue
    else:
        embedded_library.update({str(l2[j]):0})
print(embedded_library)
print(network_library)
dict={}
#l=(embedded_library.keys())
for i in embedded_library.keys():
     print( type(embedded_library[i]))
     print("hello",i)
     if (type(embedded_library[i]) is int):
        #print("hello")
        dict[i]=embedded_library[i] + network_library[i]
        #print("hello")
     if(type(embedded_library[i]) is list):
         list1=embedded_library[i]
         print(list1)
         list2=network_library[i]
         print("list2",list2)
         d1={}
         d2={}
         for d in list1:
             for key in d:
                d1[key]=d[key]
         print(d1)
         for d in list2:
            for key in d:
                d2[key]=d[key]
         print(d2)
         l1=list(d1.keys())
         l2=list(d2.keys())
         for j in range(len(l1)):
            if (str(l1[j]) in d2):
                continue
            else:
        #d2(str(l1[i]))=0
                d2.update({str(l1[j]):0})
         for k in range (len(l2)):
            if (str(l2[k]) in d1):
                continue
            else:

                d1.update({str(l2[k]):0})
#print(d1)
#print(d2)
         dict1={}
         l=list(d1.keys())
         for j in range (len(l)):
            dict1[str(l[j])]=d1[str(l[j])] + d2[str(l[j])]
#print("merged dictionary:", dict)
         dict[i]=dict1
         #dict[i]=list(dict1.items())
         print("i is",i)
         #print("dict1",dict1)
         print("dict",dict)
     #dict=dict+dict1
print("final merged :", dict)
print(dict['books'])

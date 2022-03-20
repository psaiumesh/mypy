#data = [ 
# ('Cricket', 'Dhoni'), 
# ('Music', 'ARRehman'), 
# ('Scriting', 'Python'), 
# ('Singer', 'SPBalu'), 
# ('Singer', 'Chitra'), 
# ('Singer', 'Jesudas') 
#]
def swap(data):
    
    i=0
    while(i<len(data)):
        data[i]=list(data[i])
        t=data[i][0]
        data[i][0]=data[i][1]
        data[i][1]=t
        i=i+1
    i=0
    while(i<len(data)):
        data[i]=tuple(data[i])
        i=i+1
    return data
    #print("sorted data",sorted(data))
    #data=sorted(data)
    #i=0
    #while(i<len(data)):
     #   data[i]=list(data[i])
     #   t=data[i][0]
      #  data[i][0]=data[i][1]
      #  data[i][1]=t
      #  i=i+1
        #data[i]=tuple(data[i])
    #i=0
    #while(i<len(data)):
     #   data[i]=tuple(data[i])
      #  i=i+1
    #print(data)
    #print(da
def main():
    data1 = [ 
 ('Cricket', 'Dhoni'), 
 ('Music', 'ARRehman'), 
 ('Scriting', 'Python'), 
 ('Singer', 'SPBalu'), 
 ('Singer', 'Chitra'), 
 ('Singer', 'Jesudas') 
]
    print("list before sorted",data1)
    #sort_name(data1)
    data2=swap(data1)
    data2=sorted(data2)
    data2=swap(data2)
    print(data2)

if(__name__=="__main__"):
    main()
    

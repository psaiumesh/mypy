def count_group(s):

    count=0
    i=0
    #print(len(s))
    while(i<len(s)):
        if(s[i]!="A"):
            i=i+1
        else:

            while(s[i]=="A"):

                    #print("i is:",i)
                    i=i+1
                    if(i==len(s)):
                        break
            count=count+1
    print("group of A is:",count)
def main():
    s1="A2345AA23AAAmnoAwertAAA AAAAAAA 1234AA "
    count_group(s1)
if __name__=="__main__" :
    main()




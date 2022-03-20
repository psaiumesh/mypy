def string_space(s):
    print("original string:",s)
    s=s.strip()
#s1=" "
    print("after stripping:",s)
    l=s.split()
    #print(" ".join(l))
#print(len(s))
    #a=len(l)
    #i=0
    #while(i<a):
    #    l[i].lstrip("")
        #print(l[i])
     #   i=i+1
        #print(i)
    print("new_string:",' '.join(l))
def main():
    s1="     Altran    is    a    great place   to   work        "
    string_space(s1)
    #print(f"Before....{s1}")
    #s1 = " ".join(s1.split())
    #print(f"After.....{s1}")
if(__name__=="__main__"):
    main()

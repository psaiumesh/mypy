def string_swap(s1):
    s1=s1.replace(",","@")
    s1=s1.replace(".",",")
    s1=s1.replace("@",".")
    #s3=s1.replace(".",",")
    #s=s2+s3
    print("swapping string",s1)
def main():
    s="Hi, Welcome. Altran is in Bengaluru, Hyderabad, and in Mumbai."
    print("original string:",s)
    string_swap(s)
if(__name__== "__main__"):
    main()

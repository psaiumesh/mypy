import datetime
import aura_date_time

# "2018-12-29T10:30:07.119045211Z"
def extract_date_time(str_datetime):
    (new_date, new_time) = str_datetime.split('T')
    print (f"str_datetime :{str_datetime}")
    print (f"new_date :{new_date}")
    print (f"new_time :{new_time}")

    (yy, mm, dd) = new_date.split('-')
    yy=int(yy)
    mm=int(mm)
    dd=int(dd)
    print (f"yy : {yy}, mm :{mm}, dd :{dd}")

    (hh, minu, sec) = new_time.split(':')
    sec, msec = sec.split('.')
    msec = msec.rstrip('Z')
    hh=int(hh)
    minu=int(minu)
    sec=int(sec)
    print (hh,"hour",minu,"minutes",sec,"seconds",msec,"milliseconds")

    mytime=datetime.datetime(yy, mm, dd,hh,minu,sec)
    print((mytime))
    mytime2=datetime.datetime(int(2019),int(2),int(5),int(2),int(30),int(30))
    #mytime2=datetime.datetime.today()
    print((mytime2))
    result=mytime2-mytime
    result=result.days
    print("result",result)
    if result < 7:
        
        print(result % 7 , 'days ago') 
    if (7<=result<14):
        print(result //7 ,'week',end=" ")
        result=result % 7
        print(result % 7, "days ago",end=" ")
    if(14<=result<30):
        print(result //7 ,'weeks',end=" ")
        result=result % 7
        print(result %7,'days ago',end=" ")
    if (30<=result<365):
        print(result //30 ,'months',end=" ")
        result=result % 30
        print(result //7 ,'weeks',end=" ")
        result=result % 7
        print(result % 7,"days ag0",end=" ")
    if(365<result):
        print(result //365,"years ago")
    #result=result.days
    #print("type of result",type(result))
    #print(result%7)
    #print(dir(result))
       # week=int(result) / 7
    #day=int(result) % 7
    #print(f"{week} weeks {day} days ")
   # t = int(msec)
       # print(t)
    #print(yy, mm, dd, hh, minu, sec, msec)

def main():
    
    str_created_time =  "2018-12-29T10:30:07.119045211Z"
    extract_date_time(str_created_time)
 #   elapsed_str = aura_date_time.get_docker_date_time_to_elapsed_str(str_created_time)
   # print(elapsed_str)

if (__name__ == "__main__"):
    
    main()


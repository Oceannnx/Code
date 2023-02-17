adult = int(input("Enter adult : "))
old = int(input("Enter old : "))
kid = int(input("Enter kid: "))
member = int(input("Enter member: "))
result = 0

if adult + old + kid > 10:
    if(member > 0):
        for i in range(member*5):
            if adult != 0:
                result+= 1000*0.9
                adult-=1
            elif old != 0:
                result+= 500*0.9
                old-=1
            elif kid != 0:
                result+=600*0.9
        result += (adult*1000) + (old*500) + (kid*600)
    result*=0.6
    
elif adult + old + kid > 5:
    if(member > 0):
        for i in range(member*5):
            if adult != 0:
                result+= 1000*0.9
                adult-=1
            elif old != 0:
                result+= 500*0.9
                old-=1
            elif kid != 0:
                result+=600*0.9
        result += (adult*1000) + (old*500) + (kid*600)
    result*=0.7
    
else :    
    if(member > 0):
        for i in range(member*5):
            if adult != 0:
                result+= 1000*0.9
                adult-=1
            elif old != 0:
                result+= 500*0.9
                old-=1
            elif kid != 0:
                result+=600*0.9
        result += (adult*1000) + (old*500) + (kid*600)
    
print((result))
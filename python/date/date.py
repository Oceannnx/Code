# import datetime
# birth_day, birth_month, birth_year = (input("Enter : ")).split()
# pick_day, pick_month, pick_year = (input("Enter : ")).split()
# birthday = datetime.date(int(birth_year),int(birth_month),int(birth_day)) #datetime.date(YEAR,MONTH,DAY)
# pickday = datetime.date(int(birth_year),int(birth_month),int(birth_day)) #datetime.date(YEAR,MONTH,DAY)
# now = datetime.date.today()
# delta = now - birthday
# age = delta.days//365
# month = ((delta.days)-(age*365))//30
# day = (((delta.days) - (age*365))%30)
# print(age,month,day)
# print(f"Age : {age} Year {month} month {day} day")
sum = 0
for i in range(1001):
    sum+=i
print(sum)
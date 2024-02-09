import time
import calendar

now = time.localtime()

print("Today's date:" + str(now.tm_mday) + "/" + str(now.tm_mon) + "/" + str(now.tm_year))

print("Today's time:" + str(now.tm_hour) + ":" + str(now.tm_min) + ":" + str(now.tm_sec))

month = int(input("Enter a month(1-12): "))
year = int(input("Enter a year: "))

print(calendar.month(year, month))


"""
This python file inserts 100K rows into table asyn in database end2end
"""

import pymysql
import string
import random

db = pymysql.connect(host='localhost', port=3306,
                     user='root', passwd='greeN7^Tr33', db='end2end', charset='utf8')

cursor = db.cursor()

sql = "INSERT INTO asyn(ID, Age, Name, c4, c5, c6, c7, c8, c9, c10) VALUES (%s,%s,%s, %s,%s,%s, %s,%s,%s, %s)"
T = []

def string_generator(size=6, chars=string.ascii_uppercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))

for i in range(1, 100001):
    age = random.randint(1,50)
    name = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c4 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c5 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c6 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c7 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c8 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c9 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    c10 = ''.join(random.sample(string.ascii_letters + string.digits, random.randint(1, 30)))
    T.append((i, age, name, c4, c5, c6, c7, c8, c9, c10))


try:
    cursor.executemany(sql, T)
    db.commit()
except:
    db.rollback()
cursor.close()
db.close()

n = int(input())
flag = 1
for i in range(2, 11):
    num = n
    s = ""
    
    while num != 0:
        tmp = ord('0') + (num % i)
        s += chr(tmp)
        num //= i
    r = s[::-1]
    if r == s:
        flag = 0
        print(i, s)
if flag == 1:
    print("NIE")
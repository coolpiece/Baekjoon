for i in range(3):
    n=int(input())
    s=0
    for j in range(n):
        inp=int(input())
        s+=inp
    if s==0:
        print(0)
    elif s>0:
        print('+')
    elif s<0:
        print('-')
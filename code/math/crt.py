import math

def egcd(a, b):
    if b == 0:
        return 1, 0, a
    x, y, g = egcd(b, a%b)
    return y, x-a//b*y, g

def crt(a, m, b, n):
    u, v, g = egcd(m, n)
    if (a-b)%g:
        return -1
    return (a-(a-b)//g*m*u)%math.lcm(m, n)
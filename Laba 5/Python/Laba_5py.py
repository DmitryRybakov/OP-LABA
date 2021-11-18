
n = int(input("Введіть довільне натуральне число - "))
c = int()
b = int()
a = int() 
print("Всi пiфагоровi трiйки натуральних чисел, кожне з яких не перевищує введенного числа n: ")
c = 1
while c <= n:
    if c * c == a * a + b * b:
        print(a, b, c)
    a = 1
    while a <= n:
        a += 1
        if c * c == a * a + b * b:
            print(a, b, c)
        b = a
        while b <= n:
            b += 1
            if c * c == a * a + b * b:
                print(a, b, c)
    c += 1

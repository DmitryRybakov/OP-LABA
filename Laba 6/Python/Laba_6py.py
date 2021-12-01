def SUM (sum, a):
    while a != 0:
        sum += a % 10
        a //= 10
    return sum

k = int(input("Введiть тiльки перше довiльне натуральне n-значне число: "))
sum = int()
a = int()
max = int(0)
x = int(0)
while k != 0:
    sum = 0
    a = k
    sum = SUM(sum, a)
    if max < sum:
        max = sum
        x = k
    print("Число сума цифр якого є найбільшою - ", x, " Сума цифр цього числа дорівнює ", max)
    print("Введiть наступне довiльне натуральне n-значне число, або введiть 0 для завершення программи: ")
    k = int(input())

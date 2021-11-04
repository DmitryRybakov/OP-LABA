import math

x1 = float( input ("введіть змінні x1 "))
y1 = float( input ("введіть змінні y1 "))
x2 = float( input ("введіть змінні x2 "))
y2 = float( input ("введіть змінні y2 "))
x3 = float( input ("введіть змінні x3 "))
y3 = float( input ("введіть змінні y3 "))
a = math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
b = math.sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2))
c = math.sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1))

ka = math.acos((c * c + b * b - a * a) / (2 * b * c))
kb = math.acos((a * a + c * c - b * b) / (2 * a * c))
kc = math.acos((a * a + b * b - c * c) / (2 * a * b))

ka = (ka * 180) / math.pi;
kb = (kb * 180) / math.pi;
kc = (kc * 180) / math.pi;


print("AB = " + str(a) + "\n" + "BC = "+ str(b) + "\n"  + "AC = " + str(c))
print("A = " + str(ka) + "\n" + "B = "+ str(kb) + "\n"  + "C = " + str(kc))

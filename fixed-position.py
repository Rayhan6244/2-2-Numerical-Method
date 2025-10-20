import math

def g(x):
    return (math.cos(x) + 1) / 3

x = 3.2
tolerance = 0.0001
max_steps = 100
step = 0

x_new = g(x)

while abs(x_new - x) > tolerance and step < max_steps:
    x = x_new
    x_new = g(x)
    step += 1

print("Fixed point is:", x_new)
print("Total steps:", step)

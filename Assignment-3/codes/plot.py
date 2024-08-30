import matplotlib.pyplot as plt
import numpy as np
from ctypes import *

secForm = CDLL('./secForm.so')

x1 = -6
y1 = 3
x2 = 6
y2 = 4
k = 1

secn = secForm.secForm
secn.restype = c_float

x = secn(c_float(x1), c_float(x2), c_float(k))
y = secn(c_float(y1), c_float(y2), c_float(k))
print(x, y)

X = [x1, x2, x]
Y = [y1, y2, y]

# Lists to store x and y coordinates
A = np.array(([x1, y1])).reshape(-1, 1)
B = np.array(([x2, y2])).reshape(-1, 1)
C = np.array(([x, y])).reshape(-1, 1)

txtA = str('A' + str(tuple(A.flatten())))
txtB = str('B' + str(tuple(B.flatten())))
txtC = str('C' + str(tuple(C.flatten())))

labels = [txtA, txtB, txtC]
colors = ['r', 'g', 'k']

def plot_circle(center, point_on_circle):

    # Convert inputs to numpy arrays
    center = np.array(center)
    point_on_circle = np.array(point_on_circle)

    # Calculate the radius of the circle
    radius = np.linalg.norm(point_on_circle - center)

    # Generate the points for the circle
    theta = np.linspace(0, 2 * np.pi, 100)
    x_circle = center[0] + radius * np.cos(theta)
    y_circle = center[1] + radius * np.sin(theta)

    # Plot the circle 
    plt.plot(x_circle, y_circle, label='Circle')

# Plot the Circle
plot_circle(C, A)
plt.plot(X, Y, linestyle='-', c = 'b') # Plotting Diameter


# Plotting Points
for i in range(len(X)):
    plt.scatter(X[i], Y[i], color=colors[i], label=labels[i])

plt.annotate(txtA, xy = A)
plt.annotate(txtB, xy = B)
plt.annotate(txtC, xy = C)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.axis('equal')
plt.title('Plot of Circle')
plt.grid(True)
plt.legend(loc = 'upper right')
plt.savefig("/home/dwarak/EE1030/EE1030/Assignment-3/figs/plot.png")
plt.show()


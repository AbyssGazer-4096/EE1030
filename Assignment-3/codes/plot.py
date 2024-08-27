import matplotlib.pyplot as plt
import numpy as np

file_path = 'points.txt'

# Lists to store x and y coordinates
x = []
y = []

# Read the coordinates from the file
with open(file_path, 'r') as file:
    for line in file:
        # Split the line into x and y values using space as the delimiter
        values = line.split()  # By default, split() uses whitespace as the delimiter
        # Convert values to float and append to lists
        x.append(float(values[0]))
        y.append(float(values[1]))

A = np.array([x[0], y[0]]).reshape(-1, 1)
B = np.array([x[1], y[1]]).reshape(-1, 1)
C = np.array([x[2], y[2]]).reshape(-1, 1)

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

# Plot the coordinates
plot_circle(C, A)
plt.plot(x, y, linestyle='-', c = 'b') # Customize color, linestyle, etc.

for i in range(len(x)):
    plt.scatter(x[i], y[i], color=colors[i], label=labels[i])

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


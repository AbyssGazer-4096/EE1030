import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt

# Load the data from the file
data = np.loadtxt('points.dat')

A = np.array((data[0]))
B = np.array((data[1]))
C = np.array((data[2]))

txtA = 'A'+str(tuple(A))
txtB = 'B'+str(tuple(B))
txtC = 'C'+str(tuple(C))

radius = LA.norm(C-A)

# Split data into x and y
x = data[3:, 0]
y = data[3:, 1]

# Plot the data
plt.plot(x, y, label = 'Circle')
plt.plot(data[0:3, 0], data[0:3, 1], label = 'Diameter')
plt.scatter(data[0, 0], data[0, 1], c = 'c', label = txtA)
plt.scatter(data[1, 0], data[1, 1], c = 'm', label = txtB)
plt.scatter(data[2, 0], data[2, 1], c = 'y', label = txtC)

plt.annotate(txtA, xy = A)
plt.annotate(txtB, xy = B)
plt.annotate(txtC, xy = C)

plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Plot of Circle')
plt.axis('equal')
plt.grid(True)
plt.legend(loc = 'upper right')

plt.savefig("/home/dwarak/MatrixTheory/EE1030/1-1.5-37/figs/plot.png")
plt.show()

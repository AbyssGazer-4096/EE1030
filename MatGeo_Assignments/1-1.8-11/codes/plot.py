import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt

# Load the data from the file
data = np.loadtxt('points.dat', skiprows = 3)
points = np.loadtxt('points.dat', max_rows = 3)

A = np.array((points[0]))
B = np.array((points[1]))
C = np.array((points[2]))

txtA = 'A'+str(tuple(A))
txtB = 'B'+str(tuple(B))
txtC = 'C'+str(tuple(C))

# Split data into x and y
x = data[:, 0]
y = data[:, 1]

# Plot the data
plt.plot(x, y, label = 'Locus of X')
plt.plot(points[:, 0], points[:, 1], label = 'AB')
plt.scatter(A[0], A[1], c = 'c', label = txtA)
plt.scatter(B[0], B[1], c = 'm', label = txtB)
plt.scatter(C[0], C[1], c = 'y', label = txtC)

plt.annotate(txtA, xy = A)
plt.annotate(txtB, xy = B)
plt.annotate(txtC, xy = C)

plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Plot of Locus of a point equidistant from A and B')
plt.axis('equal')
plt.grid(True)
plt.legend(loc = 'upper right')

plt.savefig("/home/dwarak/MatrixTheory/EE1030/1-1.8-11/figs/plot.png")
plt.show()

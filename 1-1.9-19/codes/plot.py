import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt

# Load the data from the file
data = np.loadtxt('points.dat')
points = data[:3]
line1 = data[3:24]
line2 = data[24:]

A1 = np.array((points[0]))
A2 = np.array((points[1]))
B = np.array((points[2]))

txtA1 = 'A\N{SUBSCRIPT ONE}'+str(tuple(A1))
txtA2 = 'A\N{SUBSCRIPT TWO}'+str(tuple(A2))
txtB = 'B'+str(tuple(B))

# Split data into x and y
x1 = line1[:, 0]
y1 = line1[:, 1]
x2 = line2[:, 0]
y2 = line2[:, 1]

# Plot the data
plt.plot(x1, y1, label = 'A\N{SUBSCRIPT ONE}B')
plt.plot(x2, y2, label = 'A\N{SUBSCRIPT TWO}B')

plt.scatter(A1[0], A1[1], c = 'c', label = txtA1)
plt.scatter(A2[0], A2[1], c = 'm', label = txtA2)
plt.scatter(B[0], B[1], c = 'y', label = txtB)

plt.annotate(txtA1, xy = A1)
plt.annotate(txtA2, xy = A2)
plt.annotate(txtB, xy = B)

plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Points at a distance of 10 units from '+txtB)
plt.axis('equal')
plt.grid(True)
plt.legend(loc = 'upper right')

plt.savefig("/home/dwarak/MatrixTheory/EE1030/1-1.9-19/figs/plot.png")
plt.show()

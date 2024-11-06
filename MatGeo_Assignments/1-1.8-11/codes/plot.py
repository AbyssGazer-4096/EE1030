import numpy as np
import matplotlib.pyplot as plt

# Load the points from the .dat file
points = np.loadtxt('points.dat', max_rows = 3)
data = np.loadtxt('points.dat', skiprows = 3)

# Extract the x and y coordinates
x = data[:, 0]
y = data[:, 1]

# Define the points A, B, and (0,9)
[A, B, C] = np.array(points)
txtA, txtB, txtC = 'A'+str(tuple(A)),'B'+str(tuple(B)),'C'+str(tuple(C))

# Plot the locus of X
plt.figure()
plt.plot(x, y, label = 'Locus of X')
plt.plot(points[:, 0], points[:, 1], label = 'AB')
plt.scatter(A[0], A[1], c = 'c', label = txtA)
plt.scatter(B[0], B[1], c = 'm', label = txtB)
plt.scatter(C[0], C[1], c = 'y', label = txtC)

# Annotate the points
plt.annotate(txtA, xy = A)
plt.annotate(txtB, xy = B)
plt.annotate(txtC, xy = C)

# Plot specs
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Plot of Locus of X')
plt.axis('equal')
plt.grid(True)
plt.legend(loc = 'upper right')

# Save and Display plot
plt.savefig("../figs/plot.png")
plt.show()

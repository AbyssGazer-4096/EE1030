import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load the points directly from the file (assuming the file has x,y,z format)
points = np.loadtxt('points.txt', delimiter=',')

# Separate the points into X, Y, Z components
x_points = points[:, 0]
y_points = points[:, 1]
z_points = points[:, 2]

# Create the figure and 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Function to annotate points
def annotate_points(ax, point, label):
    ax.text(point[0], point[1], point[2], label, size=10, zorder=1)

# Plot the first four points (A, B, C, D) as individual points
colors = ['r', 'g', 'b', 'y']
labels = ['A', 'B', 'C', 'D']
for i in range(4):
    ax.scatter(x_points[i], y_points[i], z_points[i], s=50, color=colors[i])
    annotate_points(ax, points[i], f'{labels[i]}({x_points[i]:.1f}, {y_points[i]:.1f}, {z_points[i]:.1f})')

# Add legend
handles = [plt.Line2D([0], [0], marker='o', color='w', label=f'{labels[i]}({x_points[i]:.1f}, {y_points[i]:.1f}, {z_points[i]:.1f})',
                       markerfacecolor=colors[i], markersize=10) for i in range(4)]
ax.legend(handles=handles, loc='upper left')

# Generate a grid for the plane using remaining points
num_points = len(points) - 4
if num_points > 0:
    # Create a meshgrid for the plane
    xx, yy = np.meshgrid(np.linspace(min(x_points[4:])-1, max(x_points[4:])+1, 10),
                         np.linspace(min(y_points[4:])-1, max(y_points[4:])+1, 10))
    
    # Calculate the normal vector for the plane using points A, B, C
    A = points[0]
    B = points[1]
    C = points[2]
    
    # Calculate vectors AB and AC
    AB = B - A
    AC = C - A
    
    # Calculate normal vector N = AB x AC
    N = np.cross(AB, AC)
    # Normalize the normal vector
    N /= np.linalg.norm(N)

    # Use the plane equation z = (c - n1*x - n2*y) / n3
    c = np.dot(N, A)  # dot product gives the plane equation constant
    zz = (c - N[0] * xx - N[1] * yy) / N[2]

    # Plot the plane
    ax.plot_surface(xx, yy, zz, color='cyan', alpha=0.3, rstride=100, cstride=100)

# Set the limits of the plot
ax.set_xlim([min(x_points)-1, max(x_points)+1])
ax.set_ylim([min(y_points)-1, max(y_points)+1])
ax.set_zlim([min(z_points)-1, max(z_points)+1])

# Add labels for the axes
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')

# Add a title
ax.set_title('3D Plane with Points A, B, C, D')

# Save the figure
plt.savefig('../figs/fig.png')

# Show the plot
plt.show()

import numpy as np
import matplotlib.pyplot as plt

# Load data
A = np.loadtxt('../data/training_data.txt')

# Curve parameters
X = np.hstack((np.ones((A.shape[0],1)),A[:,[0]],A[:,[0]]**2)).T
T = A[:,[0]]
C = A[:,[1]]

# Least squares method
n_lsq = np.linalg.inv(X@X.T)@X@C
print(n_lsq)

# Plot both the results
plt.plot(T, X.T@n_lsq)
plt.plot(T, C, 'k.')
plt.grid()
plt.title('Training Data')
plt.ylabel('Output Voltage (V)')
plt.xlabel('Temperature ($^{\circ}$C)')
plt.tight_layout()
plt.savefig('../figs/train.png')
plt.show()

# Close current figure(s)
plt.close('all')

# Plot for validation
B = np.loadtxt('../data/validation_data.txt')
Xv = np.hstack((np.ones((B.shape[0],1)),B[:,[0]],B[:,[0]]**2)).T
Cv = B[:,[1]]
Tv = B[:,[0]]
plt.plot(Tv, Xv.T@n_lsq)
plt.plot(Tv, Cv, 'k.')
plt.title('Validation Data')
plt.ylabel('Output Voltage (V)')
plt.xlabel('Temperature ($^{\circ}$C)')
plt.grid()
plt.tight_layout()
plt.savefig('../figs/valid.png')
plt.show()

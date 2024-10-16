import numpy as np
import matplotlib.pyplot as plt

# Define the line equation coefficients
slope = 1.282041
intercept = -0.959919

# Generate x values for the line
x_line = np.linspace(1.5, 13.0, 100)  # Generating x values from 1.5 to 13.0
y_line = slope * x_line + intercept  # Calculate corresponding y values

# Given data points
x_i = np.array([1.5, 2.3, 3.1, 3.9, 5.0, 5.7, 6.4, 7.3, 8.1, 9.0, 
                9.8, 10.5, 11.4, 12.2, 13.0])
f_i = np.array([1.0, 2.1, 3.2, 4.3, 5.0, 6.1, 7.2, 8.3, 9.4, 10.5, 
                11.6, 12.7, 13.8, 14.9, 15.5])

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(x_line, y_line, color='red', label='Line: 1.282041x - 0.959919', linewidth=2)
plt.scatter(x_i, f_i, color='blue', label='Data Points (x_i, f_i)', zorder=5)
plt.title('Line and Data Points Plot')
plt.xlabel('x_i')
plt.ylabel('f_i')
plt.legend()
plt.grid()
plt.xlim(1, 15)  # Set x-axis limits
plt.ylim(0, 16)  # Set y-axis limits
plt.savefig("Linear Regression by least mean squares(linear curve fitting)")

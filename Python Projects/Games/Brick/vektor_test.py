import numpy as np
import matplotlib.pyplot as plt

# Walls
x_min = 0
x_max = 10
y_min = 0
y_max = 10

# Start pos
x_pos = 1
y_pos = 1

delta_t = 0.01

ball_pos = np.array([x_pos, y_pos])

speed = np.array([0.5, 1.5])

x_positions = []
y_positions = []


for i in range(0, 3000):
    ball_pos = ball_pos + speed*delta_t

    if ball_pos[0] >= x_max:
        speed[0] *= -1
        ball_pos[0] = x_max
    elif ball_pos[0] <= x_min:
        speed[0] *= -1
        ball_pos[0] = x_min

    if ball_pos[1] >= y_max:
        speed[1] *= -1
        ball_pos[1] = y_max
    elif ball_pos[1] <= y_min:
        speed[1] *= -1
        ball_pos[1] = y_min

    x_positions.append(ball_pos[0])
    y_positions.append(ball_pos[1])

plt.plot(x_positions, y_positions)
plt.grid(color='grey', linestyle='-.', linewidth=0.5)
plt.xlabel("X-Position")
plt.ylabel("Y-Position")
plt.title("Flight Path of Ball")
plt.xlim([x_min, x_max])
plt.ylim([y_min, y_max])


plt.show()


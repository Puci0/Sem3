import numpy as np
import matplotlib.pyplot as plt

def S(x):
    return 2 * x

def S2(x):
    return x+1

def S3(x):
    return x
A = 1
f = 1
N = 32  # Liczba próbek na jeden pełny okres
n = np.arange(0, N)
x1 = A * np.sin(2 * np.pi * f * n / N)  # Generowanie jednego okresu sinusoidy

# plt.figure(figsize=(8, 6))
# plt.subplot(2, 2, 1)
# plt.plot(n, x1)
# plt.ylim(-1, 6)
# plt.title('x1 = sin')
# plt.xlabel('Liczba próbek')
# plt.ylabel('Amplituda')
# plt.grid(True)
#
# x2 = np.ones_like(n)
# plt.subplot(2, 2, 2)
# plt.plot(n, x2)
# plt.ylim(-1, 6)
# plt.title('x2 = 1')
# plt.xlabel('Liczba próbek')
# plt.ylabel('Amplituda')
# plt.grid(True)
#
# add_1 = S(x1) + S(x2)
# add_1_normalized = (add_1 - np.min(add_1)) * (7 / (np.max(add_1) - np.min(add_1))) - 1
# plt.subplot(2, 2, 3)
# plt.plot(n, add_1_normalized)
# plt.ylim(-1, 6)
# plt.title('S(x1[n])+S(x2[n])')
# plt.xlabel('Liczba próbek')
# plt.ylabel('Amplituda')
# plt.grid(True)
#
# add_2 = S(x1 + x2)
# add_2_normalized = (add_2 - np.min(add_2)) * (7 / (np.max(add_2) - np.min(add_2))) - 1
# plt.subplot(2, 2, 4)
# plt.plot(n, add_2_normalized)
# plt.ylim(-1, 6)
# plt.title('S(x1[n]+x2[n])')
# plt.xlabel('Liczba próbek')
# plt.ylabel('Amplituda')
# plt.grid(True)

#B)

plt.figure(figsize=(8, 6))
plt.subplot(2, 2, 1)
plt.plot(n, x1)
plt.ylim(-1, 6)
plt.title('x1 = sin')
plt.xlabel('Liczba próbek')
plt.ylabel('Amplituda')
plt.grid(True)

x2 = np.ones_like(n)
plt.subplot(2, 2, 2)
plt.plot(n, x2)
plt.ylim(-1, 6)
plt.title('x2 = 1')
plt.xlabel('Liczba próbek')
plt.ylabel('Amplituda')
plt.grid(True)

add_1 = S2(x1) + S2(x2)
plt.subplot(2, 2, 3)
plt.plot(n, add_1)
plt.ylim(-1, 6)
plt.title('S(x1[n])+S(x2[n])')
plt.xlabel('Liczba próbek')
plt.ylabel('Amplituda')
plt.grid(True)

add_2 = S2(x1 + x2)
plt.subplot(2, 2, 4)
plt.plot(n, add_2)
plt.ylim(-1, 6)
plt.title('S(x1[n]+x2[n])')
plt.xlabel('Liczba próbek')
plt.ylabel('Amplituda')
plt.grid(True)

plt.tight_layout()
plt.show()
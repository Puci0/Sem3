import numpy as np
import matplotlib.pyplot as plt

# A = 1
# f = 1000
# T = 1 / f
# N = 32
# t = np.linspace(0, T, N, endpoint=False)
# y = A * np.sin(2 * np.pi * f * t)
# plt.figure(figsize=(12,8))
#
# Re = np.real(y)
# plt.subplot(3,2,1)
# plt.stem(Re)
# #plt.stem(freq)
#
# plt.xlabel('Numer probki')
# plt.ylabel('Amplituda')
# plt.title('Re(y)')
#
# plt.subplot(3,2,2)
# plt.axis((0, N, -1, 0.05))
# plt.title("Im(y)")
# plt.xlabel("Numer Próbki")
# plt.ylabel("Amplituda")
# Im = np.imag(y)
# plt.stem(Im)
#
# fft = np.fft.fft(y) * 2/N
# Re_fft = np.real(fft)
# plt.subplot(3,2,3)
# plt.stem(Re_fft)
# plt.axis((0,N,-1,1))
# plt.title("Re(fft(y))")
# plt.xlabel("Numer pasma czestotliwosciowego")
# plt.ylabel("Amplituda")
#
# Im_fft = np.imag(fft)
# plt.subplot(3,2,4)
# plt.stem(Im_fft)
# plt.axis((0,N,-1,1))
# plt.title("Im(fft(y))")
# plt.xlabel("Numer pasma czestotliwosciowego")
# plt.ylabel("Amplituda")
#
# Modul = np.abs(fft)
# plt.subplot(3,2,5)
# plt.stem(Modul)
# plt.axis((0,N,0,1))
# plt.title("Modul(fft(y))")
# plt.xlabel("Numer pasma czestotliwosciowego")
# plt.ylabel("Magnituda")
#
# kat = np.angle(fft)
# plt.subplot(3,2,6)
# plt.stem(kat)
# plt.title("Phase(fft(y))")
# plt.xlabel("Numer pasma czestotliwosciowego")
# plt.ylabel("Faza[rad]")
#
# plt.tight_layout()
# plt.show()

#zad2
N = 32
n = np.arange(0,N-1)
y1 = np.cos(2*np.pi*n/N + np.pi/4)
y2 = 0.5*np.cos(4*np.pi*n/N)
y3 = 0.25*np.cos(8*np.pi*n/N+np.pi/2)
plt.figure(figsize=(10, 6))
# plt.plot(n, y1, label='y1 = np.cos(2*np.pi*n/N + np.pi/4)', color='red')
# plt.plot(n, y2, label='y2 = 0.5*np.cos(4*np.pi*n/N)', color='green')
# plt.plot(n, y3, label='y3 = 0.25*cos(8*np.pi*n/N+np.pi/2)', color='blue')
#
# plt.xlabel('n')
# plt.ylabel('Amplituda')
# plt.title('Trzy różne sygnały')
# plt.legend()
# plt.grid(True)

fft1 = np.fft.fft(y1) *2/N
fft2 = np.fft.fft(y2) *2/N
fft3 = np.fft.fft(y3) *2/N
modul1 = np.abs(fft1)
modul2 = np.abs(fft2)
modul3 = np.abs(fft3)
modul4 = np.abs(fft1+fft2+fft3)
plt.subplot(4,2,1)
plt.title("y1")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(modul1)
plt.subplot(4,2,2)
plt.title("y2")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(modul2)
plt.subplot(4,2,3)
plt.title("y3")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(modul3)
plt.subplot(4,2,4)
plt.title("y1+y2+y3")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(modul4)

angle1 = np.angle(fft1)
angle2 = np.angle(fft2)
angle3 = np.angle(fft3)
angle4 = np.angle(fft1+fft2+fft3)

plt.subplot(4,2,5)
plt.title("y1")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [rad]")
plt.stem(angle1)

plt.subplot(4,2,6)
plt.title("y1")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [rad]")
plt.stem(angle2)

plt.subplot(4,2,7)
plt.title("y1")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [rad]")
plt.stem(angle3)

plt.subplot(4,2,8)
plt.title("y1")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [rad]")
plt.stem(angle4)

plt.tight_layout()
plt.show()


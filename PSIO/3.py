import numpy as np
import matplotlib.pyplot as plt

#Zad 1

A = 1
f = 1000
T = 1 / f
N = 32
t = np.linspace(0, T, N, endpoint=False)
y = A * np.sin(2 * np.pi * f * t)
plt.figure(figsize=(12,8))

Re = np.real(y)
plt.subplot(3,2,1)
plt.stem(Re)
#plt.stem(freq)

plt.xlabel('Numer probki')
plt.ylabel('Amplituda')
plt.title('Re(y)')

plt.subplot(3,2,2)
plt.axis((-1, N, -1, 0.05))
plt.title("Im(y)")
plt.xlabel("Numer Próbki")
plt.ylabel("Amplituda")
Im = np.imag(y)
plt.stem(Im)

fft = np.fft.fft(y) * 2/N
Re_fft = np.real(fft)
plt.subplot(3,2,3)
plt.stem(Re_fft)
plt.axis((-1,N,-1,1))
plt.title("Re(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Amplituda")

Im_fft = np.imag(fft)
plt.subplot(3,2,4)
plt.stem(Im_fft)
plt.axis((-1,N,-1.1,1.1))
plt.title("Im(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Amplituda")

Modul = np.abs(fft)
plt.subplot(3,2,5)
plt.stem(Modul)
plt.axis((-1,N,-0.05,1.05))
plt.title("Modul(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")

kat = np.angle(fft)
plt.subplot(3,2,6)
plt.stem(kat)
plt.title("Phase(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza[rad]")

plt.tight_layout()
plt.show()
plt.savefig("Zadanie1.png")

#zad2
N = 16
n = np.arange(0,N)
y1 = np.cos(2*np.pi*n/N + np.pi/4)
y2 = 0.5*np.cos(4*np.pi*n/N)
y3 = 0.25*np.cos(8*np.pi*n/N+np.pi/2)
plt.figure(figsize=(10, 6))
plt.plot(n, y1, label='y1 = np.cos(2*np.pi*n/N + np.pi/4)', color='red')
plt.plot(n, y2, label='y2 = 0.5*np.cos(4*np.pi*n/N)', color='green')
plt.plot(n, y3, label='y3 = 0.25*cos(8*np.pi*n/N+np.pi/2)', color='blue')

plt.xlabel('n')
plt.ylabel('Amplituda')
plt.title('Trzy różne sygnały')
plt.legend()
plt.grid(True)

fft1 = np.fft.fft(y1) *2/N
fft2 = np.fft.fft(y2) *2/N
fft3 = np.fft.fft(y3) *2/N
modul1 = np.abs(fft1)
modul2 = np.abs(fft2)
modul3 = np.abs(fft3)
modul4 = np.abs(fft1+fft2+fft3)
x_normalized = np.linspace(0, 15, len(modul1))

plt.subplot(2,2,1)
plt.xlim(-0.3, 15.3)
plt.ylim(-1, 1.05)
plt.title("y1[n] = cos(2πn/N + π/4)")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(x_normalized,modul1)
plt.xticks(np.arange(0, 16, 5))

plt.subplot(2,2,2)
plt.xlim(-0.3, 15.3)
plt.ylim(-1, 1.05)
plt.title("y2[n] = 0.5cos(4πn/N)")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(x_normalized,modul2)
plt.xticks(np.arange(0, 16, 5))

plt.subplot(2,2,3)
plt.xlim(-0.3, 15.3)
plt.ylim(-1,1.05)
plt.title("y3[n] = 0.25cos(8πn/N + π/2)")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(x_normalized,modul3)
plt.xticks(np.arange(0, 16, 5))

plt.subplot(2,2,4)
plt.xlim(-0.3, 15.3)
plt.ylim(-1, 1.05)
plt.title("y1+y2+y3")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")
plt.stem(x_normalized,modul4)
plt.xticks(np.arange(0, 16, 5))

angle1 = np.angle(fft1)/np.pi
angle2 = np.angle(fft2)/np.pi
angle3 = np.angle(fft3)/np.pi
angle4 = np.angle(fft1+fft2+fft3)/np.pi

plt.subplot(2,2,1)
plt.title("y1[n] = cos(2πn/N + π/4)")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [pi x rad]")
plt.xticks(np.arange(0, 16, 5))
plt.stem(angle1)

plt.subplot(2,2,2)
plt.title("y2[n] = 0.5cos(4πn/N)")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [pi x rad]")
plt.xticks(np.arange(0, 16, 5))
plt.stem(angle2)

plt.subplot(2,2,3)
plt.title("y3[n] = 0.25cos(8πn/N + π/2)")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [pi x rad]")
plt.xticks(np.arange(0, 16, 5))
plt.stem(angle3)

plt.subplot(2,2,4)
plt.title("y1+y2+y3")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza [pi x rad]")
plt.xticks(np.arange(0, 16, 5))
plt.stem(angle4)

plt.tight_layout()
plt.show()



#Zad 3
A = 1
f = 1000
T = 1 / f
N = 32
t = np.linspace(0, T, N, endpoint=False)
y = A * np.sin(2 * np.pi * f * t)
plt.figure(figsize=(12, 8))
fft = 2*np.fft.fft(y)/N

Re = np.real(y)
plt.subplot(3, 2, 1)
plt.stem(Re)
plt.xlabel('Numer próbki')
plt.ylabel('Amplituda')
plt.title('Re(y)')

plt.subplot(3, 2, 2)
plt.axis((-1, N, -1, 0.05))
plt.title("Im(y)")
plt.xlabel("Numer próbki")
plt.ylabel("Amplituda")
Im = np.imag(y)
plt.stem(Im)

ifft = np.fft.ifft(y) * N

Modul = np.abs(ifft)
plt.subplot(3, 2, 3)
plt.stem(Modul)
plt.axis((-1, N, -0.3, 16.5))
plt.title("Moduł(ifft(y))")
plt.xlabel("Numer pasma częstotliwościowego")
plt.ylabel("Magnituda")

kat = np.angle(ifft)
kat_normalized = np.interp(kat, (kat.min(), kat.max()), (-1, 1))
plt.subplot(3, 2, 4)
plt.stem(kat_normalized)
plt.title("Faza(ifft(y))")
plt.xlabel("Numer pasma częstotliwościowego")
plt.ylabel("Faza[rad]")

ifft = np.fft.ifft(fft)*20
plt.subplot(3, 2, 5)
plt.stem(ifft)
plt.title("Re(ifft(y))")
plt.xlabel("Numer pasma częstotliwościowego")
plt.ylabel("Amplituda")

Im_ifft = np.imag(ifft)
plt.subplot(3, 2, 6)
plt.axis((-1, N +1, -1.1, 0.1))
plt.stem(Im_ifft[:N])
plt.title("Im(ifft(y))")
plt.xlabel("Numer pasma częstotliwościowego")
plt.ylabel("Amplituda")
plt.savefig("Zadanie3a.png")

#b

N = 32
n = np.arange(start=0, stop=N)
y1 = np.cos(2*np.pi*n/N + np.pi/4)
y2 = 0.5*np.cos(4*np.pi*n/N)
y3 = 0.25*np.cos(8*np.pi*n/N + np.pi/2)
y4 = y1 + y2 + y3
plt.figure(figsize=(12, 10))

plt.subplot(2, 2, 1)
plt.stem(y4)
plt.axis((-1, N, -2.1, 2.1))
plt.title("y1+y2+y3")
plt.xlabel("Numer Probki")
plt.ylabel("Amplituda")

fft = 2*np.fft.fft(y4)/N
fft_abs = np.abs(fft)
plt.subplot(2, 2, 2)
plt.axis((-1, N, -0.05,1))
plt.stem(fft_abs)
plt.title("Modul Widma")
plt.xlabel("Numer Pasma Czestotliwosciowego")
plt.ylabel("Magnituda")

fft_ang = np.angle(fft)/np.pi
plt.subplot(2, 2, 3)
plt.axis((-1, N, -1.1,1.1))
plt.stem(fft_ang)
plt.title("Faza Widma")
plt.xlabel("Numer Pasma Czestotliwosciowego")
plt.ylabel("Faza [pi x rad]")

ifft = N*np.fft.ifft(fft)/2
plt.subplot(2, 2, 4)
plt.axis((-1, N, -2.1, 2.1))
plt.stem(ifft)
plt.title("ifft(Y)")
plt.xlabel("Numer Probki")
plt.ylabel("Amplituda")

plt.tight_layout()
plt.show()
plt.savefig("Zadanie3b.png")

#Zad 4

N = 32
k=1
phi = np.pi/2
n = np.arange(start=0, stop=N)
y = np.exp(1j*((2*np.pi * k/N * n) + phi))

Re = np.real(y)
plt.subplot(3,2,1)
plt.stem(Re)
plt.xlabel('Numer probki')
plt.ylabel('Amplituda')
plt.title('Re(y)')

plt.subplot(3,2,2)
plt.title("Im(y)")
plt.xlabel("Numer Próbki")
plt.ylabel("Amplituda")
Im = np.imag(y)
plt.stem(Im)

fft = np.fft.fft(y) * 2/N
Re_fft = np.real(fft)
plt.subplot(3,2,3)
plt.axis((0, 31, -1, 1))
plt.stem(Re_fft)
plt.title("Re(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Amplituda")

Im_fft = np.imag(fft)
plt.subplot(3,2,4)
plt.stem(Im_fft)
plt.title("Im(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Amplituda")

Modul = np.abs(fft)
plt.subplot(3,2,5)
plt.stem(Modul)
plt.title("Modul(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Magnituda")

kat = np.angle(fft)
plt.subplot(3,2,6)
plt.stem(kat)
plt.title("Phase(fft(y))")
plt.xlabel("Numer pasma czestotliwosciowego")
plt.ylabel("Faza[rad]")

plt.tight_layout()
plt.show()

#Zad 6
A = 1
f = 1000
T = 2.5 / f
N = 64
t = np.linspace(0, T, N, endpoint=False)
y = A * np.sin(2 * np.pi * f * t)
plt.figure(figsize=(12, 8))

Re = np.real(y)
plt.subplot(2, 1, 1)
plt.stem(Re)
plt.title('y')
plt.xlabel('Numer próbki')
plt.ylabel('Amplituda')

fft_result = np.fft.fft(y)
magnitude = np.abs(fft_result)

max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(2, 1, 2)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT bez okna')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')
plt.savefig("Zadanie6_sinusoida.png")

Okno Bartletta
window = np.bartlett(N)
windowed_signal = y * window
fft_result = np.fft.fft(windowed_signal)
magnitude = np.abs(fft_result)
max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(3, 2, 1)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT - Bartlett')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')

# Okno Blackmana
window = np.blackman(N)
windowed_signal = y * window
fft_result = np.fft.fft(windowed_signal)
magnitude = np.abs(fft_result)
max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(3, 2, 2)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT - Blackman')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')

# Okno Hamminga
window = np.hamming(N)
windowed_signal = y * window
fft_result = np.fft.fft(windowed_signal)
magnitude = np.abs(fft_result)
max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(3, 2, 3)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT - Hamming')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')

# Okno Hann
window = np.hanning(N)
windowed_signal = y * window
fft_result = np.fft.fft(windowed_signal)
magnitude = np.abs(fft_result)
max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(3, 2, 4)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT - Hann')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')

#okno Kaiser
window = np.kaiser(N,5)
windowed_signal = y * window
fft_result = np.fft.fft(windowed_signal)
magnitude = np.abs(fft_result)
max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(3, 2, 5)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT - Kaiser')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')

#okno Rectwin
window = np.ones(N)
windowed_signal = y * window
fft_result = np.fft.fft(windowed_signal)
magnitude = np.abs(fft_result)
max_magnitude = np.max(magnitude)
normalized_magnitude = (0.7 / max_magnitude) * magnitude

plt.subplot(3, 2, 6)
plt.stem(normalized_magnitude)
plt.title('Moduł FFT - Rectwin')
plt.xlabel('Numer pasma częstotliwościowego')
plt.ylabel('Magnituda')
#
plt.tight_layout()
plt.show()
plt.savefig("Zadanie6_okna.png")

#Wszystkie okna
N = 32
samples = np.arange(N)
plt.figure(figsize=(13,8))

window = np.bartlett(N)
plt.plot(samples, window, label='Bartlett')
window = np.blackman(N)
plt.plot(samples, window, label='Blackman')
window = np.hamming(N)
plt.plot(samples, window, label='Hamming')
window = np.hanning(N)
plt.plot(samples, window, label='Hann')
window = np.kaiser(N, 0.5)
plt.plot(samples, window, label='Kaiser')
window = np.ones(N)
plt.plot(samples, window, label='Rectwin')

plt.xlabel('Numer próbki')
plt.ylabel('Waga')
plt.title('Wszystkie okna')
plt.legend()
plt.grid(True)
plt.show()
plt.savefig("Zadanie6_wykres_laczony.png")
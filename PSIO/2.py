import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import square, sawtooth
from time import sleep
import sounddevice as sd
import wave
from scipy.io import wavfile
import struct
# # Zadanie 1
# # a)
# x = np.zeros((1, 41))
# x[0][0] = 1
# x[0][40] = 1
# plt.stem(x[0])
# plt.xlabel('Numer probki')
# plt.ylabel('Wartosc probki')
# plt.title('Impuls oraz impuls przesuniety o N=40 probek')
# plt.axis((-1, 41, -0.05, 1.05))
# plt.grid(True)
# plt.show()
#
#
# # b)
# N = 200
# x = np.linspace(0, 2*5*np.pi, N)
# Y = [np.sin(x), sawtooth(x), square(x)]
#
# for i in range(0, 3):
#     plt.subplot(3, 1, i+1)
#     plt.plot(x, Y[i])
#     plt.xlabel('Kat [rad]')
#     plt.ylabel('Amplituda')
# plt.tight_layout()
# plt.show()
#
#
#c)
# n = 400
# y = np.random.normal(loc=0, scale=0.5, size=n)
# plt.plot(y)
# plt.xlabel("Numer probki")
# plt.ylabel('Wartosc chwilowa')
# plt.title(f'Szum Gaussowski, μ={round(np.mean(y), 4)}, σ^2={round(np.std(y), 4)}')
# plt.show()

#zadanie 2
# A = [1,2,5]
# F = [1000,2000,5000]
# phi = [0,-np.pi/2,np.pi/2]
# fs = 44100
# dur = 3
# t = np.arange(start=0,stop=dur,step=1/fs)
# n = np.arange(0,len(t))

# m = 1
# for i in range(0,3):
#     y = A[i]*np.sin(2*np.pi*F[0]*n/fs + phi[0])
#     plt.subplot(3,1,m)
#     plt.xticks([0.0000, 0.0005, 0.0010, 0.0015, 0.0020, 0.0025, 0.0030], ["0", "0.5", "1", "1.5", "2", "2.5", "3"])
#     plt.axis((0,0.003,-5,5))
#     plt.plot(t,y)
#     plt.xlabel("Czas[s]")
#     plt.ylabel("Amplituda")
#     plt.title(f"Amplituda = {A[i]}")
#     plt.text(0.0028, -11.5, r'$x 10^{-3}$', fontsize=10)
#     plt.tight_layout()
#     m+=1
#     sd.play(y, fs)
#     sd.wait()
# plt.tight_layout()
# plt.show()

# m = 1
# for i in range(0,3):
#     y = A[2]*np.sin(2*np.pi*F[i]*n/fs + phi[0])
#     plt.subplot(3,1,m)
#     plt.xticks([0.0000, 0.0005, 0.0010, 0.0015, 0.0020, 0.0025, 0.0030], ["0", "0.5", "1", "1.5", "2", "2.5", "3"])
#     plt.axis((0,0.003,-5,5))
#     plt.plot(t,y)
#     plt.xlabel("Czas[s]")
#     plt.ylabel("Amplituda")
#     plt.title(f"f = {F[i]} Hz")
#     plt.text(0.003, -10.5, r'$x 10^{-3}$', fontsize=10)
#     m+=1
#     sd.play(y, fs)
#     sd.wait()
# plt.tight_layout()
# plt.show()

#
# m = 1
# for i in range(0,3):
#     y = A[2]*np.sin(2*np.pi*F[0]*n/fs + phi[i])
#     plt.subplot(3,1,m)
#     plt.xticks([0.0000, 0.0005, 0.0010, 0.0015, 0.0020, 0.0025, 0.0030], ["0", "0.5", "1", "1.5", "2", "2.5", "3"])
#     plt.axis((0,0.003,-5,5))
#     plt.plot(t,y)
#     plt.xlabel("Czas[s]")
#     plt.ylabel("Amplituda")
#     plt.title(f"phi = {round(phi[i],2)} rad")
#     plt.text(0.00165, -11, r'$x 10^{-3}$', fontsize=10)
#     m+=1
#     sd.play(y, fs)
#     sd.wait()
# plt.tight_layout()
# plt.show()

#zadanie 3
# A = 1
# f = 1000
# dur = 0.007
# fs = [8000,2000,1100]
#
# m = 1
# for i in range(0,3):
#     t = np.arange(start=0, stop=dur+1/fs[i], step=1 / fs[i])
#     n = np.arange(start = 0, stop=len(t))
#     y = A*np.sin(2*np.pi*f*n/fs[i])
#     plt.subplot(3,1,m)
#     plt.plot(t,y)
#     plt.stem(t,y)
#     plt.axis((0, 0.007, -1, 1))
#     plt.xlabel("Czas [ms]")
#     plt.ylabel("Amplituda")
#     plt.title(f"fs = {fs[i]}Hz, f = 1000Hz")
#     plt.grid(True)
#     m+=1
#     sd.play(y,fs[i])
#     sd.wait()
# plt.tight_layout()
# plt.show()

#zadanie 4
# obj = wave.open("123.wav","rb")
# sample_freq = obj.getframerate()
# n_samples = obj.getnframes()
# signal_wave = obj.readframes(-1) #byte object
#
# obj.close()
#
# length_signal = n_samples/sample_freq
# print(length_signal)
# signal_array = np.frombuffer(signal_wave,dtype=np.int16)
#
# times = np.linspace(0,length_signal,num=n_samples)
#
# plt.figure(figsize=(8,6))
# plt.subplot(4,1,1)
# plt.plot(times,signal_array)
# plt.title("Mowa")
# plt.xlabel("Czas [s]")
# plt.ylabel("Amplituda")
# plt.xlim(0,length_signal)
# plt.ylim(-5000,5000)
# #sd.play(signal_array,sample_freq)
# #sd.wait()
#
# reversed_array = signal_array[::-1]
# plt.subplot(4,1,2)
# plt.plot(times,reversed_array)
# plt.title("Mowa odwrocona")
# plt.xlabel("Czas [s]")
# plt.ylabel("Amplituda")
# plt.ylim(-5000,5000)
# sd.play(reversed_array,sample_freq)
# sd.wait()
#
# y = np.random.normal(loc=0, scale=600, size=n_samples)
# plt.subplot(4,1,3)
# plt.plot(times,y)
# plt.xlabel("Numer probki")
# plt.ylabel('Wartosc chwilowa')
# plt.title(f'Szum Gaussowski, μ={round(np.mean(y), 4)}, σ^2={round(np.std(y), 4)}')
# plt.ylim(-5000,5000)
# plt.xlim(0,length_signal)
#
# superposed_signal = signal_array + y
# plt.subplot(4, 1, 4)
# plt.plot(times, superposed_signal)
# plt.title("Superpozycja")
# plt.xlabel("Czas [s]")
# plt.ylabel("Amplituda")
# plt.xlim(0, length_signal)
#
# plt.tight_layout()
# plt.show()

#zadanie 5
sample_rate = 44100
CZESTOTLIWOSC = {
    'C': 261.626,
    'D': 293.665,
    'E': 329.628,
    'F': 349.228,
    'G': 391.995,
    'A': 440,
    'H': 493.883,
}

MELODIA = [
    ('G', 0.75), ('E', 0.75), ('E', 0.75), ('F', 0.75), ('D', 0.75), ('D', 0.75),
    ('C', 0.35), ('E', 0.35), ('G', 1.5),
    ('G', 0.75), ('E', 0.75), ('E', 0.75), ('F', 0.75), ('D', 0.75), ('D', 0.75),
    ('C', 0.35), ('E', 0.35), ('C', 1.5),
    ('C', 0.75), ('E', 0.75), ('E', 0.75), ('F', 0.75), ('D', 0.75), ('D', 0.75),
    ('C', 0.35), ('E', 0.35), ('G', 1.5),
    ('G', 0.75), ('E', 0.75), ('E', 0.75), ('F', 0.75), ('D', 0.75), ('D', 0.75),
    ('C', 0.35), ('E', 0.35), ('C', 1.5)
]

def generuj_dzwiek(length,freq,fade_in=0.1, fade_out=0.1):
    t = np.arange(0,length,1/sample_rate)
    nuta = np.sin(2*np.pi*freq*t)
    nuta[:int(fade_in * sample_rate)] *= np.linspace(0, 1, int(fade_in * sample_rate))
    nuta[-int(fade_out * sample_rate):] *= np.linspace(1, 0, int(fade_out * sample_rate))
    nuta *= 32767
    nuta = np.int16(nuta)
    return nuta

combined_signal = np.array([], dtype=np.int16)

for i in range(1,len(MELODIA)):
    nuta, dlugosc = MELODIA[i]
    czestotliwosc = CZESTOTLIWOSC[nuta]
    sygnal = generuj_dzwiek(dlugosc,czestotliwosc)
    combined_signal = np.append(combined_signal,sygnal)

wavfile.write("file.wav",sample_rate,combined_signal)

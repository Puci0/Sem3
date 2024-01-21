import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import lfilter, freqz, tf2zpk


a = [1, 0.9, 0.1]
b = [0.1, 0.2, 0.3]

def filtr(x):
    y = np.empty(len(x))

    y[0] = b[0]*x[0]
    y[1] = b[0]*x[1] + b[1]*x[0] - a[1]*y[0]

    for i in range(2, len(x)):
        y[i] = b[0]*x[i] + b[1]*x[i-1] + b[2]*x[i-2] - a[1]*y[i-1] - a[2]*y[i-2]

    return y


N = 16
x = np.zeros(16)
x[0] = 1

fig, axs = plt.subplots(1, 2)
fig.set_size_inches(14, 6)
ax = axs[0]; ax.stem(x); ax.set_title("Impuls jednostkowy"); ax.set_xlabel("Numer próbki"); ax.set_ylabel("Amplituda")
ax = axs[1]; ax.stem(filtr(x)); ax.set_title("Odpowiedź filtru obliczona z równania różnicowego"); ax.set_xlabel("Numer próbki"); ax.set_ylabel("Amplituda")
fig.set_tight_layout(tight=True)
plt.savefig("Zadanie1_a.png")


fig, axs = plt.subplots(1, 2)
fig.set_size_inches(14, 6)
ax = axs[0]; ax.stem(filtr(x)); ax.set_title("Odpowiedź filtru obliczona z równania różnicowego"); ax.set_xlabel("Numer próbki"); ax.set_ylabel("Amplituda")
ax = axs[1]; ax.stem(lfilter(b, a, x)); ax.set_title("Odpowiedź filtru obliczona funkcją lfilter"); ax.set_xlabel("Numer próbki"); ax.set_ylabel("Amplituda")
fig.set_tight_layout(tight=True)
plt.savefig("Zadanie1_b.png")


w, h = freqz(b, a)
w = w / np.pi
h_modul = np.abs(h)
fig, axs = plt.subplots(1, 2)
fig.set_size_inches(14, 6)
ax = axs[0]; ax.plot(w, 20*np.log10(h_modul)); ax.set_title("Charakterystyka amplituda filtru"); ax.set_xlabel("Czestotliwosc znormalizowana [n*radian/próbka]"); ax.set_ylabel("Magnituda [dB]")
ax = axs[1]; ax.plot(w, np.unwrap(np.angle(h))/np.pi); ax.set_title("Charakterystyka fazowa filtru"); ax.set_xlabel("Czestotliwosc znormalizowana [n*radio/próbka]"); ax.set_ylabel("Faza [pi*radian]")
fig.set_tight_layout(tight=True)
plt.savefig("Zadanie1_c.png")


z, p, k = tf2zpk(b, a)
plt.scatter(np.real(z), np.imag(z), color="")
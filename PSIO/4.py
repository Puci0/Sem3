import numpy as np
import matplotlib.pyplot as plt
import wave
import struct

import scipy.signal
import sounddevice as sd
from scipy.signal import square, sawtooth, periodogram, spectrogram, chirp


# def exponential_moving_power(x, alpha):
#     power_envelope = np.zeros_like(x)
#
#     for i in range(1, len(x)):
#         power_envelope[i] = alpha * power_envelope[i - 1] + (1 - alpha) * (x[i]**2)
#
#     return power_envelope
#
# fs = 8000
# T = 3
# n_samples = int(fs * T)
# time = np.arange(n_samples) / fs
# noise = np.random.normal(0, 1, n_samples)
# f_sinusoid = 1000
# sinusoid = np.sin(2 * np.pi * f_sinusoid * time)
#
# freq_range = np.linspace(0, 1000, n_samples)
# sinusoid_variable_freq = np.sin(2 * np.pi * freq_range * time)
#
# audio_file = wave.open('123.wav', 'r')
# sample_rate = audio_file.getframerate()
# num_frames = audio_file.getnframes()
# duration = num_frames / float(sample_rate)
#
# audio_frames = audio_file.readframes(-1)
# audio_data = np.frombuffer(audio_frames, dtype=np.int16)
#
# normalized_audio = audio_data / np.max(np.abs(audio_data))
# time_audio = np.linspace(0, duration, num=len(audio_data))
#
# alpha = 0.999
# power_envelope_noise = exponential_moving_power(noise, alpha)
# power_envelope_sinusoid = exponential_moving_power(sinusoid, alpha)
# power_envelope_variable_freq = exponential_moving_power(sinusoid_variable_freq, alpha)
# power_envelope_audio = exponential_moving_power(audio_data.astype(np.float64), alpha)
#
# plt.figure(figsize=(12,6))
#
# plt.subplot(4, 2, 1)
# plt.plot(time, noise, color='blue')
# plt.title('Szum gaussowski')
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda')
# plt.grid(True)
#
# plt.subplot(4, 2, 3)
# plt.plot(time, sinusoid, color='blue')
# plt.title('Sygnał sinusoidalny o stałej częstotliwości')
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda')
# plt.grid(True)
#
# plt.subplot(4, 2, 5)
# plt.plot(time, sinusoid_variable_freq, color='blue', label='Zmienna częstotliwość sinusoidy')
# plt.title('Sygnał sinusoidalny o zmiennej częstotliwości')
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda')
# plt.grid(True)
#
# plt.subplot(4, 2, 7)
# plt.plot(time_audio, normalized_audio, color='blue')
# plt.title('Sygnał mowy')
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda')
# plt.ylim(-1, 1)
# plt.grid(True)
#
# plt.subplot(4, 2, 2)
# plt.plot(time, power_envelope_noise, color='blue')
# plt.title(f'Szum gaussowski - Obwiednia mocy, alpha = {alpha}')
# plt.xlabel('Czas [s]')
# plt.ylabel('Moc')
# plt.ylim(0,2)
# plt.grid(True)
#
# plt.subplot(4, 2, 4)
# plt.plot(time, power_envelope_sinusoid, color='blue')
# plt.title(f'Sygnał sinusoidalny - Obwiednia mocy, alpha = {alpha}')
# plt.xlabel('Czas [s]')
# plt.ylabel('Moc')
# plt.ylim(0,1)
# plt.grid(True)
#
# plt.subplot(4, 2, 6)
# plt.plot(time, power_envelope_variable_freq, color='blue')
# plt.title(f'Sygnał o zmiennej częstotliwości - Obwiednia mocy, alpha = {alpha}')
# plt.xlabel('Czas [s]')
# plt.ylabel('Moc')
# plt.ylim(0,1)
# plt.grid(True)
#
# plt.subplot(4, 2, 8)
# plt.plot(time_audio, power_envelope_audio, color='blue')
# plt.title(f'Sygnał mowy - Obwiednia mocy, alpha = {alpha}')
# plt.xlabel('Czas [s]')
# plt.ylabel('Moc')
# plt.grid(True)


#zad 2
f = 1000
fs = 16000
t = np.arange(0,2,1/fs)

plt.figure(figsize=(10,8))
plt.subplot(8,2,1)
sinusoide = np.sin(2*np.pi*f*t)
plt.plot(t,sinusoide)
plt.xlim(0,0.02)
plt.title('Sygnal sinusoidalny o stalej czestotliwosci'); plt.ylabel("Amplituda")

plt.subplot(8,2,2)
sinusoide_f,sinusoide_pxx = scipy.signal.periodogram(sinusoide)
plt.plot(sinusoide_f,10*np.log10(np.abs(sinusoide_pxx)))
plt.title('Periodogram sygnału sinusoidalnego o stałej f'); plt.ylabel("Moc [dB]")


plt.subplot(8,2,3)
square_sinusoide = square(2*np.pi*f*t)
plt.plot(t,square_sinusoide)
plt.xlim(0,0.02)
plt.title('Sygnal prostokatny o stalej czestotliwosci'); plt.ylabel("Amplituda")

plt.subplot(8,2,4)
square_f,square_pxx = scipy.signal.periodogram(square_sinusoide)
plt.plot(square_f,10*np.log10(np.abs(square_pxx)))
plt.title('Periodogram sygnału prostokatnego o stałej f'); plt.ylabel("Moc [dB]")

plt.subplot(8,2,5)
triangle_sinusoide = sawtooth(2*np.pi*f*t, width=0.5)
plt.plot(t,triangle_sinusoide)
plt.xlim(0,0.02)
plt.title('Sygnal trojkatny o stalej czestotliwosci'); plt.ylabel("Amplituda")

plt.subplot(8,2,6)
triangle_f,triangle_pxx = scipy.signal.periodogram(triangle_sinusoide)
plt.plot(triangle_f,10*np.log10(np.abs(triangle_pxx)))
plt.title('Periodogram sygnału trojkatnego o stałej f'); plt.ylabel("Moc [dB]")

plt.subplot(8,2,7)
pi_sinusoide = sawtooth(2*np.pi*f*t)
plt.plot(t,pi_sinusoide)
plt.xlim(0,0.02)
plt.title('Sygnal piłokształtny o stalej czestotliwosci'); plt.ylabel("Amplituda")

plt.subplot(8,2,8)
pi_f,pi_pxx = scipy.signal.periodogram(pi_sinusoide)
plt.plot(pi_f,10*np.log10(np.abs(pi_pxx)))
plt.title('Periodogram sygnału piloksztaltnego o stałej f'); plt.ylabel("Moc [dB]")

plt.subplot(8,2,9)
gauss_noise = np.random.normal(0,1,len(t))
plt.plot(t,gauss_noise)
plt.xlim(0,0.02)
plt.title('Szum gaussowski o stalej czestotliwosci'); plt.ylabel("Amplituda")

plt.subplot(8,2,10)
gauss_f,gauss_pxx = scipy.signal.periodogram(gauss_noise)
plt.plot(gauss_f,10*np.log10(np.abs(gauss_pxx)))
plt.title('Periodogram szumu gaussowskiego o stałej f'); plt.ylabel("Moc [dB]")

plt.subplot(8,2,11)
sin_var = chirp(t, f0=1000, f1=2000, t1=2, method='linear')
plt.plot(t,sin_var)
plt.xlim(0,0.02)
plt.title('Sygnal sinusoidalny o zmiennej czestotliwosci'); plt.ylabel("Amplituda")

plt.subplot(8,2,12)
var_f,var_pxx = scipy.signal.periodogram(sin_var)
plt.plot(var_f,10*np.log10(np.abs(var_pxx)))
plt.title('Periodogram sygnału sinusoidalnego o zmiennej f'); plt.ylabel("Moc [dB]")

with wave.open("C:\\Users\\User\\PycharmProjects\\numpy\\mowa.wav", 'r') as file:
    n_frames = file.getnframes()
    fs_mowy = file.getframerate()
    t_mowy = n_frames/fs_mowy
    n_mowy = np.arange(0, t_mowy, 1/fs_mowy)
    data = file.readframes(n_frames)
    mowa = struct.unpack(f"{n_frames}h", data)
    max_amplitude = np.max(np.abs(mowa))
    mowa = mowa / max_amplitude
with wave.open("C:\\Users\\User\\PycharmProjects\\numpy\\muzyka.wav", 'r') as file:
    liczba_kanalow = file.getnchannels()
    liczba_bitow_na_probke = file.getsampwidth()
    n_frames = file.getnframes()
    fs_muzyki = file.getframerate()
    t_muzyki = n_frames / fs_muzyki
    n_muzyki = np.arange(0, t_muzyki-(1/fs_muzyki), 1 / fs_muzyki)
    data = file.readframes(n_frames)
    muzyka = struct.unpack(f"{n_frames * liczba_kanalow}h", data)
    muzyka = np.array(muzyka).reshape((-1, liczba_kanalow))
    muzyka = np.sum(muzyka, axis=1)
    max_amplitude = np.max(np.abs(muzyka))
    muzyka = muzyka / max_amplitude

plt.subplot(8,2,13)
plt.plot(n_mowy,mowa)
plt.title('Mowa'); plt.ylabel("Amplituda")

plt.subplot(8,2,14)
mowa_f,mowa_pxx = scipy.signal.periodogram(mowa)
plt.plot(mowa_f,10*np.log10(np.abs(mowa_pxx)))
plt.title('Periodogram mowy'); plt.ylabel("Moc [dB]")

plt.subplot(8,2,15)
plt.plot(n_muzyki,muzyka)
plt.title('Muzyka'); plt.ylabel("Amplituda")

plt.subplot(8,2,16)
muzyka_f,muzyka_pxx = scipy.signal.periodogram(muzyka)
plt.plot(muzyka_f,10*np.log10(np.abs(muzyka_pxx)))
plt.title('Periodogram muzyki'); plt.ylabel("Moc [dB]")

plt.tight_layout()
plt.show()
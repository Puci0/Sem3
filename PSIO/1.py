import numpy as np
from matplotlib import pyplot as plt
from scipy import signal as sg
import math

#zad1
# x = np.linspace(-10,10)
# y = pow(x,2) + 5
# plt.title("tytul")
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda [v]')
# plt.plot(x,y)
# plt.show()

#zad2
# x = np.linspace(0,2*math.pi) #arange robi kwadratowy wykres
# y1 = np.sin(x)
# y2 = np.cos(x)
#plt.xlabel('Czas [s]')
#plt.ylabel('Amplituda [v]')
# plt.title('Wykres sin(x) i cos(x)')
# plt.plot(x,y1,x,y2)
# plt.show()

#zad3
A = 2
f = 1000
t = np.linspace(0,0.005,1000)
y = A*np.sin((2*math.pi*f)*t)
plt.xlabel('Czas [s]')
plt.ylabel('Amplituda [v]')
plt.title('wykres sygnału sinusoidalnego')
plt.plot(t,y)
plt.show()

#zad4
#a
# A = 2
# f = 1000
# t = np.linspace(0,0.5,100)
# y = A*np.cos(2*math.pi*f*t)
#plt.xlabel('Czas [s]')
#plt.ylabel('Amplituda [v]')
# plt.title('wykres sygnału kosinusoidalnego')
# plt.plot(t,y)
# plt.show()

#b
# A = 2
# f = 1000
# t = np.linspace(0,0.005,1000)
# y = A*sg.square(2*np.pi*f*t)
# plt.plot(t, y)
#plt.xlabel('Czas [s]')
#plt.ylabel('Amplituda [v]')
# plt.title('Sygnał prostokątny')
# plt.grid(True)
# plt.show()

#c
# A = 2
# f = 1000
# t = np.linspace(0,0.005,1000)
# y = A*sg.sawtooth(2*np.pi*f*t,width=0.5)
# plt.plot(t,y)
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda [v]')
# plt.title('Sygnal trójkątny')
# plt.grid(True)
# plt.show()

#d
# A = 2
# f = 1000
# t = np.linspace(0,0.005,1000)
# y = A*sg.sawtooth(2*np.pi*f*t)
# plt.plot(t,y)
# plt.xlabel('Czas [s]')
# plt.ylabel('Amplituda [v]')
# plt.title('Sygnal piłokształtny')
# plt.grid(True)
# plt.show()

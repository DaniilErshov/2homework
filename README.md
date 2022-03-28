# homework
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 09:04:27 2022

@author: User
"""
import numpy as np
import matplotlib.pyplot as plt 


def f(p,u1,u2,t,h,q):
    u2[p] = u1[p] - t / (2*h) * (u1[p+1] - u1[p-1]) + (t**2*q/h**2)*(u1[p-1] - 2*u1[p] + u1[p+1])









M = 100
N = 1000
h = 1/M
t = 0.5/N
q = 0.3
u0 = np.zeros(M + 1)
u1 = np.zeros(M + 1)
tmp = np.zeros(M + 1)
u2 = np.zeros(M + 1)

n_lst = ["100","500","1000","10000","100000"]
for time in n_lst:
  time_int = int(time)
  t = 0.5/time_int
  for i in range(int(0.1/h), int(0.2/h) + 1):
      u1[i] = 1.
      u0[i] = 1.
  for m in range(0, time_int):
      for p in range(1, M):
        f(p,u1,u2,t,h,q) 
      u1 = u2
      u2 = np.zeros(M + 1)
  plt.plot(u1, label = time)
  u1 = np.zeros(M + 1)
for i in range(int(0.1/h + M*0.5), int(0.2/h + M*0.5)):
    tmp[i] = 1 
plt.plot(tmp)
plt.legend()
plt.show()      





import numpy as np
import matplotlib.pyplot as plt 

def f(p,u1,u2,t,h):
    u2[p] = u1[p] - t / h * (u1[p] - u1[p - 1])









M = 350
h = 1/M
tmp = np.zeros(M + 1)
u0 = np.zeros(M + 1)
u1 = np.zeros(M + 1)
u2 = np.zeros(M + 1)
n_lst = ["200","500","1000","10000"]
for time in n_lst:
  time_int = int(time)
  t = 0.5/time_int
  for i in range(int(0.1/h), int(0.2/h) + 1):
      u1[i] = 1.
      u0[i] = 1.
  for m in range(0, time_int):
      for p in range(1, M):
        f(p,u1,u2,t,h) 
      u1 = u2
      u2 = np.zeros(M + 1)
  plt.plot(u1, label = time)
  u1 = np.zeros(M + 1)
for i in range(int(0.1/h + M*0.5), int(0.2/h + M*0.5)):
    tmp[i] = 1 
plt.plot(tmp)
plt.legend()
plt.show()      

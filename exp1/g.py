import numpy as np
import matplotlib.pyplot as plt
import ctypes
import os, sys
os.chdir("./")
so=ctypes.CDLL("./lsm.so")
so.init()
so.get_line.restype=ctypes.c_double
so.get_line.argtype=[ctypes.c_double]
print("f(55)")
print(so.get_line(ctypes.c_double(55.0)))
plt.figure(figsize=(10,5))
x = np.linspace(0,100, 20000)
list = []
for i in x:
    list.append(so.get_line(ctypes.c_double(i)))
    #print(i)
    #print (list[len(list)-1])
x1=[0.0,10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0]
y1=[68.0,67.1,66.4,65.6,64.6,61.8,61.0,60.8,60.4,60.0]
plt.scatter(x1,y1)
plt.plot(x,list)
plt.show()

#y=so.esti(x,200)
#sr_x = [0.10,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,1.00]
#sr_fx = [0.904837,0.818731,0.740818,0.670320,0.606531,0.548812,0.496585,0.449329,0.406570,0.367879]

#deriv = [-0.904837,-0.818731,-0.740818,-0.670320,-0.606531,-0.548812,-0.496585,-0.449329,-0.406570,-0.367879]                           # 导数都为 0


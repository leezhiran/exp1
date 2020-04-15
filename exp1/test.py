import numpy as np
import matplotlib.pyplot as plt

"""
@brief: 获得拉格朗日插值基函数
@param: xi      xi为第i个插值节点的横坐标
@param: x_set   整个插值节点集合
@return: 返回值为参数xi对应的插值基函数
"""
def get_li(xi, x_set = []):
    def li(Lx):
        W = 1; c = 1
        for each_x in x_set:
            if each_x == xi:
                continue
            W = W * (Lx - each_x)
         
        for each_x in x_set:
            if each_x == xi:
                continue
            c = c * (xi - each_x)
             
        # 这里一定要转成float类型，否则极易出现严重错误. 原因就不说了(截断误差)
        return W / float(c)    
    return li
def get_basis_func_alpha(xi, x_set = []):
     
    def basis_func_alpha(x):
        tmp_sum = 0
        for each_x in x_set:
            if each_x == xi:
                continue
            tmp_sum = tmp_sum + 1/float(xi - each_x)
             print ((1 + 2*(xi-x) * tmp_sum) * ((get_li(xi, x_set))(x)) ** 2)
             print ("\")
        return (1 + 2*(xi-x) * tmp_sum) * ((get_li(xi, x_set))(x)) ** 2

    return basis_func_alpha
 
 
 
"""
@brief: 获得埃尔米特插值基函数β(x)   notice: 求导部分基函数
@param: xi      xi为第i个插值节点的横坐标
@param: x_set   整个插值节点集合
@return: 返回值为参数xi对应的插值基函数
"""
def get_basis_func_beta(xi, x_set = []):  
    return lambda x : (x - xi) * ((get_li(xi, x_set))(x)) ** 2

def get_Hermite_interpolation(x = [], fx = [], deriv = []): 
    set_of_func_alpha = []  # α(x)基函数集合
    set_of_func_beta = []   # β(x)基函数集合
    for each in x:          # 获得每个插值点的基函数
        tmp_func = get_basis_func_alpha(each, x)
        set_of_func_alpha.append(tmp_func)      # 将集合x中的每个元素对应的插值基函数保存
        tmp_func = get_basis_func_beta(each, x)
        set_of_func_beta.append(tmp_func)       # 将集合x中的每个元素对应的插值基函数保存
         
    def Hermite_interpolation(Hx):
        result = 0
        for index in range(len(x)):
            result = result + fx[index]*set_of_func_alpha[index](Hx) + deriv[index]*set_of_func_beta[index](Hx)   #根据根据拉格朗日插值法计算Lx的值
        return result
             
    return Hermite_interpolation

if __name__ == '__main__':  
 

    import math
    sr_x = [0.10,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,1.00]
    sr_fx = [0.904837,0.818731,0.740818,0.670320,0.606531,0.548812,0.496585,0.449329,0.406570,0.367879]

    deriv = [-0.904837,-0.818731,-0.740818,-0.670320,-0.606531,-0.548812,-0.496585,-0.449329,-0.406570,-0.367879]    
    Hx = get_Hermite_interpolation(sr_x, sr_fx, deriv)  # 获得插值函数
    tmp_x = np.linspace(0.1,1.0, 20000)# 测试用例
    tmp_y = [Hx(i) for i in tmp_x]                      # 根据插值函数获得测试用例的纵坐标
         
    ''' 画图 '''
    import matplotlib.pyplot as plt
    plt.figure("play")
    ax1 = plt.subplot(211)
    plt.sca(ax1)
    plt.plot(sr_x, sr_fx, linestyle = ' ', marker='o', color='b')
    plt.plot(tmp_x, tmp_y, linestyle = '--', color='r')
    plt.show()   

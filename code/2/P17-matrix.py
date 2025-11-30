# 千万不要用 Python 自带的 list（列表）去模拟矩阵运算，那是自讨苦吃。List: [1, 2] + [3, 4] 结果是拼接 [1, 2, 3, 4]。Matrix: $\begin{bmatrix}1 & 2\end{bmatrix} + \begin{bmatrix}3 & 4\end{bmatrix}$ 结果应该是 $\begin{bmatrix}4 & 6\end{bmatrix}$。
import numpy as np

A = np.array([
    [2, 0, 1],
    [0, 2, 0],
    [1, 0, 2]
])

B = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]  
])

C = A.T @ B 

print("矩阵 C (A.T @ B):")
print(C)


det = np.linalg.det(C)
print(det)



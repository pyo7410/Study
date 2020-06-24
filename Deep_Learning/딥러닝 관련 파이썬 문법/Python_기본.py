#!/usr/bin/env python
# coding: utf-8

# In[3]:


print("Hello world")


# In[5]:


get_ipython().run_line_magic('matplotlib', 'inline')

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-np.pi, np.pi)
plt.plot(x, np.cos(x))
plt.plot(x, np.sin(x))
plt.show()


# In[11]:


i = 123
print(type(i))

s = "test"
print(type(s))

c = "a"
print(type(c))

f = 1.23
print(type(f))

# bool은 True는 1, False는 0으로 취급한다. 즉, True와 False를 더하면 1이 된다.
b = True
print(type(b))

l = [1, 2, 3]
print(type(l))

# **는 거듭제곱
e = 2 ** 5
print(e)

# 논리연산자인 "in"은 x in y일 경우 y 속에 x가 포함되어 있을 경우 true를 반환한다.
# + 연산자는 문자열이나 리스트를 합칠때도 사용이 가능하다.


# In[12]:


# 파이썬의 리스트는 자료형이 섞여도 상관이 없다. [] 를 사용한다.
# 튜플은 리스트와 달리 원소를 추가, 삭제, 변경이 불가능하다. ()를 사용한다.

a = [1, 2, 3]
a1, a2, a3 = a # 리스트의 각 원소를 차례대로 변수에 입력한다.
print(a1, a2, a3)

b = (4, 5 ,6)
b1, b2, b3 = b # 튜플의 각 원소를 차례대로 변수에 입력한다.
print(b1, b2, b3)


# In[14]:


# 딕셔너리(dictionary)는 Key와 Value를 한 쌍으로 갖는 자료형

a = {"Apple":3, "Pineapple":4} # 딕셔너리 생성
print(a["Apple"]) # "Apple"을 키로 갖는 값을 표시

a["Pineapple"] = 6 # 원소값을 변경
print(a["Pineapple"])

a["Melon"] = 3 # 새로운 원소를 추가
print(a)


# In[16]:


# if 조건문:
# elif 조건문:
# else:

a = 7
if a < 12:
    print("Good morning!")
elif a < 17:
    print("Good afternoon!")
elif a < 21:
    print("Good evening!")
else:
    print("Good night!")


# In[17]:


# for 반복문
# for문은 리스트나 range 함수를 in 연산자와 함께 이용
# range([시작하는 수,] 끝나는 수[, 간격])

# 리스트를 이용한 반복
for a in [4, 7, 10]:
    print(a)
    
# range 함수를 이용한 반복
for a in range(3):
    print(a)


# In[18]:


# while 문
a = 0
while a < 3:
    print(a)
    a += 1


# In[21]:


# 컴프리헨션(Comprehension)
# 리스트의 원소를 변경해 새로운 리스트를 생성하는 방법
# 보통 for 반복문을 사용, 컴프리헨션을 사용하면 반복문을 간결하게 기술가능.
# 리스트에서 원소를 하나씩 추출해 원소에 대한 작업을 처리하고 새로운 리스트를 만든다.

# 새로운 리스트 = [원소에 대한 처리 for 원소 in 리스트]
a = [1, 2, 3, 4, 5, 6, 7]
b = [c * 2 for c in a]
print(b)

# 새로운 리스트 = [원소에 대한 처리 for 원소 in 리스트 if 조건문]
a = [1, 2, 3, 4, 5, 6, 7]
b = [c * 2 for c in a if c < 5] # 5 보다 작은 원소만 처리
print(b)


# In[25]:


# 함수
# def 함수명():

def add(a, b):
    c = a + b
    return c
print(add(3, 4))

# 기본값 설정
def add2(a, b=4): # 2번째 인수에 기본값을 설정
    c = a + b
    return c
print(add2(3))

# 여러 개의 인수를 튜플로 전달
def add3(a, b, c):
    d = a + b + c
    print(d)
    
e = (1, 2, 3) # 인수에 전달되는 값을 튜플로 생성
add3(*e)


# In[28]:


# 함수 안에 정의된 변수를 지역(local)변수, 함수 밖에서 정의된 변수를 전역(global)변수라고 한다.
# 지역변수는 같은 함수 안에서만 참조할 수 있지만, 전역변수는 어디에서나 참조할 수 있다.

a = 123 # 전역변수

def showNum():
    b = 456 # 지역변수
    print(a, b)
    
showNum()

# 함수안에서 전역변수에 새로운 값을 입력하려고 하면 새로운 지역변수로 간주한다.
a = 123

def setLocal():
    a = 456 # a는 전역변수가 아닌 지역변수로 간주된다.
    print("Local : ", a)
    
setLocal()
print("Global : ", a)

# 함수 안에서 전역변수의 값을 변경하기 위해서는 global 혹은 nonlocal을 이용해 변수가 지역변수가 아님을 명시해야한다.
a = 123

def setGlobal():
    global a
    a = 456
    print("Global : ", a)
    
setGlobal()
print("Global : ", a)


# In[30]:


# Class
# class 클래스명(대문자로 시작해야한다.):
# 파이썬의 메소드는 self를 인수로 전달하는 특징이 있다.
# self를 이용해 인스턴스 변수에 접근할 수 있다.

class Calc:
    def __init__(self, a): # 생성자(Constructor)
        self.a = a # 인수로 받은 값을 인스터느 변수 a에 입력
    
    def add(self, b):
        print(self.a + b)
        
    def multiply(self, b):
        print(self.a * b)
        
calc = Calc(3) # Calc 클래스의 인스턴스 생성
calc.add(4)
calc.multiply(4)

# 상속
# class 클래스명(상속받을 클래스명):

class CalcPlus(Calc):
    def subtract(self, b):
        print(self.a - b)
    
    def divide(self, b):
        print(self.a / b)
        
calc_plus = CalcPlus(3) # CalcPlus클래스의 인스턴스 생성
calc_plus.add(4)        # Calc 클래스의 메소드
calc_plus.multiply(4)   # Calc 클래스의 메소드
calc_plus.subtract(4)   # CalcPlus 클래스의 메소드
calc_plus.divide(4)     # CalcPlus 클래스의 메소드


# In[37]:


# 넘파이(Numpy)
# 다차원 배열을 충실하게 지원하며 내부는 C 언어로 구현되어 있어 실행 속도가 매우 빠르다.
# 또한 방대한 수학함수 라이브러리를 내장하고 있어 연산 기능이 충실하다.
import numpy as np

a = np.array([0, 1, 2, 3, 4, 5])
print(a)

b = np.array([[0, 1, 2], [3, 4, 5]]) # 2중 리스트로 생성
print(b)

c = np.array([[[0, 1, 2], [3, 4, 5]], [[5, 4, 3], [2, 1, 0]]]) # 3중 리스트로 생성
print(c)

# 위와 같은 방법으로 더 높은 차원의 배열을 만들 수 있다.

print(np.shape(c)) # 배열의 형태 즉, 각 차원의 원소 수
print(np.size(c)) # 배열의 총 원소 수

d = [[1, 2], [3, 4], [5, 6]] # (3, 2) 형태의 리스트
print(len(d)) # 첫 번째 차원의 원소 개수를 센다.
print(len(np.array(d))) # 첫 번째 차원의 원소 개수를 센다.


# In[45]:


print(np.zeros(10)) # 모든 값이 0인 원소를 10개 가진 배열
print(np.ones(10)) # 모든 값이 1인 원소를 10개 가진 배열
print(np.random.rand(10)) # 난수로 생성되는 배열

# zeros와 ones는 튜플 형태의 다차원 배열을 생성할 수 있다.
print(np.zeros((2, 3)))
print(np.ones((2, 3)))

# arange 함수를 사용하면 연속된 값을 갖는 배열을 생성할 수 있다.
# arange(시작하는 수, 끝나는 수, 간격)
print(np.arange(0, 1, 0.1)) # 0 ~ 1 까지 0.1씩 증가하는 배열

# 시작하는 수와 간격을 생략 가능
# 이때, 시작하는 수는 0, 간격은 1이 된다.
print(np.arange(10))

# linspace 함수는 arange와 비슷한 역할을 한다.
# 보통 그래프의 가로, 세로축의 값을 나타낼 때 자주 사용한다.
# linspace(시작하는 수, 끝나는 수, 원소 수)
print(np.linspace(0, 1, 11)) # 0부터 1까지 원소 수가 11개인 배열을 생성

# linspace 함수의 세 번째 인수는 생략이 가능
# 이때, 배열의 원소수는 50이 된다.
print(np.linspace(0, 1))


# In[52]:


# reshape
# 배열의 형태를 변환할 때 사용
# 원소의 수만 일치하면 어떤 형태든 reshape로 변환 가능
a = np.array([0, 1, 2, 3, 4, 5, 6, 7])
b = a.reshape(2, 4) # (2, 4) 형태의 2차원 배열로 변환
print(b)

# reshape는 배열의 메소드임을 주의!
# 넘파이는 함수와 메소드가 동일한 기능을 실행할 수 있다.
b = np.reshape(a, (2, 4))
print(b)

c = b.reshape(2, 2, 2) # 2차원을 3차원으로
print(c)

d = c.reshape(4, 2) # 3차원을 2차원으로
print(d)

# reshape의 인수를 -1로 지정하면 어떠한 형태의 배열도 1차원이 된다.
e = d.reshape(-1)
print(e)

# 여러 개의 인수 중 하나를 -1로 지정하면 해당 위치의 차원의 원소 수를 자동으로 계산해 값을 넣어 준다.
f = e.reshape(2, -1)
print(f)


# In[54]:


# 배열 연산
a = np.array([0, 1, 2, 3, 4, 5]).reshape(2, 3) # (2, 3) 배열 생성
print(a)
print(a + 3) # 각 원소값에 3을 더함
print(a * 3) # 각 원소값에 3을 곱함

# 배열간 연산
b = np.array([5, 4, 3, 2, 1, 0]).reshape(2, 3)
print(b)
print(a + b) # 배열간 덧셈
print(a * b) # 배열간 곱셈


# In[56]:


# 브로드캐스트(Broadcast)
# 넘파이에서 특정 조건을 만족하면 형태가 다른 배열 간에도 연산이 가능하다.

# 세로 방향 확장
a = np.array([[1, 1], [1, 1]]) # 2차원 배열
b = np.array([1, 2]) # 1차원 배열

print(a + b) # b가 [[1, 2], [1, 2]]로 세로 확장 된다.

# 가로 방향 확장
c = np.array([[1], [2]]) # 2차원 배열
print(a + c) # c가 [[1, 1], [2, 2]]로 가로 확장 된다.


# In[73]:


# 1차원 배열의 경우, []안에 인덱스를 넣어 값을 추출, 변환이 가능
a = np.array([0, 1, 2, 3, 4, 5])
print(a[2])

a[2] = 9
print(a)

# 2차원 배열의 경우, []안에 인덱스를 2개로 지정하고 쉼표로 구분한다.
b = np.array([[0, 1, 2], [3, 4, 5]])
print(b[1, 2]) # b[1][2]와 같다.

b[1, 2] = 9
print(b)

# 만약 지정된 인덱스의 수가 배열의 차원 수보다 작을 경우 배열의 일부에 접근한다.
c = np.array([[0, 1, 2],[3, 4, 5],[6, 7, 8]])
print(c[1])

# 위의 방법을 이용해서 인덱스를 지정해 원소값을 배열로 변환할 수 있다.
c[1] = np.array([9, 10, 11])
print(c)

# [] 안에 조건문을 넣어 조건에 만족하는 값만 추출이 가능
d = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
print(d[d % 2 == 0])

# 인덱스에 배열을 이용할 수 있다. 즉, 인덱스를 넣는다.
# 이 경우 여러 개의 원소값을 한번에 접근할 수 있다.
e = np.zeros((3, 3))
f = np.array([8, 9])

e[np.array([0, 2]), np.array([0, 1])] = f # 0, 2번째 행의 0, 1의 열에 f값을 넣는다
print(e)


# In[84]:


# 슬라이싱(Slicing)
# 배열의 일부분 값을 추출하거나 변경할 수 있다.
# 배열명[이 인덱스 이상 : 이 인덱스 미만]
a = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
print(a[2:8])

# 배열명[이 인덱스 이상 : 이 인덱스 미만 : 간격]
print(a[2:8:2])

# 배열명[:]은 모든 원솟값을 지정
print(a[:])

# 범위를 지정한 슬라이싱
b = np.array([[0, 1, 2],
              [3, 4, 5],
              [6, 7, 8]])
print(b[0:2, 0:2]) # 각 차원의 범위를 지정

# 지정한 영역의 원소값을 바꾸는 것도 가능
b[0:2, 0:2] = np.array([[9, 9], 
                        [9, 9]]) # 왼쪽 위 영역을 변경
print(b)

# 3차원 배열
c = np.zeros(18).reshape(2, 3, 3)
print(c)

c[0, 0:2, 0:2] = np.ones(4).reshape(2, 2)
print(c)


# In[88]:


# Transpose
# 넘파이에는 축(axis) 개념이 있다. 축은 문자 그대로 좌표축을 뜻한다.
# 배열에는 값이 늘어서 있는 방향, 축은 차원의 수만큼 존재

# 2차원 배열의 축
a = np.array([[0, 1, 2],  # axis = 0은 [0, 1, 2], [3, 4, 5]
              [3, 4, 5]]) # axis = 1은 [0, 3], [1, 4], [2, 5]
print(a)

# 즉, 세로 방향 축은 axis = 0, 가로 방향 축은 axis = 1

# axis = 0을 1로 axis = 1을 0으로
print(a.transpose(1, 0)) 

# T로도 같은 조작이 가능
print(a.T)

# 3차원 배열의 축
# 가로, 세로 축 이외에도 깊이 축이 추가된다.
b = np.arange(12).reshape(2, 2, 3)
print(b)
# axis = 0을 1로, axis = 1을 2로, axis = 2를 0으로
print(b.transpose(1, 2, 0))


# In[99]:


# 넘파이 함수
# sum 함수
# 모든 원소값을 더한다.
a = np.array([[0, 1], [2, 3]])
print(np.sum(a))

# axis를 설정해 특정 축 방향으로 연산을 수행할 수 있다.
print(np.sum(a, axis=0)) # 세로 축 방향 계산
print(np.sum(a, axis=1)) # 가로 축 방향 계산
# keepdims = True를 설정하면 배열의 차원이 그대로 유지
print(np.sum(a, axis=1, keepdims=True))

# max 함수
# 원소값 중에서 최대값을 추출한다.
print(np.max(a))

# argmax 함수
# 최대값의 인덱스를 얻는다.
print(np.argmax(a, axis=0)) # 세로 축 방향 최대값의 인덱스를 추출한다.

# where 함수
# 배열에 대해 조건에 따라 원소값을 변경하고 새로운 배열을 생성한다.
# np.where(조건, 조건을 만족하는 값, 조건을 만족하지 않는 값)
print(np.where(a<2, 9, a)) # 새로운 배열은 조건을 만족하면 9, 조건을 만족하지 않으면 원래의 값을 유지


# In[101]:


# Matplotlib

# 주피터 노트북으로 맷플롯립 그래프를 인라인으로 표시하기 위해서는, 코드의 첫부분에 추가해야한다.
get_ipython().run_line_magic('matplotlib', 'inline')

import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 2 * np.pi) # 0 ~ 2π 까지
y = np.sin(x)

plt.plot(x, y)
plt.show()


# In[102]:


# 디자인된 그래프 생성
get_ipython().run_line_magic('matplotlib', 'inline')

x = np.linspace(0, 2 * np.pi) # 0 ~ 2π 까지
y_sin = np.sin(x)
y_cos = np.cos(x)

plt.xlabel("x value") # 축 이름
plt.ylabel("y value") # 축 이름

plt.title("sin/cos") # 그래프 이름

plt.plot(x, y_sin, label="sin") # 그래프 생성시 범례와 선의 스타일 지정
plt.plot(x, y_cos, label="cos", linestyle="dashed")
plt.legend()

plt.show()


# In[106]:


# 산포도 표시
# scatter 함수를 이용해 산포도를 생성할 수 있다.

x_1 = np.random.rand(100) - 1.0 # 이 그룹을 왼쪽으로 1만큼 이동
y_1 = np.random.rand(100)
x_2 = np.random.rand(100)
y_2 = np.random.rand(100)

# marker는 미리 지정된 종류가 있으니 찾아서 참고해 볼 것.
plt.scatter(x_1, y_1, marker="+")
plt.scatter(x_2, y_2, marker="x")

plt.show()


# In[107]:


# 이미지 표시
# imshow 함수는 배열을 이미지로 표현 가능
img = np.array([[0, 1, 2, 3],
                [4, 5, 6, 7],
                [8, 9, 10, 11],
                [12, 13, 14, 15]])

plt.imshow(img, "gray") # 그레이스케일로 표시
plt.colorbar() # 컬러 막대 표시

plt.show()


# In[108]:


# imread 함수는 외부에서 입력한 이미지 파일을 읽어들여 배열로 저장한다.
# imshow 함수를 이용해 이미지로 표시할 수 있다.
img = plt.imread("./flower.jpg")

plt.imshow(img)
plt.show()


# In[ ]:





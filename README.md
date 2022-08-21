# LinprogSolver4C ‒ Linear Programming Solver for Large-Scale Linear Programming

`LinprogSolver4C` is a small C++ library for solving **large-scale linear programming** problems via interior point method. 

---

## 1. What to do

The library solves a large-scale linear programming problem of the form

$$
\begin{array}{rl}
\min\ \ &c_1x_1+c_2x_2+\dots+c_nx_n\\
\textrm{s.t.}\ \ &a_{11}x_1+a_{12}x_2+\dots+a_{1n}x_n=b_1\\
&a_{21}x_1+a_{22}x_2+\dots+a_{2n}x_n=b_2\\
&\dots\\
&a_{m1}x_1+a_{m2}x_2+\dots+a_{mn}x_n=b_m\\
&x_1,x_2,\dots,x_n\ge0
\end{array}
$$

which also can be writes like

$$
\min\ \bf{cx}\ \ \textrm{s.t.}\left\{
\begin{array}{l}
\bf Ax=b,\\
\bf x\succcurlyeq 0
\end{array}\right.
$$

with $\bf{A}\in{R}_{m\times n},x\in R_{n\times 1},b\in R_{m\times 1}$.

---

## 2. Normalization of constraints

- For variables $x_i$ which missing non negative constraint:
  
  - $x_i=x_{i1}-x_{i2}$
  
  - $x_{i1}\ge0,x_{i2}\ge0$

- For each inequality constraints, we need to slack first:
  
  - $\sum_{j=0}^{n}a_{ij}x_{j}\le b_i$ or $\sum_{j=0}^{n}a_{ij}x_{j}\ge b_i$
  
  - $x_{n+i}\pm\sum_{j=0}^{n}a_{ij}x_{j}=b_i, x_{n+i}\ge 0$

----

## 3. Input data

The code reads data from **TXT file** (data.txt):

- The first line has two integers, `m` and `n`, indicating the number of constraints and the number of variables
- The next **(m)** lines had **(n + 1)** floats in each line, the first (n) numbers in each line are the coefficients before the variables($a_{ij}$), and the last one is $b_i$
- **(n)** numbers in the last line represent the coefficients before each variable in the objective function($c_i$)

For a sample:

$$
\begin{array}{rl}
\max&5x_1+10x_2\\
\textrm{s.t.}&8x_1+8x_2\le 160\\
&4x_1+12x_2\le180\\
&x_1\le15\\
&x_1,x_2\ge0
\end{array}
$$

first we made the following changes:

$$
\begin{array}{rl}
\min&-5x_1-10x_2\\
\textrm{s.t.}&8x_1+8x_2+x_3= 160\\
&4x_1+12x_2+x_4=180\\
&x_1+x_5=15\\
&x_1,x_2,x_3,x_4,x_5\ge0
\end{array}
$$

then the input data in `data.txt` should be:

```textile
3 5
-5 -10 0 0 0
8 8 1 0 0 160
4 12 0 1 0 180
1 0 0 0 1 15
```

It should be noted that the solution results obtained in above case are not so good. For this small-scale solution, we can try to use some integer programming solvers such as Google OR-Tools, or use the simplex method to solve. 

**For large-scale linear programming(include integers and floats), the accuracy is acceptable.**

---

## 4. How to build

You should make sure you have these compiling tools, in Ubuntu:

```bash
sudo apt install build-essential cmake make
```

then clone this project to your computer:

```bash
git clone git@github.com:ZhiQiangFeng/LinprogSolver4C.git
```

into this folder and:

```bash
cd LinprogSolver4C && cmake CMakeLists.txt
```

you will see `Makefile` created here, use `make` to get a executed file:

```bash
make
```

---

## 5. How to use

```bash
./linprog data.txt # any data paths
```

you will get these outputs in your terminal:

> 1
> 
> LP problem:
>  Iter  Residual        Mu    Alphax    Alphas
>     0  2.70e-01  1.54e+00       ---       ---
>     1  1.24e-03  6.01e-02  1.00e+00  1.00e+00
>     2  7.97e-08  3.86e-06  1.00e+00  1.00e+00
>     3  3.99e-12  1.93e-10  1.00e+00  1.00e+00
>     4  2.06e-16  9.66e-15  1.00e+00  1.00e+00
> 
> ----------------------------
> 
> Optx:
>     1       7.5
>     2        12
>     3   2.4e-14
>     4   2.6e-14
>     5       7.5
> 
> ----------------------------
> 
> linprog Terminated. Status : 0
> [Iters: 4] [Time: 2.82e-03s]

`0` - optimal

`1` - terminated by maxIter

`2` - infeasible

---

Thanks!

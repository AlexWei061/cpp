## 泰勒展开推导

$$ f(x) = a_0 + a_1x + a_2x^2 + a_3x^3 + \cdots + a_nx^n $$

$$ \therefore f(0) = a_0 + a_1*0 + a_2*0^2 + a_3*0^3 + \cdots + a_n*0^n = a_0 $$
$$ \therefore a_0 = f(0) = \frac{f^{(0)}(0)}{0!} $$

$$ f(x) = \sum_{i=0}^{n}a_ix^i $$

----

$$ f'(x) = 0 + a_1 + 2a_2x + 3a_3x^2 + \cdots + na_nx^{n-1} $$

$$ \therefore f'(0) = 0 + a_1 + 2a_2*0 + 3a_3*0^2 + \cdots + na_n*0^{n-1} = a_1 $$
$$ \therefore a_1 = f'(0) = \frac{f^{(1)}(0)}{1!} $$

$$ f'(x) = \sum_{i=0}^{n} [i \times a_i]  x^{i-1} $$

----

$$ f''(x) = 0 + 0 + 2a_2 + 6a_3x + \cdots + n(n-1)a_nx^{n-2} $$

$$ \therefore f''(0) = 0 + 0 + 2a_2 + 6a_3*0 + \cdots + n(n-1)a_n*0^{n-2} = 2a_2 $$
$$ \therefore a_2 = \frac{f''(0)}{2} = \frac{f^{(2)}(0)}{2!} $$

$$ f''(x) = \sum_{i=0}^{n} [i  (i-1)  a_i] x^{i-2} $$

----

$$ f'''(x) = 0 + 0 + 0 + 6a_3 + \cdots + n(n-1)(n-2)a_nx^{n-3} $$

$$ \therefore f'''(x) = 0 + 0 + 0 + 6a_3 + \cdots + n(n-1)(n-2)a_n*0^{n-3} = 6a_3 $$
$$ \therefore a_3 = \frac{f'''(0)}{6} = \frac{f^{(3)}(0)}{3!} $$

$$ f'''(x) = \sum_{i=0}^{n}[i(i-1)(i-2)a_i]x^{i-3} $$



$$ \cdots \cdots \cdots $$



$$ \therefore a_n = \frac{f^{(n)}(0)}{n!} $$

----

$$ \therefore f(x) = \sum_{n=0}^{N} \frac{f^{(n)}(0)}{n!}     x^n + Rn(x) $$

推广 :
$$ f(x) = \sum_{n=0}^{N} \frac{f^{(n)}(a)}{n!} (x-a)^n + Rn(x) $$

----


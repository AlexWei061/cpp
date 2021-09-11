## 最长不下降子序列 LIS 
~~Longest Increasing Subsequence~~

令 $f[i]$ 表示以 $a[i]$ 结尾的最长不下降子序列。这样对于 $\forall a[i]$ 来说有两种情况:

1. 如果存在 $a[i]$ 之前的元素 $a[j] (j < i)$ ，使得 $a[j] < a[i]$ 且 $f[j+1] > f[i]$ 那么就把 $a[i]$ 跟在以 $a[j]$ 结尾的 $LIS$ 后面，形成一条更大的不下降子序列。即 $f[i] = f[j] + 1$
2. 如果 $a[i]$ 比之前的元素都要大那么就只能自己形成一条不下降子序列，长度为1.

由此写出动态转移方程:
$$ f[i] = max\lbrace 1, f[j] + 1 \rbrace ， 其中 j \in \lbrace j \in N^* \mid 1 \leq j < i \rbrace $$

边界：
$$ f[i] = 1 (i > j, j \in \lbrace j \in N^* \mid 1 \leq j < i \rbrace) $$

整体时间复杂度 :
$$ O(n^2) $$

代码请参考 cpp/practice/SeniorHigh1/semester1/September2021/20210910/LIS.cpp

----

## 算法优化

详见 : https://www.luogu.com.cn/blog/w1049/solution-p1020

时间复杂度： $O(nlogn)$

&emsp; 用一个数组 $d$ 来存储不上升序列，把 $arr$ 中的元素依次加入 $d$ 中。<br>
~~d 的长度为 len~~
1. 若 $a[i] <= d[len]$ <br>
   则直接把 $a[i]$ 接在 $d$ 数组最后 <br>
   即： 
   $$d[++len] = a[i]$$

2. 若 $a[i] > d[len]$ <br>
   就找到 $d$ 中第一个小于 $a[i]$ 的数，并把这个数替换为 $a[i]$ <br>
   即：
   $$int \quad p = upper\_bound(d + 1, d + len + 1, a[i], greater<int>()) - d$$
   $$ d[p] = a[i] $$

&emsp; 到最后把 $a$ 数组遍历完一遍之后就得到了 $d$ 数组的 $len$ 也就是不下降子序列的长度

~~注意：$d$ 数组中存的并不是不下降子序列~~

代码见 ：cpp/practice/SeniorHigh1/semester1/September2021/20210911/LISOptimazation.cpp
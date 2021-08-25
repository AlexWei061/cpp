## 二分的几种形式

### 在单调递增序列 a 中查找 $\geq x$ 的数中**最小**的一个(即 x 或 x 的后续)

while(l < r){<br>
&emsp; int mid = **(l + r)** >> 1;<br>
&emsp; if(a[mid] >= x){<br>
&emsp; &emsp; r = mid;<br>
&emsp; }<br>
&emsp; else{<br>
&emsp; &emsp; l = mid + 1;<br>
&emsp; }<br>
}<br>
return a[l];

### 在单调递增序列 a 中查找 $\leq x$ 的数中**最大**的一个(即 x 或 x 的前驱)

while(l < r){<br>
&emsp; int mid = **(l + r + 1)** >> 1;<br>
&emsp; if(a[mid] <= x){<br>
&emsp; &emsp; l = mid;<br>
&emsp; }<br>
&emsp; else{<br>
&emsp; &emsp; r = mid - 1;<br>
&emsp; }<br>
}<br>
return a[l];

### 实数域上的二分

while(l + le-5 < r){<br>
&emsp; double mid = (l + r) >> 1;<br>
&emsp; if(clac(mid)){<br>
&emsp; &emsp; r = mid;<br>
&emsp; }<br>
&emsp; else{<br>
&emsp; &emsp; l = mid;<br>
&emsp; }<br>
}<br>

或者

for(int i = 0; i < 100; i++){<br>
&emsp; double mid  = (l + r) >> 1;<br>
&emsp; if(calc(mid)){<br>
&emsp; &emsp; r = mid;<br>
&emsp; }<br>
&emsp; else{<br>
&emsp; &emsp; l = mid;<br>
&emsp; }<br>
}
#include<bits/stdc++.h>
using namespace std;

double m, h;

int main(){
    scanf("%lf%lf", &m, &h);

    double BMI = m / (h * h);

    //printf("%lf", BMI);

    if(BMI < 18.5){
        printf("Underweight\n");
    }
    else if(18.5 <= BMI and BMI < 24){
        printf("Normal\n");
    }
    else{
        printf("%.4lf\nOverweight\n", BMI);
    }

    return 0;
}

/*

BMI 指数是国际上常用的衡量人体胖瘦程度的一个标准，其算法是 m / h^2 (40 ≤ m ≤ 120, 1.4 ≤ h ≤ 2.0)，
 
 其中 mm 是指体重（千克），hh 是指身高（米）。不同体型范围与判定结果如下：

小于 18.5：体重过轻，输出 Underweight；
大于等于 18.5 且小于 24：正常体重，输出 Normal；
大于等于 24：肥胖，不仅要输出 BMI 值（使用 cout 的默认精度），然后换行，还要输出 Overweight；
现在给出体重和身高数据，需要根据 BMI 指数判断体型状态并输出对应的判断。

对于非 C++ 语言，在输出时，请四舍五入保留六位有效数字输出，如果小数部分存在后缀 00，不要输出后缀 00。

请注意，保留六位有效数字不是保留六位小数。例如 114.5149114.5149 应该输出为 114.515114.515，9198.109198.10 应该输出为 9198.19198.1。

*/
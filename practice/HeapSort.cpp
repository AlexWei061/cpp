#include<bits/stdc++.h>
using namespace std;

int find_left_child(int n)
{
        return 2 * n ;
}

int find_right_child(int n)
{
        return 2 * n + 1;   
}

int find_greater_child(int num_list[], int n)
{
    if(num_list[find_left_child(n)] > num_list[find_right_child(n)])
    {
        return find_left_child(n);
    }
    else
    {
        return find_right_child(n);
    }
}

bool is_have_left_child(int len, int n)
{
    return (2 * n) > (len - 1) ? false : true;
}

bool is_have_right_child(int len, int n){
    return (2 * n + 1) > (len - 1) ? false : true;
}

void adjustheap(int num_list[], int len, int cur){
    while(is_have_left_child(len, cur))
        {
            //int gck = 0;
            if(!is_have_right_child(len,cur))
            {
                if(num_list[find_left_child(cur)] > num_list[cur])
                {
                    swap(num_list[find_left_child(cur)],num_list[cur]);
                    cur = find_left_child(cur);
                }
                else
                {
                    break;
                }
            }
            else if (num_list[find_greater_child(num_list, cur)] > num_list[cur])
            {                
                int gck = find_greater_child(num_list, cur);
                swap(num_list[gck], num_list[cur]);
                cur = gck; 
            }
            else
            {
                break;
            }
        }
}

void heapify(int num_list[],int len)
{
    for(int i = (len - 1); i >= 0; i--)
    {
        adjustheap(num_list, len, i);   
    }
}

void heapsort(int num_list[], int len)
{
    int i = 0;
    while(i <= (len - 1)){
        swap(num_list[0], num_list[len - i -1]);
        adjustheap(num_list, len - i -1, 0);
        i++;
    }
}

int num_list[] = { 1, 555, 23, 47356, 2, 0, 36453, 56, 65, 25643, 5454443, 526, 635, 635, 6, 643, 4, 5, 68, 65  };

int main()
{
    int len = sizeof(num_list) / sizeof(int);
    heapify(num_list,len);
    heapsort(num_list,len);
    for(int i = 0; i < len; i++)
    {
        cout << num_list[i] << " ";
    }
    cout << endl;
    return 0;
}

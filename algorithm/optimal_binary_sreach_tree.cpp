#include<bits/stdc++.h>
using namespace std;

/*
Dynamic tansfer equation :
    c[i, j] = min{c[i, k-1] + c[k, j]} + w[i, j]
    i < k <= j and w[i, j] = for(int k=i+1;i<=j;k++)ans+=frequce(i)
    w[i, j] = w[i, j-1] + p[j] + q[j]
*/

#define N 4

struct T{
    int w;
    int root;
    int cost;
};

void clac_w(int num_list[4][N + 1], T c[][N + 1]){
    for(int a = 0; a <= N; a++){
        for(int i = 0; i <= N; i++){
            int j = i + a;
            if(j > N){
                break;
            }
            if(a == 0){
                c[i][j].w = num_list[N - 1][j];
            }
            else{
                c[i][j].w = c[i][j - 1].w + num_list[2][j] + num_list[3][j];
            }
        }
    }
}

void clac_cost_and_root(int num_list[4][N + 1], T c[][N + 1]){
    clac_w(num_list, c);
    for(int a = 0; a <= N; a++){
        for(int i = 0; i <= N; i++){
            int j = i + a;
            if(j > N){
                break;
            }
            if(a == 0){
                c[i][j].cost = 0;
                c[i][j].root = 0;
            }
            
            else{
                int mmin = 65535;
                for(int k = i + 1; k <= j; k++){
                    if(c[i][k - 1].cost + c[k][j].cost < mmin){
                        mmin = c[i][k - 1].cost + c[k][j].cost;
                        c[i][j].root = k;
                    }
                }
                c[i][j].cost = mmin + c[i][j].w;
            }
        }
    }
}

int main(){
    int num_list[4][N + 1] = 
    {
           /*0  1   2   3   4 */
           { 0, 0,  0,  0,  0  },           //0
/*key*/    { 0, 10, 20, 30, 40 },           //1
/*frequce*/{ 0, 3 , 3 , 1 , 1  }, //p[i]    //2
/*frequce*/{ 2, 3,  1 , 1 , 1  }  //q[i]    //3
    };

    T c[N + 1][N + 1];
    clac_cost_and_root(num_list, c);
    /*
    for(int a = 0; a <= N; a++){
        for(int i = 0; i <= N; i++){
            int j = i + a;
            if(j > N){
                break;
            }
            cout << c[i][j].cost << " ";
        }
        cout << endl;
    }
    */
    int i = 0;
    int j = N;
    int binary_tree_list[2 * N + 2] = { 0 };
    //memset(binary_tree_list, 0, sizeof(binary_tree_list));
    int roott = 1;
    while(i != j){
        binary_tree_list[roott] = num_list[1][c[i][j].root];
        roott *= 2;
        j = c[i][j].root - 1;
    }
    i = 0;
    j = N;
    roott = 1;
    while(i != j){
        binary_tree_list[roott] = num_list[1][c[i][j].root];
        roott = roott * 2 + 1;
        i = c[i][j].root;
    }
    for(int i = 1; i <= N * 2 + 1; i++){
        cout << binary_tree_list[i] << " ";
    }
    cout << endl;
    return 0;
}


/*
brightness_4
// A naive recursive implementation of  
// optimal binary search tree problem  
#include <bits/stdc++.h> 
using namespace std; 
  
// A utility function to get sum of  
// array elements freq[i] to freq[j]  
int sum(int freq[], int i, int j);  
  
// A recursive function to calculate  
// cost of optimal binary search tree  
int optCost(int freq[], int i, int j)  
{  
    // Base cases  
    if (j < i)  // no elements in this subarray  
        return 0;  
    if (j == i) // one element in this subarray  
        return freq[i];  
      
    // Get sum of freq[i], freq[i+1], ... freq[j]  
    int fsum = sum(freq, i, j);  
      
    // Initialize minimum value  
    int min = INT_MAX;  
      
    // One by one consider all elements  
    // as root and recursively find cost  
    // of the BST, compare the cost with 
    // min and update min if needed  
    for (int r = i; r <= j; ++r)  
    {  
        int cost = optCost(freq, i, r - 1) +  
                   optCost(freq, r + 1, j);  
        if (cost < min)  
            min = cost;  
    }  
      
    // Return minimum value  
    return min + fsum;  
}  
  
// The main function that calculates  
// minimum cost of a Binary Search Tree.  
// It mainly uses optCost() to find  
// the optimal cost.  
int optimalSearchTree(int keys[],  
                      int freq[], int n)  
{  
    // Here array keys[] is assumed to be  
    // sorted in increasing order. If keys[]  
    // is not sorted, then add code to sort  
    // keys, and rearrange freq[] accordingly.  
    return optCost(freq, 0, n - 1);  
}  
  
// A utility function to get sum of  
// array elements freq[i] to freq[j]  
int sum(int freq[], int i, int j)  
{  
    int s = 0;  
    for (int k = i; k <= j; k++)  
    s += freq[k];  
    return s;  
}  
  
// Driver Code 
int main()  
{  
    int keys[] = {10, 12, 20};  
    int freq[] = {34, 8, 50};  
    int n = sizeof(keys) / sizeof(keys[0]);  
    cout << "Cost of Optimal BST is " 
         << optimalSearchTree(keys, freq, n);  
    return 0;  
}  
  
// This is code is contributed 
// by rathbhupendra 
*/

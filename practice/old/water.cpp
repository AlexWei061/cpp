#include <bits/stdc++.h>
using namespace std;

typedef struct node_s{
	int total_sec;
	int now_sec;
	bool opened;   //false
} node_t;


void close_spout(node_t& node){
	node.opened = false;
} 

int time(int m, int n, int w[]){
	node_t* head = new node_t[m];
	memset(head, 0, m*sizeof(node_t));
	
	//1. 重置水龙头状态; reset spout state
	int have_water = 0;
	if(n>=m)
	{  	//reset all spouts to true 
		for(int i=0; i<m; i++){
			head[i].opened = true; 
			head[i].now_sec = w[i];
		}
		have_water = m;
	}
	else { //n < m reset n spouts to true
		for(int i=0; i<n; i++){
			head[i].opened = true; 
			head[i].now_sec = w[i];
		}	
		
		have_water = n;
	}
	
	while(true){
		int min_now_sec = 0;
		
		for(int i=0; i<m; i++){ //find min of all spouts
			if (head[i].opened==true){
				if(min_now_sec==0){
					min_now_sec = head[i].now_sec;
				}
				else{
					min_now_sec = min(min_now_sec,head[i].now_sec);
				}
			}
		}
		
		if(min_now_sec==0){
			break;
		}
		
		for(int i=0; i<m; i++){ //time out min_now_sec spout 
			if (head[i].opened==true){
				head[i].now_sec -=  min_now_sec;
				head[i].total_sec += min_now_sec;
				
				if(head[i].now_sec ==0){
					if(have_water<n){          //still have students are waiting for water
						head[i].now_sec = w[have_water];
						have_water++;
					} 
					else{
						close_spout(head[i]);
					}
				}
			}
		}
	}
	
	int max_total_time=head[0].total_sec;
	for(int i=1; i<m; i++){
		max_total_time = max(max_total_time,head[i].total_sec);
	}
	
	delete head;
	return max_total_time;
}


int main(){
	int m=0;                              //水龙头数量 
	int n=0;                              //接水人数 
	cin>>n>>m; 
	int * w = new int[n];                 //接水水量list 
	for(int i = 0;i<n;i++){  
		cin>>w[i];
	}
	cout<<time(m,n,w)<<endl;
	delete w;
	return 0;
}

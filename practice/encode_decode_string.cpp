#include <bits/stdc++.h>
#include <string>
using namespace std;
//add some comments here to try git merge from another person
/*
	encode steps:
	1.Ã¿¸ö×ÖÄ¸×óÒÆÈıÎ» eg:e -> b c -> z
	2.´óĞ¡Ğ´»¥»» eg:a->A L->l
	3.µ¹ĞòÅÅÁĞ eg:abc->cba 
*/
char upper_lower_translate(char c)
{
	if('A'<=c && c<='Z'){
		return c+32;
	}
	if('a'<=c && c<='z'){
		return c-32;
	}
	
	return c;
}

char left_shift(char c){
	if(c == 'a'){
		return 'x';
	}
	if(c == 'b'){
		return 'y';
	}
	if(c == 'c'){
		return 'z';
	}
	if(c<='z' && c>='d'){
		return c-3;
	} 
	if(c == 'A'){
		return 'X';
	}
	if(c == 'B'){
		return 'Y';
	}
	if(c == 'C'){
		return 'Z';
	}
	if(c<='Z' && c>='D'){
		return c-3;
	}
	return c;
}

void encode(char* str){
	int len = strlen(str); 
	for (int i=0; i<len/2; i++){
		swap(str[i],str[len-i-1]);
		str[i] = left_shift(str[i]);
		str[len-i-1] = left_shift(str[len-i-1]);
		str[i] = upper_lower_translate(str[i]);
		str[len-i-1] = upper_lower_translate(str[len-i-1]);
	}
}
	
char right_shift(char c){
	if(c == 'x'){
		return 'a';
	}
	if(c == 'y'){
		return 'b';
	}
	if(c == 'z'){
		return 'c';
	}
	if(c<='w' && c>='a'){
		return c+3;
	} 
	if(c == 'X'){
		return 'A';
	}
	if(c == 'Y'){
		return 'B';
	}
	if(c == 'Z'){
		return 'C';
	}
	if(c<='W' && c>='A'){
		return c+3;
	}
	return c;
}

void decode(char* str){
	int len = strlen(str); 
	for (int i=0; i<len/2; i++){
		swap(str[i],str[len-i-1]);
		str[i] = right_shift(str[i]);
		str[len-i-1] = right_shift(str[len-i-1]);
		str[i] = upper_lower_translate(str[i]);
		str[len-i-1] = upper_lower_translate(str[len-i-1]);
	}
}

int main(){
	char encrypt_str[256];
	
	encrypt_str[0] = 'A';
	encrypt_str[1] = 'l';
	encrypt_str[2] = 'e';
	encrypt_str[3] = 'x';
	encrypt_str[4] = 0;
	decode(encrypt_str); 
	cout<<encrypt_str<<endl;
	encode(encrypt_str);
	cout<<encrypt_str<<endl;
	return 0;
}


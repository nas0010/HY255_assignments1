/*
 * Nasia Boubourakij
 * assignment1
 * main.c
 *
*/

#include <stdio.h>
#include <stdlib.h>

#define akuro 'f'
#define tonos 39
#define dialytika 34

/*declarations*/
void print(int num);
enum states{S_N, S_n, S_M, S_m, S_norm}state;
enum states n(int n);
enum states m(int m);
enum states norm(int d);
enum states M(int M);
enum states N(int N);

/*function to initilise array with alfavhto*/
void initialiseArray(char alfavhto[256][3]){
	char kefalaia[]="AVGDEZH8IKLMNJOPRSSTYFXCW";
	char mikra[]="avgdezh8iklmnjoprsstyfxcw";
	int i,k=0,l=0;

	for(i=0;i<256;i++){
		if(i<182 || i>254){
			alfavhto[i][0]=i;/*set normal corespandance*/
			alfavhto[i][1]=akuro;
			alfavhto[i][2]=akuro;
		}else if(i>=193 &&i<218){
			/*get from kefalaia array all capital letters and put them in the correct position that corresponds to the number in iso*/
			alfavhto[i][0]=kefalaia[k];
			alfavhto[i][1]=akuro;
			alfavhto[i][2]=akuro;
			/*change J and C with correct combo ( KS and PS)*/
			if(i==206){
				alfavhto[i][0]='K';
				alfavhto[i][1]='S';
				alfavhto[i][2]=akuro;
			}
		       	if(i==216){
				alfavhto[i][0]='P';
				alfavhto[i][1]='S';
				alfavhto[i][2]=akuro;
			}
			k++;
		}else if(i>=220 && i<=223){
		    	alfavhto[i][1]=tonos;
		    	alfavhto[i][2]=akuro;

			if(i==223){
				alfavhto[220][0]= 'a';
				alfavhto[221][0]= 'e';
				alfavhto[222][0]= 'h';
				alfavhto[223][0]= 'i';			
			}
		}else if(i>=252 && i<=254){
			alfavhto[i][1]=tonos;
		    	alfavhto[i][2]=akuro;

			if(i==254){
				alfavhto[252][0]= 'o';
				alfavhto[253][0]= 'u';
				alfavhto[254][0]= 'w';	
			}	
		}else if(i>=225 && i<250){
			/*get from mikra array all small letters and put them in the correct position that corresponds to the number in iso*/
			alfavhto[i][0]=mikra[l];
			alfavhto[i][1]=akuro;
			alfavhto[i][2]=akuro;
			/*change j and c with correct combo ( ks and ps)*/
			if(i==238){
				alfavhto[i][0]='k';
				alfavhto[i][1]='s';
				alfavhto[i][2]=akuro;
			}
			if(i==248){
				alfavhto[i][0]='p';
				alfavhto[i][1]='s';
				alfavhto[i][2]=akuro;
			}
			l++;
		}else if(i>=182 && i<192){
			alfavhto[i][0]=i;
			alfavhto[i][1]=akuro;
			alfavhto[i][2]=akuro;
			if(i==191){ /*in last loop put values in array*/
				alfavhto[182][0] = tonos;
				alfavhto[182][1] = 'A';
				alfavhto[184][0] = tonos;
				alfavhto[184][1] = 'E';
				alfavhto[185][0] = tonos;
				alfavhto[185][1] = 'H';
				alfavhto[186][0] = tonos;
				alfavhto[186][1] = 'I';
				alfavhto[188][0] = tonos;
				alfavhto[188][1] = 'O';
				alfavhto[190][0] = tonos;
				alfavhto[190][1] = 'Y';
				alfavhto[191][0] = tonos;
				alfavhto[191][1] = 'W';
			}
		}
	}

	/*initialise positions that correspond to dialutika and tonos for i and y*/
	alfavhto[218][0] = 'I';
	alfavhto[218][1] = dialytika;
	alfavhto[192][0] = 'i';
	alfavhto[192][1] = tonos;
	alfavhto[192][2] = dialytika;
	alfavhto[250][0] = 'i';
	alfavhto[250][1] = dialytika;

	alfavhto[219][0] = 'Y';
	alfavhto[219][1] = dialytika;
	alfavhto[251][0] = 'u';
	alfavhto[251][1] = dialytika;
	alfavhto[224][0] = 'u';
	alfavhto[224][1] = tonos;
	alfavhto[224][2] = dialytika;


}


/*
*array with functions
*/
enum states(*action[])(int number)={N,n,M,m,norm};


enum states M(int index){
    switch(index) {
        	case 208:/*user typed MP*/
			print(66); 
			state=S_norm;
			break;
		case 240:/*user typed Mp*/
			print(66); 
			state=S_norm;
			break;
		case 204:/*user typed MM */
			print(204); 
			state=S_M;
			break;
		case 205:/*user typed MN*/
			print(204); 
			state=S_N;
			break;

		case 236:/*user typed Mm*/
			print(204); 
			state=S_m;
			break;
		case 237:/*user typed Mn*/
			print(204); 
			state=S_n;
			break;
		default:/*user typed M and a usual letter*/
			print(204); 
			print(index);
			state=S_norm;
			break;
	}	
    return state;
}

enum states m(int index){
        switch(index) {
                case 208:/*mP*/
    			print(98); 
                        state=S_norm;
                        break;
                case 240:/*mp*/
                        print(98); 
			state=S_norm;
                        break;
                case 204:/*mM*/
                        print(236); 
                        state=S_M;
                        break;
		case 205:/*mN*/
                        print(236); 
                        state=S_N;
                        break;

                case 236:/*mm*/
                        print(236); 
                        state=S_m;
                        break;
                case 237:/*mn*/
                        print(236); 
                        state=S_n;
                        break;
                default:/*m & usual letter*/
                        print(236); 
                        print(index);
                        state=S_norm;
                        break;
        }	return state;
}

enum states N(int index){       
        switch(index) {
              	case 204:/*NM*/
                        print(205); 
                        state=S_M;
                        break;
		case 205:/*NN*/
                        print(205); 
			state=S_N;
                        break;
		case 212:/*NT*/
                        print(68); 
                        state=S_norm;
                        break;
                case 236:/*Nm*/
                        print(205);
                        state=S_m;
                        break;
		case 237:/*Nn*/
			print(205); 
                        state=S_n;
                        break;
		case 244:/*Nt*/
                        print(68);
                        state=S_norm;
                        break;

                default:/*N &usual*/
                        print(205);
                        print(index);
                        state=S_norm;
                        break;
        }	return state;
}

enum states n(int index){
        switch(index) {
                case 212:/*nT*/
                        print(100); 
			state=S_norm;
                        break;
                case 236:/*nm*/
                        print(237); 
                        state= S_m;
                        break;
                case 244:/*nt*/
                        print(100); 
                        state= S_norm;
                        break;
		case 237:/*nn*/
                        print(237);  
                        state= S_n;
                        break;
                case 204:/*nM*/
                        print(237); 
                        state= S_M;
                        break;
		case 205:/*nN*/
                        print(237);  
                        state= S_N;
                        break;
                default:/*n&usual*/
                        print(237);
                        print(index);
                        state=S_norm;
                        break;
        }	
	return state;
}

enum states norm(int index){		
		if(index==205){ /*user typed N*/
			state=S_N;
		}else if(index==204){/*user typed M*/
			state=S_M;
		}else if(index==237){/*user typed n*/
			state=S_n;
		}else if(index==236){/*user typed m*/
			state=S_m;
		}else{/*user typd usual letter with no exception*/
			print(index);
			state=S_norm;
				
   		}

	return state;

}



/*
*function to print a line from array shown by num
*/
void print(int num){
    	char array[256][3];
	int i=0;
	char tmp;
    	initialiseArray(array);
	
	for(i=0;i<3;i++){
	    tmp=array[num][i];
    		if(tmp!=akuro){
    	    		putchar(tmp);
    		}
	}
}
 
/*
*main gats a character input saves it in an integer(map)  and calls
*norm state function
*/
int main(){
	int map=0;
    	state=S_norm;

    	while((map=getchar())!=EOF){
		action[state](map);
	}

	return 0; 
}

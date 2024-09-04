#include"sudoku.h"
#include <assert.h>
#include <string.h>
Grid_T sudoku_read(void){
    int n,i=0,j=0;
    Grid_T *g = malloc(sizeof(Grid_T));
    while(i<=8){
        if(j==9){
          j=0;
          i++; 
        }
        scanf("%d",&n);
        grid_update_value(g, i, j, n);
        j++;
    }
    return *g;
}

/* Print the sudoku puzzle defined by g to stream s in the same format
   as expected by sudoku_read(). */
void sudoku_print(FILE *s, Grid_T g){
    int i=0,j=0,num;
    printf("D");
    assert(s);
    while(i<=8){
            for(j=0;j<9;j++) {
                num=grid_read_value(g,i,j);
                fprintf(s,"%d ",num);
        }
        
        fprintf(s, "\n");
        i++;
    }
    return;
}

int duplicate_checker(int *temp){
    int counter[10]={0};
    int i,t,flag=0;

    for(i=0;i<9;i++){
        counter[temp[i]]++;
    }

    for (t=1; t<10;t++){
    	  if (counter[t]>1){
    	      flag++;
    	    }            	
    }

     if(flag==0){
        return 0;
    }else{
        return 1;
    }
}
/* Print all row, col, sub-grid errors/conflicts found in puzzle g;
   some errors may be reported more than once. */
void sudoku_print_errors(Grid_T g){
    int i=0,j=0,a=0,b=0,t=0;
    int temp[9];

    if(sudoku_is_correct(g)) return;
    
    for(i=0;i<9;i++) {
        for(j=0;j<9;j++){
          temp[j] = grid_read_value(g,i,j);
        }

        if( duplicate_checker(temp)){
          printf("Error in row: %d \n",i+1);
        }
    }
    
    for(j=0;j<9;j++){
        for(i=0;i<9;i++){
           temp[i] = grid_read_value(g,i,j);
         }

        if( duplicate_checker(temp))
        {
            printf("Error in col: %d \n",j+1);
        }
    }
    
    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
            for(a=i;a<i+3;a++){
               for(b=j;b<j+3;b++){
                temp[t]=grid_read_value(g,a,b);
                t++;
               }
            }
            t=0;
            if( duplicate_checker(temp)){
                    printf("Error in block: %d \n",i+1+(j/3));
                }
        }
    }
    return;
}

/* Return true iff puzzle g is correct. */
int sudoku_is_correct(Grid_T g){
    
    int temp[9],t,i,j,a,b;

    for(i=0;i<9;i++){
          for(j=0;j<9;j++){
               temp[j] = grid_read_value(g,i,j);
            }
          if( duplicate_checker(temp)) return 0;

          for(t=0;t<9;t++){
              temp[j] = grid_read_value(g,t,i);
            }
          if( duplicate_checker(temp)) return 0;
      }

    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
            for(a=i;a<i+3;a++){
               for(b=j;b<j+3;b++){
                temp[t]=grid_read_value(g,a,b);
                t++;
               }
            }
            t=0;
            if( duplicate_checker(temp)) return 0;
        }
    }
    return 1;
}

static void sudoku_init_choices(Grid_T *g){
    int subGrid[9],i=0,j=0,t=0,k=0,n=0;
    
    t=t-t%3;
    k=k-k%3;
    grid_set_unique(g);   
    for(i=0;i<3;i++){
          for(j=0;j<3;j++){
                subGrid[n++] = grid_read_value(*g,t+i,k+j);
            }
    }

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            t=grid_read_value(*g,i,j);
            if(t==0){
                for(k=1;k<10;k++){
                     grid_set_choice(g,i,j,k);
                }
                grid_set_count(g,i,j);
                k=0;
                while(k<9){
                    t=grid_read_value(*g,i,k);/*row*/
                    grid_remove_choice(g,i,j,t);
                    t=grid_read_value(*g,k,j);/*col*/
                    grid_remove_choice(g,i,j,t);
                    grid_remove_choice(g,i,j,subGrid[k]);
                    k++;
                }

            }

        }
    }
    return;
}

static int sudoku_try_next(Grid_T g, int *row, int *col){
    int i,j,n,count=9;

    srand(getpid());
    i = rand()%9;

    for(n=0;n<9;n++){
        for(j=0;j<9;j++){
           
            if(grid_read_count(g,i,j)==0){
               return 0;
             }
            if(grid_read_count(g,i,j) < count){
                *row = i;
                *col = j;
                count = grid_read_count(g,i,j);
            }
        }
          i++;
        if(i == 9){
            i = 0;
          }
    }
    for(i=1;i<10;i++){
        if(grid_choice_is_valid(g, *row, *col, i)){
           return i;
         }
    }
    return 0;
}/************************************/

static int sudoku_update_choice(Grid_T *g, int i, int j, int n){
    int temp;
    grid_remove_choice(g,i,j,n);
    grid_update_value(g,i,j,n);
    temp=grid_read_count(*g,i,j);
    return temp;
}

static void sudoku_eliminate_choice(Grid_T *g, int r, int c, int n){
    int i=0,j=0,k=0;
    c = c - c%3;
    r = r - r%3;
    while(i<9){
        grid_remove_choice(g,r,i,n);
        grid_remove_choice(g,i,c,n);
        if(i==8){
            for(k=0;k<3;k++){
                for(j=0;j<3;j++){
                    grid_remove_choice(g,k+r,j+c,n);
                }
            }
        }
        i++;
    }

}

/* Sovle puzzle g and return the solved puzzle; if the puzzle has
   multiple solutions, return one of the possible solutions.*/
Grid_T sudoku_solve(Grid_T g){
    int i,j;
    int n;
    Grid_T temp;
    
    sudoku_init_choices(&g);
       while( (n = sudoku_try_next(g,&i,&j))){
        if(n == 0)    return g;

        if(sudoku_update_choice(&g,i,j,n) != 0){
            temp = sudoku_solve(g);
            if(sudoku_is_correct(temp)){
                if(grid_read_count(temp,i,j)!=0)  grid_clear_unique(&temp);
                
                return temp;
            }
            grid_update_value(&g,i,j,0); 
        }
        else   sudoku_eliminate_choice(&g,i,j,n);
        
    }
    return g;
}

/* Returns true if solution g, as returned by sudoku_solve, has a
   unique choice for each step (no backtracking required). (Note, g
   must have been computed with the use of sudoku_solve.) */
int sudoku_solution_is_unique(Grid_T g){
    int temp;
    temp=(grid_read_unique(g));
    return temp;
}

Grid_T sudoku_generate_complete(){
    int i=0,j=0;
    Grid_T g,temp;
    
   while(i<9){
       for(j=0;j<9;j++){
            grid_update_value(&g,i,j,0);
          }
          
          i++;
      }
      temp=sudoku_solve(g);
    return temp;
}

/* Generate and return a sudoku puzzle with "approximately" nelts
   elements having non-0 value. The smaller nelts the harder may be to
   generate/solve the puzzle. For instance, nelts=81 should return a
   completed and correct puzzle. */
Grid_T sudoku_generate(int nelts){
    int i,j,n;
    Grid_T g;
    
    g = sudoku_generate_complete();
    for(n=0;n<81-nelts;n++){
        while(grid_read_value(g,i,j)==0){
            j= rand()%9;
            i= rand()%9;
            
        }
        grid_update_value(&g,i,j,0);
    }

    return g;
}

int main(int argc, char *argv[])
{
    Grid_T g;
      
      if(argc==1 && !strcmp(argv[0] ,"sudoku")){
            printf("Give a new sudoku:\n");
            g = sudoku_read();
            sudoku_print(stderr,g);
            g = sudoku_solve(g);
            if(!sudoku_is_correct(g)){
                sudoku_print_errors(g);
            }else{
                if(grid_read_unique(g)) printf("(unique)");
            }
            printf("Solution:\n");
            sudoku_print(stdout,g);
           
      }else if(!strcmp(argv[1] ,"-c")) {
	    
            printf("Give a new sudku:\n");
            g = sudoku_read();
            sudoku_print(stderr,g);
            if(!sudoku_is_correct(g)){
                fprintf(stderr,"Sudoku is wrong\n");
                sudoku_print_errors(g);
            }
            else fprintf(stderr,"Sudoku is correct\n");

       }else if(!strcmp(argv[1] ,"-g") && argc==3 ){
	     sudoku_print(stdout, sudoku_generate( atoi(argv[2]) ));
       }else if(argc==4&& !strcmp("-u", argv[3])){
                do{
                    g=sudoku_generate(atoi(argv[2]));
                    }while(grid_read_unique(g));
                 sudoku_print(stdout,g);
            }

        
    
    return 0;
}

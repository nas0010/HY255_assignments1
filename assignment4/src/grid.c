#include "grid.h"

/* check if i and j are valid*/
int simple_check(int i,int j){
    if(i>=0 && i<=8 && j>=0 && j<=8){
        return 1;
    }else return 0;
}
/* update value of i,j to n */
void grid_update_value(Grid_T *g, int i, int j, int n){
    if(simple_check(i,j)){
         g->elts[i][j].val=n;
    }
    return;
}
/* return value of i,j */
int grid_read_value(Grid_T g, int i, int j){
    if(simple_check(i,j)) return g.elts[i][j].val;
    else return -2;
}
/* set (to 1) or clear (to 0) choice n for elt i,j */
void grid_set_choice(Grid_T *g, int i, int j, int n){
    if(simple_check(i,j)){
        g->elts[i][j].choices.num[n]=1;
    }
    return;
}
void grid_clear_choice(Grid_T *g, int i, int j, int n){
    if(simple_check(i,j)){
        g->elts[i][j].choices.num[n]=0;
    }
    return;
}
/* true if choice n for elt i,j is valid */
int grid_choice_is_valid(Grid_T g, int i, int j, int n){
    if(simple_check(i,j)){
        return g.elts[i][j].choices.num[n]==1;
    }else return -2;
}
/* remove n from choices of elt i,j and adjust count only if n is a
   valid choice for elt i,j */
void grid_remove_choice(Grid_T *g, int i, int j, int n){
    if(simple_check(i,j)){
        g->elts[i][j].choices.num[n]=0;
        if(grid_choice_is_valid(*g,i,j,n)){
            g->elts[i][j].choices.count-=1;
        }
    }
    return;
}
/* return count, set (to 9), or clear (to 0) count for elt i, j */
int grid_read_count(Grid_T g, int i, int j){
   if(simple_check(i,j)) return g.elts[i][j].choices.count;
   else return -1;
}
void grid_set_count(Grid_T *g, int i, int j){
    if(simple_check(i,j)) g->elts[i][j].choices.count=9;
    return;
}
void grid_clear_count(Grid_T *g, int i, int j){
    if(simple_check(i,j)) g->elts[i][j].choices.count=0;
    return;
}
/* return val, set (to 1), or clear (to 0) unique flag for g */
int grid_read_unique(Grid_T g){
    return g.unique;
}
void grid_set_unique(Grid_T *g){
    g->unique=1;
    return;
}
void grid_clear_unique(Grid_T *g){
    g->unique=0;
    return;
}

#define M2(x,y) #x #y #x
#define INC(x) x+1
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define REDUCE (x, y) x - y 
#define M = 10
int main(){
	int i,j=0,a[M],m;
	#ifdef M
	i=j;
	#else
	j=i;
	#endif
	i=10*INC(j);
	i=REDUCE (j,k);
	i=SQR(SQR(j++));
	i=CUBE(j);
	i=M1(j+k);
	puts(M2(i,j));
#undef INC
	i=INC(j);
#define INC
	i=INCE(j);

	return 0;

}

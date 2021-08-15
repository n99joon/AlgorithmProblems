#include <cstdio>
int a,b,c;
int n[101][101][101]={0};
int w(int x,int y,int z){
	x+=50;
	y+=50;
	z+=50;
	if(n[x][y][z]!=0) return n[x][y][z];
	if(x<=50 || y<=50 || z<=50) return 1;
	if(x>70 || y>70 || z>70) {
		n[x][y][z]=w(20,20,20);
		return n[x][y][z];
	}if(x<y && y<z){
		n[x][y][z]=w(x-50,y-50,z-51)+w(x-50,y-51,z-51)-w(x-50,y-51,z-50);
		return n[x][y][z];
	} 
	else {
		n[x][y][z]=w(x-51,y-50,z-50)+w(x-51,y-51,z-50)+w(x-51,y-50,z-51)-w(x-51,y-51,z-51);
		return n[x][y][z];
	} 
}

int main(){
	while(1){
		scanf("%d%d%d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1) break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
	
}
#include<bits/stdc++.h>
using namespace std;
char num[20][6][5]={
    {" - ","| |","   ","| |"," - "},
    {"   ","  |","   ","  |","   "},
    {" - ","  |"," - ","|  "," - "},
    {" - ","  |"," - ","  |"," - "},
    {"   ","| |"," - ","  |","  |"},
    {" - ","|  "," - ","  |"," - "},
    {" - ","|  "," - ","| |"," - "},
    {" - ","  |","   ","  |","   "},
    {" - ","| |"," - ","| |"," - "},
    {" - ","| |"," - ","  |"," - "}
};
char str[100][10000];
int n,y=0;
void print(int x){
    int nu=0;
    for(int i=y+1;i<y+n+2-1;i++)str[nu][i]=num[x][0][1];nu++;
    for(int j=0;j<n;j++){
        str[nu][y]=num[x][1][0];str[nu][y+n+2-1]=num[x][1][2];nu++;
    }
    for(int i=y+1;i<y+n+2-1;i++)str[nu][i]=num[x][2][1];nu++;
    for(int j=0;j<n;j++){
        str[nu][y]=num[x][3][0];str[nu][y+n+2-1]=num[x][3][2];nu++;
    }
    for(int i=y+1;i<y+n+2-1;i++)str[nu][i]=num[x][4][1];nu++;
    y+=n+2;y++;
}
char s[1000];
int main(){
    scanf("%d %s",&n,s);int len=strlen(s);
    for(int i=0;i<80;i++)
        for(int j=0;j<8000;j++)
            str[i][j]=' ';
    for(int i=0;i<len;i++){
        print(s[i]-'0');
    }
    for(int i=0;i<2*n+3;i++){
        for(int j=0;j<y;j++){
            printf("%c",str[i][j]);
        }printf("\n");
    }
    return 0;
}
 

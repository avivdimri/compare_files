#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <memory.h>
int sim =0;
int fdin;
int f2;
int skip_space(int file,char buf[]){
    //char buf[20];
    while(read(file,buf,1)>0){
        if(strcmp(buf," ")!=0){
            return 0;
        }
    }
    return -1;
}
int caseSenstive(char a,char b){
    if(a>b){
        return (a-32==b);
    }
    return (b-32==a);
}
int compare(char buf[],char buf2[]){
    if(strcmp(buf,buf2)!=0){
        if((strcmp(buf," ")==0)||(strcmp(buf,"\n")==0)){
            if(!skip_space(fdin,buf)){
                return compare(buf,buf2);
            }
            return -1;
        }
        if((strcmp(buf2," ")==0)||(strcmp(buf2,"\n")==0)) {
            if (!skip_space(f2, buf2)) {
                return compare(buf, buf2);
            }
            return -1;
        }
        if (!caseSenstive(buf[0],buf2[0])){
            return -1;
        }
        sim =1;
    }
    return 1;
}
int main() {
    fdin = open("name1.txt", O_RDONLY);
    f2 = open("name2.txt", O_RDONLY);
    if (fdin<0){
        perror("can't open");
        return -1;
    }
    char buf[20];
    char buf2[20];
    int i,j;
    i = read(fdin,buf,1);
    j = read(f2,buf2,1);
    while((i>0)&&(j>0)){
        if(compare(buf, buf2)<0){
            printf("not eqal");
            return -1;
        }
        i = read(fdin,buf,1);
        j = read(f2,buf2,1);
    }
    if (i^j){
        printf("not eqal");
        return -1;
    }
    if(sim){
        printf(" similar");
        return 0;
    }
    printf("eqal");
    return 0;
}


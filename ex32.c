//
// Created by אביב דמרי on 10/05/2021.
//

#include <stdio.h>
#include <fcntl.h>
#include <memory.h>
#include <dirent.h>

int main() {
    char line[150];
    char* dir_path,in_path,out_path;
    int fdin = open("/Users/aviv/Desktop/ex3/cmake-build-debug/students", O_RDONLY);
    if (fdin<0){
        printf("cant open file");
    }
    if(getline(&line, 150, fdin)==-1){
        printf("error line");
    }
    strcpy(dir_path,line);
    if(getline(&line, 150, fdin)==-1){
        printf("error line");
    }
    strcpy(in_path,line);
    if(getline(&line, 150, fdin)==-1){
        printf("error line");
    }
    strcpy(out_path,line);
    DIR* pDir;
    struct dirent *pDirent;
    if((pDir=opendir(dir_path))==NULL){
        printf("error dir");
    }
    while ((pDirent = readdir(pDir))!=NULL){
        printf(pDirent->d_ino , "\n");
        printf(pDirent->d_name , "\n");
        printf(pDirent->d_namlen, "\n");
        printf(pDirent->d_reclen + "\n");
        printf(pDirent->d_seekoff + "\n");
        printf(pDirent->d_type + "\n");
    }
}
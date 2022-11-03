#include<omp.h>
#include<stdio.h>

struct student{
    char name[20];
    char reg_no[10];
    int salary;
    char company[10];
} s[100];
int main(){
    for(int i=0;i<100;i++){
        s[i].name = "Gokul";
        
    }
}
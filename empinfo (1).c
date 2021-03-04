#include<stdio.h>
typedef struct employee{
            int eno;
            char ename[20];
            int esal;
            int da;
            int hra;
            int ta;
            int pf;
            int gs;
            int loan;
            int ls;
}employee;

void create(){
    FILE *fp;
    fp = fopen("employee.txt","w");
    employee *e;
    int n, i;
    printf("Enter how many employees you want = ");
    scanf("%d",&n);

    e = (employee*) calloc(n,sizeof(employee));

    for(i=0;i<n;i++)
    {
        printf("Enter employee no = ");
        scanf("%d",&e[i].eno);
        printf("Enter employee name = ");
        scanf("%s",e[i].ename);
        printf("Enter employee basic salary = ");
        scanf("%d",&e[i].esal);

        e[i].da = e[i].esal * 1.2;
        e[i].ta = e[i].esal * 0.1;
        e[i].hra = e[i].esal * 0.2;
        e[i].pf = e[i].esal * 0.1;
        e[i].loan = e[i].esal * 0.1;
        e[i].gs = e[i].da + e[i].ta + e[i].hra + e[i].esal;
        e[i].ls = e[i].gs - e[i].loan - e[i].pf;
        fwrite(&e[i],sizeof(employee),1,fp);


    }
    fclose(fp);


}
void display(){
    employee e1;
    FILE *fp;

    fp = fopen("employee.txt","r");
    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("%-10s%-15s%10s%7s%7s%7s%10s%5s%5s%10s\n","EMPNO","EMP NAME","BASIC","DA","HRA","TA","GROSS","LOAN","PF","GROSS","NET");
    printf("\n----------------------------------------------------------------------------------------------\n");
    while(fread(&e1,sizeof(employee),1,fp)){

    printf("%-10d%-15s%10d%7d%7d%7d%10d%5d%5d%10d\n",e1.eno,e1.ename,e1.esal,e1.da,e1.hra,e1.ta,e1.gs,e1.loan,e1.pf,e1.ls);

    }
    printf("\n----------------------------------------------------------------------------------------------\n");
    fclose(fp);
}
void append(){
    FILE *fp;
    fp = fopen("employee.txt","a");
    employee *e;
    int n, i;
    printf("Enter how many employees you want = ");
    scanf("%d",&n);

    e = (employee*) calloc(n,sizeof(employee));

    for(i=0;i<n;i++)
    {
        printf("Enter employee no = ");
        scanf("%d",&e[i].eno);
        printf("Enter employee name = ");
        scanf("%s",e[i].ename);
        printf("Enter employee basic salary = ");
        scanf("%d",&e[i].esal);

        e[i].da = e[i].esal * 1.2;
        e[i].ta = e[i].esal * 0.1;
        e[i].hra = e[i].esal * 0.2;
        e[i].pf = e[i].esal * 0.1;
        e[i].loan = e[i].esal * 0.1;
        e[i].gs = e[i].da + e[i].ta + e[i].hra + e[i].esal;
        e[i].ls = e[i].gs - e[i].loan - e[i].pf;
        fwrite(&e[i],sizeof(employee),1,fp);


    }
    fclose(fp);
}
void count(){
     FILE *fp;
    fp = fopen("employee.txt","r");
    fseek(fp,0,SEEK_END);
    int no = ftell(fp)/sizeof(employee);
    printf("\n----------------\n");
    printf("\nTOTAL NO OF RECORD = %d",no);
    printf("\n----------------\n");
    fclose(fp);
}
void search(){
    employee e1;
    int found = 0;
    FILE *fp;

    fp = fopen("employee.txt","r");
    int eno;
    printf("Enter empno to search :  ");
    scanf("%d",&eno);
    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("%-10s%-15s%10s%7s%7s%7s%10s%5s%5s%10s\n","EMPNO","EMP NAME","BASIC","DA","HRA","TA","GROSS","LOAN","PF","GROSS","NET");
    printf("\n----------------------------------------------------------------------------------------------\n");
    while(fread(&e1,sizeof(employee),1,fp)){
    if(eno == e1.eno){
    printf("%-10d%-15s%10d%7d%7d%7d%10d%5d%5d%10d\n",e1.eno,e1.ename,e1.esal,e1.da,e1.hra,e1.ta,e1.gs,e1.loan,e1.pf,e1.ls);
    found = 1;
    }

    }
    if(!found)
        printf("\nRECORD NOT FOUND...........");

    printf("\n----------------------------------------------------------------------------------------------\n");
    fclose(fp);
}
int main()
{
    int ch;

    do{
    printf("\n1.CREATE");
    printf("\n2.DISPLAY");
    printf("\n3.APPEND");
    printf("\n4.COUNT NO OF RECORDS");
    printf("\n5.SEARCH");
    printf("\n0.EXIT");
    printf("\nENTER YOUR CHOICE = ");
    scanf("%d",&ch);

    switch(ch){

    case 1: create();
            break;
    case 2: display();
            break;
    case 3: append();
            break;
    case 4: count();
            break;
    case 5: search();
            break;
    case 0: printf("\nTHANK YOU\n");
            break;
    }

    }while(ch!=0);


}

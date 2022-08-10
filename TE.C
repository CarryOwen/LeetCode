#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int my_atoi(char *p)
{
    int sample=1;
    int re=0;
    while (*p>'9'||*p<'0') 
        p++;
    if(*(p-1)=='-')
        sample=-1;
    while(*p<='9'&&*p>='0')
     {   
        re=re*10+(*p-'0');
        p++;
     }

    return re*sample;
    
}
int main()
{
    char *a=(char *)malloc(sizeof(char)*64);
    // char *p=strstr(a,"df");
    memset(a,0,64);
    char * b=(char *)malloc(sizeof(char)*32);
    memset(b,0,sizeof(char)*32);
    strcpy(b,"asdf:123:456798:asdf");
    
    // strncpy(b,a,3);
    strncat(a,b,3);
    int i=strcmp(a,b);
    char *p=strchr(a,'2');

    printf("%s\n",b);
    char *ptr;
    ptr=strtok(b, ":");
    while(ptr!=NULL)
    {
        printf("%s\n",ptr);
        ptr=strtok(NULL,":");
    }

    int kk=my_atoi(b);
    system("pause");
}

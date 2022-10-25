#include "stdio.h"
#include "string.h"


typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef short  int16_t;
typedef unsigned short  uint16_t;
typedef int  int32_t;
typedef unsigned   uint32_t;
 typedef long long  int64_t;
 typedef unsigned long long   uint64_t;
#pragma pack(4)
//类似的C++接口类

typedef struct  
{
    int (*my_print_1)(char *);
    int (*my_print_2)(char *);
}print_struct;

//需要注册的函数1
int true_print_1( char *str)
{
    printf("hello:%s\n", str);
}
//需要注册的函数2
int true_print_2( char *str)
{
    printf("CSDN:%s\n", str);
}
//以函数名为元素的结构体
print_struct testStruct =
{
    true_print_1,
    true_print_2,
};

struct hw
{
    int k;
    print_struct *printStruct;
};
//需要初始化的全局结构体
struct hw myhw;

//注册函数
void regiser_fun( print_struct * to_register,int i)
{
    myhw.printStruct=to_register;
    myhw.k = i;
}
static char* strtok_dgps(char* str, const char* delims)
{
    static char *src = NULL;
    char *p, *ret = 0;
    
    if(str != NULL)
    {
        src = str;
    }
    
    if(src == NULL)
    {
        return NULL;
    }
    
    if((p = strpbrk(src, delims)) != NULL)
    {
        *p = 0;
        ret = src;
        src = ++p;
    }
    else if(*src)
    {
        ret = src;
        src = NULL;
    }
    
    return ret;
}
//device SN
char source_id[16] = {'1','1','1','1','2','2','2','2','3','3','3','3','4','4','4','4'};
//Get from app
char target_id[16] = {0};
//Broadcast flag to app
char broadcast_id[16] = {'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F'};
typedef struct
{
    uint16_t    msg_len;
    char        source_id[16];
    char        target_id[16];
    uint32_t    time_stamp;
    uint8_t     msg_type;
    uint8_t     msg_num;
}gs_msg_header_t;
int main()
{
    gs_msg_header_t gs_msg_header = {0};
    int slen = sizeof(source_id);
    memcpy(gs_msg_header.target_id,source_id,strlen(source_id));
    int k = strncmp(gs_msg_header.target_id,source_id,strlen(gs_msg_header.target_id));
    getchar();
}

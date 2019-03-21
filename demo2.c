#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int flag;
    flag=fork();
    if(flag<0)//error in fork
    {
        printf("error in fork\n");
    }
    else if(flag>0)//parent
    {
        printf("This is parent process, its pid is %d\n",getpid());
        while(1);//vacant cycle
    }
    else//flag==0 child
    {
        printf("This id child process, its pid is %d\n",getpid());
        //open vi editer with "exec"
        int ret;
        ret=execl("/usr/bin/vi","vi","test.c",NULL);
        if(ret==-1)//error in execl
            perror("execl");
    }
    return 0;
}

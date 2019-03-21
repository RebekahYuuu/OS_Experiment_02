#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

char *a;
int main()
{
    pid_t p1,p2,p3,p4,p5;
    
    //if error occurred while creating root process, keep create it.
    while((p1=fork())==-1);

    if(p1==0)//root process
    {
        while((p2=fork())==-1);

        if(p2==0)//left child
        {
            while((p4=fork())==-1);

            if(p4==0)//left child
            {
                while(1)
                {
                    sleep(1);
                    printf("p4's pid is %d and its parent's pid is %d\n",getpid(),getppid());
                }

            }
            else
            {
                while((p5=fork())==-1);

                if(p5==0)//right child
                {
                    while(1)
                    {
                        sleep(1);
                        printf("p5's pid is %d and its parent's pid is %d\n",getpid(),getppid());
                    }
                }
            }
            while(1)
            {
                sleep(1);
                printf("p2's pid is %d and its parent's pid is %d\n",getpid(),getppid());
                printf("未初始化指针a，制造段错误：a[11]:%d\n",a[11]);
            }
        }
        else
        {
            while((p3=fork())==-1);

            if(p3==0)
            {
                while(1)
                {
                    sleep(1);
                    printf("p3's pid is %d and its parent's pid is %d\n",getpid(),getppid());
                }
            }

        }
        while(1)
        {
            sleep(1);
            printf("\np1's pid is %d and its parent's pid is %d\n",getpid(),getppid());
        }
    }
        return 0;
}




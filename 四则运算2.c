#include <stdio.h>
#include <time.h>

int main()
{
    int a,b,m,n;    //a,b为操作数，m为运算结果，n为用户输入结果
    char c;           //c为四则运算操作 
    int i,sum=0;      //i为题目数量,sum为正确数目
    srand(time(0));   //初始化随机数发生器
    
	//**主界面显示
    printf("\n                                              亓帅 & 王旭  \n");
    printf("  ********************欢迎使用小学四则运算********************\n\n");
 
	//**生成随机题目
    for(i=0;i<10;i++)
    {
        a=rand()%100+1;
        b=rand()%100+1;
        c=rand()%4;     //0+，1-，2×，3÷

        printf("                   第%d题：",i+1);
        switch(c)
        {
        case 0:                     //约束和
            while((m=a+b)>100)    
            {
                a=rand()%100+1;
                b=rand()%100+1;
            }
            printf("%d + %d = ",a,b);
            break;
        case 1:                     //约束差
            while(a>100||b>100)  
            {
                a=rand()%100+1;
                b=rand()%100+1;
            }
            if(a<b)            
            {
                m=a;
                a=b;
                b=m;
            }
            m=a-b;
            printf("%d - %d = ",a,b);
            break;
        case 2:                     //约束积
            while((m=a*b)>100)    
            {
                a=rand()%100+1;
                b=rand()%100+1;
            }
            printf("%d × %d = ",a,b);
            break;
        case 3:                     //约束商
            while(a>100||b>100||(a*b==0))   
            {
                a=rand()%100+1;
                b=rand()%100+1;
            }
            if(a<b)               
            {
                m=a;
                a=b;
                b=m;
            }
            a=(a/b)*b;            
            m=a/b;
            printf("%d ÷ %d = ",a,b);
            break;
        }
 
		//**用户输入计算结果
        scanf("%d",&n);
        if(m==n)
        {
            sum++; 
            printf("                                           正确\n");
        }
        else
            printf("                                           错误\n");
    }
    
	//**结果统计
    printf("\n            答对 %d 题，得分：%d",sum,sum*10);
        if(sum == 10)
            printf("      恭喜你取得满分!!! GREAT ");
        else if(sum>=60 & sum<100)
            printf("      成绩不错，继续保持！");
        else 
            printf("    再接再厉，给自己加加油吧！");
		printf("\n\n            ");
        return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include "../structure/Seqstack.h"
#include "../structure/Lkqueue.h"

/*
利用栈和队列数据结构综合应用来模拟停车场管理系统（车辆进入停车场，离开停车场，停车场外面等候排队停车）
参考数据与结构书：84页
*/
void main(){
    SeqStk ps, ts; //停车场和临时停车栈，限定停车位长度，所以用 顺序栈结构
    LkQue LQ; // 便道车辆队列，不限长度，所以用 链队结构
    int out, number, temp;
    char ch;

    InitStack(&ps); // 初始化 ps栈，存储停车场内停放的车辆
    InitStack(&ts); // 初始化 ts栈，用来存储临时退出停车场的车辆
    // 假如停车场是单向停车的，那么最开始停进去的车辆要退出来时，必须让停在其后面的车先退出
    InitQueue(&LQ); // 初始化 LQ队列，用来存储停在便道上排队待进入停车场进行停车的车辆
    out = 0; //0代表停车场内未找到车号为number的车辆，1代表找到了

    // printf("请输入要执行的动作命令，A:车辆进入停车场；C:查看停车内车辆；D:车辆开出停车场；L:查看便道车辆；Q:退出程序：");
    printf("\n请输入要执行的动作命令，A:车辆进入停车场；D:车辆开出停车场；Q:查看停车场车辆并退出：");
    scanf("%c", &ch); //读入命令，当命令为Q时退出程序
    while(1){
        if(ch=='Q'){
            printf("\n停车场已停放车辆如下：");
            while(!EmptyStack(&ps)){
                printf("，%d", GetTop(&ps));
                Pop(&ps);
            }

            printf("\n便道已排队的车辆如下：");
            while(!EmptyQueue(LQ)){
                printf("，%d", GetHead(LQ));
                OutQueue(&LQ);
            }

            break;
        }

        printf("\n请输入车辆号码："); 
        scanf("%d", &number); //读入车号
        switch(ch){                
            case 'A': // 命令为'A'时，车辆进入停车场
                {
                    if(ps.top==maxsize-1){
                        EnQueue(&LQ, number);
                        printf("停车场已满！第 %d 号车驶入便道等待停车！\n", number);
                    }else{
                        Push(&ps, number);
                        printf("车牌号为 %d 的车辆已成功停入停车场！\n", number);
                    }
                    break;
                }
            case 'D': // 命令为 'D' 时，车辆开出停车场
                {
                    while (!EmptyStack(&ps)){
                        temp = GetTop(&ps);  //temp临时变量，存放出栈的编号，即：停车场里的最后一辆车
                        Pop(&ps);
                        if(temp!=number){
                            Push(&ts, temp); //如果依次取出的车辆不是要真正驶出的那辆车，则放到另一个存放临时退出车辆的栈里面
                        }else{
                            printf("车牌号为 %d 的车辆，驶离停车场！\n", number);
                            out = 1;
                            break; //这个只会退出当前while层从而进入，后面的while执行代码，不会退出 case 'D':层
                        }   
                    }
                    
                    while(!EmptyStack(&ts)){ 
                        //将挪动到临时停车场的车开回停车场
                        temp = GetTop(&ts);
                        Pop(&ts);
                        Push(&ps, temp);
                    }

                    if(!out){
                        printf("停车场内没有停放车牌号为 %d 的车辆！\n", number);
                    }
                    else if(!EmptyQueue(LQ)){
                        // 如果有车辆驶离停车场，那么将停在便道车辆队列中的第一辆入驶入停车场内
                        temp = GetHead(LQ);
                        OutQueue(&LQ);
                        printf("便道上的车牌号为 %d 的车辆，驶入停车场！\n", temp);
                        Push(&ps, temp);
                    }
                    
                    out = 0; // 恢复变量状态
                    break;
                }
        }

        printf("\n请输入要执行的动作命令，A:车辆进入停车场；D:车辆开出停车场；Q:查看停车场车辆并退出：");
        scanf("%c", &ch); //读入命令，当命令为Q时退出程序
    }

    getch();
}
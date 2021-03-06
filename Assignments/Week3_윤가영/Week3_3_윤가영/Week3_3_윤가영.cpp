#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void myInfo(void) {
    printf("====================\n");
    printf("俳引: 紫戚獄左照穿因\n");
    printf("俳腰: 1971079\n");
    printf("失誤: 星亜慎\n");
    printf("====================\n");
}

void elementGeneration(int arrPtr[], int arrSize) //紫遂切亜 据馬澗 滴奄税 壕伸聖 脊径閤柔艦陥.
{
    for(int i = 0; i < arrSize; i++) scanf("%d", arrPtr+i);
    elementPrint(arrPtr, arrSize); //脊径閤精 壕伸聖 窒径杯艦陥.
}

void elementInsertion(int arrPtr[], int* arrSize) //壕伸拭 据社研 諮脊杯艦陥.
{
    int insLoc, insValue; //insLoc: 諮脊 是帖, insValue: 諮脊拝 葵
    printf("Input location and value to insert\n");
    scanf("%d%d", &insLoc, &insValue);
    if(insLoc < 1 || insLoc > *arrSize){ //紫遂切亜 脊径廃 諮脊 是帖 葵戚 骨是研 込嬢劾 井酔 敗呪研 曽戟杯艦陥.
        printf("Choose between 1 and %d\n\n", *arrSize);
        return;
    }
    int insIdx = insLoc - 1; //紫遂切亜 脊径廃 是帖澗 壕伸 昔畿什 雌生稽 1 希 旋生艦猿推..
    for(int i = *arrSize - 1; i >= insIdx; i--) arrPtr[i+1] = arrPtr[i]; //廃牒梢 及稽 葵聖 企脊背掃艦陥.
    arrPtr[insIdx] = insValue; //是税 for庚拭辞 諮脊是帖+1 腰属 据社猿走 葵聖 郊蚊爽醸生糠稽, 原走厳生稽 諮脊是帖拭 紫遂切 脊径葵聖 企脊杯艦陥.
    *arrSize = *arrSize + 1; //壕伸税 (叔霜旋昔 葵) 掩戚亜 1鯵 希 潅嬢概生糠稽 1 装亜獣佃掃艦陥.
    elementPrint(arrPtr, *arrSize);
}

void elementDeletion(int arrPtr[], int* arrSize) //壕伸税 据社研 肢薦馬澗 敗呪脊艦陥.
{
    int delLoc; //肢薦拝 据社税 是帖(紫遂切 脊径)研 煽舌拝 痕呪
    printf("Input location to delete\n");
    scanf("%d", &delLoc);

    if(delLoc < 1 || delLoc > *arrSize){ //骨是研 込嬢劾 井酔 敗呪研 曽戟杯艦陥.
        printf("No element in location %d\n\n", delLoc);
        return;
    }
    int delIdx = delLoc - 1; //昔畿什 = 脊径葵 - 1
    for(int i = delIdx; i < *arrSize; i++) arrPtr[i] = arrPtr[i+1]; //据社級聖 廃牒梢 蒋生稽 雁移掃艦陥.
    arrPtr[*arrSize] = 0; //原走厳生稽, 据掘 原走厳 昔畿什税 葵聖 0生稽 蒸蕉掃艦陥.

    *arrSize = *arrSize - 1; //壕伸税 紫戚綜亀 匝食掃艦陥.
    elementPrint(arrPtr, *arrSize); //衣引研 窒径杯艦陥.
}

void elementPrint(int arrPtr[], int arrSize)
{
    printf("Array:");
    for(int i = 0; i < arrSize; i++) printf("%3d", arrPtr[i]); //据社研 窒径杯艦陥.
    printf("\n\n");
}

int main(void) {
    myInfo();

    int numCount, i, v;
    int arr[MAX_SIZE];

    printf("How many numbers? ");
    scanf("%d", &numCount);
    printf("Input %d numbers\n", numCount);

    elementGeneration(arr, numCount); //耕庁 食奄辞 堂顕...! ぞぞぞぞぞぞぞ

    while(1) //鋼差庚
    {
        printf("Choose operation:\n1. insertion 2. deletion 3.output 0:program end\n");

        scanf("%d", &v);
        switch(v) {
            case 0: exit(0); break; //覗稽益轡 曽戟
            case 1:
                elementInsertion(arr, &numCount); //据社 諮脊
                break;
            case 2:
                elementDeletion(arr, &numCount); //据社 肢薦
                break;
            case 3:
                elementPrint(arr, numCount); //壕伸 窒径
                break;
            default: break;
        }
    }
}

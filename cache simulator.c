#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct mCache   //cache 구조체의 멤버 정의
{
    int valid;
    char *tag;
    char *block;
};

void hex_to_binary(char in[], char out[])
{
    int a = 0;  //각int형 변수가 나타내는 수를 지정
    int b = 1;
    int c = 2;
    int d = 3;
    int x = 4;
    int size = strlen(in);  //입력된 in의 배열의 길이를 size로 지정

    for (int i = 0; i < size; i++)      //각 입력된 수의 경우에 따라 out배열의 인덱스에 각 수를 지정해준다
    {
        if (in[i] =='0')    //입력된수가 '0'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '0';
            out[c+i*x] = '0';
            out[d+i*x] = '0';
        }
        else if (in[i] =='1')//입력된수가 '1'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '0';
            out[c+i*x] = '0';
            out[d+i*x] = '1';
        }    
        else if (in[i] =='2')//입력된수가 '2'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '0';
            out[c+i*x] = '1';
            out[d+i*x] = '0';
        }    
        else if (in[i] =='3')//입력된수가 '3'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '0';
            out[c+i*x] = '1';
            out[d+i*x] = '1';
        }    
        
        else if (in[i] =='5')//입력된수가 '5'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '1';
            out[c+i*x] = '0';
            out[d+i*x] = '1';
        }    
        else if (in[i] =='6')//입력된수가 '6'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '1';
            out[c+i*x] = '1';
            out[d+i*x] = '0';
        }    
        else if (in[i] =='7')//입력된수가 '7'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '1';
            out[c+i*x] = '1';
            out[d+i*x] = '1';
        }    
        else if (in[i] =='8')//입력된수가 '8'일경우
        {
            out[a+i*x] = '1';
            out[b+i*x] = '0';
            out[c+i*x] = '0';
            out[d+i*x] = '0';
        }
        else if (in[i] =='9')//입력된수가 '9'일경우
        {
            out[a+i*x] = '1';
            out[b+i*x] = '0';
            out[c+i*x] = '0';
            out[d+i*x] = '1';
        }
        else if (in[i] =='a')//입력된수가 'a'일경우
        {    
            out[a+i*x] = '1';
            out[b+i*x] = '0';
            out[c+i*x] = '1';
            out[d+i*x] = '0';
        }
        else if (in[i] =='b')//입력된수가 'b'일경우
        {
            out[a+i*x] = '1';
            out[b+i*x] = '0';
            out[c+i*x] = '1';
            out[d+i*x] = '1';
        }
        else if (in[i] =='c')//입력된수가 'c'일경우
        {
            out[a+i*x] = '1';
            out[b+i*x] = '1';
            out[c+i*x] = '0';
            out[d+i*x] = '0';
        }
        else if (in[i] =='d')//입력된수가 'd'일경우
        {    
            out[a+i*x] = '1';
            out[b+i*x] = '1';
            out[c+i*x] = '0';
            out[d+i*x] = '1';
        }
        else if (in[i] =='e')//입력된수가 'e'일경우
        {    
            out[a+i*x] = '1';
            out[b+i*x] = '1';
            out[c+i*x] = '1';
            out[d+i*x] = '0';
        }
        else if (in[i] =='f')//입력된수가 'f'일경우
        {
            out[a+i*x] = '1';
            out[b+i*x] = '1';
            out[c+i*x] = '1';
            out[d+i*x] = '1';
        }
        else if (in[i] =='x')//입력된수가 'x'일경우
        {
            out[a+i*x] = '0';
            out[b+i*x] = '1';
            out[c+i*x] = '0';
            out[d+i*x] = '0';
        }    
    }
    out[32] = '\0'; //null문자를 추가
}




int main(int argc, char* argv[])
{    
    FILE *trace;    //trace파일 선언
    int c_size; //캐시 사이즈
    int b_size; //블록사이즈
    int c_miss = 0; //캐시 miss
    int c_hit = 0;  //캐시 hit
    char* input;
    char* output;

    trace = fopen(argv[3], "r");    //trace를 염
    if(trace == NULL)   //trace파일이 열리지 않을경우
    {
        fprintf(stderr, "file is not open");
        return -1;
    }
    hex_to_binary(input, output);
    
    c_size = atoi(argv[1]);  //캐시의 사이즈를 입력받는다
    b_size = atoi(argv[2]);  //블록의 사이즈를 입력받는다
    
    printf("hit: %d\n", c_hit);  //캐시의hit를 출력한다
    printf("miss: %d\n", c_miss);    //캐시의 miss를 출력한다
}
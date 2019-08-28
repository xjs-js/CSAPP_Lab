#include <stdlib.h>
#include <stdio.h>

char * Hex2Binary(char * Hex)
{

    int hexSize = strlen(Hex) - 2;
    // 转换后二进制需要的位数
    int binarySize = hexSize * 4;
    char *str = Hex;
    char *result = calloc(binarySize+1, sizeof(char));
    for (int i = 0, j = 0; j < hexSize; ++j)
    {
        switch (str[j+2])
        {
        case '0':
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '0';
            break;
        case '1':
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '1';
            break;
        case '2':
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '0';
            break;
        case '3':
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '1';
            break;
        case '4':
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '0';
        case '5':
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '1';
        case '6':
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '0';
        case '7':
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '1';
        case '8':
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '0';
        case '9':
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '0';
            result[i++] = '1';
            break;
        case 'a':
        case 'A':
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '0';
            break;
        case 'b':
        case 'B':
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '1';
            result[i++] = '1';
            break;
        case 'c':
        case 'C':
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '0';
            break;
        case 'd':
        case 'D':
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '0';
            result[i++] = '1';
            break;
        case 'e':
        case 'E':
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '0';
            break;
        case 'f':
        case 'F':
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '1';
            result[i++] = '1';
            break;
        default:
            printf("Invalid Input\n");
            return "NULL";
        }
    }
    result[binarySize] = '\0';

    // leftmost的0不输出，找到第一个下标
    int firstNotZeroIndex = -1;
    for (int i = 0; i < binarySize; ++i)
    {
        if (result[i] == '0')
        {
            continue;
        }
        else if (result[i] != '0')
        {
            firstNotZeroIndex = i;
            break;
        }
    }

    // 都为0或者都不为0
    if (firstNotZeroIndex == -1)
    {
        // 都为0
        if (result[0] == '0')
        {
            result[1] = '\0';
            return result;
        }
        else if (result[0] != '0')
        {
            return result;
        }
    }
    else if (0 <= firstNotZeroIndex && firstNotZeroIndex < binarySize)
    {
        result = result + firstNotZeroIndex;
        return result;
    }
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        char *binary = Hex2Binary(argv[1]);
        printf("%s\n", binary);
    }
}
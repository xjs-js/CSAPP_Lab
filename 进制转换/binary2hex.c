#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * 每4个bit的二进制转换为十六进制字符
 * 
 * Params:
 *      char *bin: 如"0010"
 * 
 * Return:
 *      对应的16进制字符，如bin="0010"，应该返回'2'     
 * 
 **/
char binary2HexByDecimal(char *bin)
{
    int decimal = 0;
    for (int i = 0; i < 4; ++i)
    {
        decimal += (int)pow(2, 4-1-i) * (bin[i]-'0');
    }
    if (0 <= decimal && decimal <= 9)
    {
        return decimal + 48;
    }
    else if (10 <= decimal && decimal <= 15)
    {
        return decimal + 87;
    }
}

/**
 *从2进制转化为16进制，先补上前面的0，再调用binary2HexByDecimal
 * 
 * Params:
 *      char * binary: 输入的二进制字符串
 * 
 * Returns:
 *      返回16进制的字符串
 *
 * Example:
 *      char *binary = "10000";
 *      
 *      extendBinary = "00010000";
 *      binaryLenth  = 8; 
 *      
 *      return "10"
 **/
char * binary2Hex(char *binary)
{
    // 补上0之后的二进制字符串
    char *extendBinary;
    int  binaryLength = strlen(binary);
    // 更新二进制字符串的长度
    if (binaryLength % 4 != 0)
    {
        binaryLength = ((binaryLength/4)+1) * 4;
        extendBinary = (char *)calloc(binaryLength, sizeof(char));
        
        // 从后向前拷贝
        int j = binaryLength-1;
        for (int i = strlen(binary)-1; i >= 0; --i)
        {
            extendBinary[j--] = binary[i]; 
        }
        while(j >= 0)
        {
            extendBinary[j--] = '0';
        }
    }
    else if (binaryLength % 4 == 0)
    {
        extendBinary = binary;
    }

    char *returnHex;
    returnHex = calloc(binaryLength + 1, sizeof(char));
    int returnHexIndex = 0;

    char *item = calloc(5, sizeof(char));
    int count = binaryLength / 4;
    while(count--)
    {
        memcpy(item, extendBinary, sizeof(char) * 4);
        returnHex[returnHexIndex++] = binary2HexByDecimal(item); 
        extendBinary = extendBinary + 4;    
    }
    returnHex[returnHexIndex] = '\0';

    return returnHex;
}

int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        char *binary = argv[1];
        char *result = binary2Hex(binary);
        printf("%s\n", result);
    }
    return 0;
}
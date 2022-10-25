
// const UInt32 CRC32_POLYNOMIAL = 0xEDB88320;
// /* --------------------------------------------------------------------------
//  * Calculates the CRC-32 of a block of data all at once
//  * Copied from Novatel document
// -------------------------------------------------------------------------- */
// public
// static UInt32 ComputeCRC(Byte[] buf, UInt32 offset, UInt32 len)
// {
//     UInt32 ulTemp1;
//     UInt32 ulTemp2;
//     UInt32 ulCRC = 0;
//     UInt32 idx = 0;
//     while (idx < len)
//     {
//         ulTemp1 = (ulCRC >> 8) & (UInt32)0x00FFFFFFL;
//         ulTemp2 = CRC32Value(((UInt32)ulCRC ^ buf[offset + idx]) & 0xff);
//         ulCRC = ulTemp1 ^ ulTemp2;
//         idx++;
//     }
//     return (ulCRC);
// }

// private
// static UInt32 CRC32Value(UInt32 i)
// {
//     int j;
//     UInt32 ulCRC;
//     ulCRC = i;
//     for (j = 8; j > 0; j--)
//     {
//         if ((ulCRC & 0x1) == 1)
//             ulCRC = (ulCRC >> 1) ^ CRC32_POLYNOMIAL;
//         else
//             ulCRC >>= 1;
//     }
//     return ulCRC;
// }
#include "stdio.h"
#include "string.h"
typedef int  int32_t;
typedef short int  int16_t;
int32_t CRC32_POLYNOMIAL = 0xEDB88320;
int32_t CRC32Value(int32_t i)
{
    int32_t ulCRC = i;
    for (int j = 8; j > 0;j--)
    {
        if((ulCRC&0x01)==1)
        {
            ulCRC = (ulCRC >> 1) ^ CRC32_POLYNOMIAL;
            printf("ulCRC = 0x%08x\n",ulCRC);
        }
        else
        {
            ulCRC >>= 1;
        }
    }
    return ulCRC;
}
int32_t ComputeCRC(int32_t *buf,int16_t len)
{
    int32_t ulTemp1;
    int32_t ulTemp2;
    int32_t ulCRC = 0;
    int32_t idx = 0;
    while (idx < len)
    {
        ulTemp1 = (ulCRC >> 8) & (int32_t)0x00FFFFFF;
        ulTemp2 = CRC32Value(((int32_t)ulCRC ^ buf[idx]) & 0xff);
        ulCRC = ulTemp1 ^ ulTemp2;
        idx++;
    }
    printf("last ulCRC = 0x%08x\n",ulCRC);
    return (ulCRC);
}
int main()
{
    int32_t buf[16] = {0x00,0xaf,0x00,0x20,0xa9,0x86,0x01,0x08,0xb1,0x86,0x01,0x08,0xd5,0x5e,0x01,0x08};
    printf("%d\n",ComputeCRC(buf, 16));
    getchar();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[10], b[10], c[10], temp, sum[10], sum1[10], carry = 0, n, i, p, chkr[20];

    printf("-------------------------Checksum program for two segments only-------------------------\n\r");
    printf("Enter athe number of bits of each segment: ");
    scanf("%d", &n);
    printf("\n\rAt the RECEIVER's end......");
    carry = 0;
    printf("\n\rEnter the receieved bits one after another:\n\r");
    for (i = n - 1; i >= 0; i--)
    {
        scanf("%d", &a[i]);
    }

    printf("\n\r");
    for (i = n - 1; i >= 0; i--)
    {
        scanf("%d", &b[i]);
    }
    printf("\n\rNext bits will be identified as checksum\n\r");
    for (i = n - 1; i >= 0; i--)
    {
        scanf("%d", &c[i]);
    }

    printf("\n\r---------------Calculating Receiver's Checksum----------------");
    for (i = 0; i < n; i++)
    {
        sum[i] = (a[i] + b[i] + c[i] + carry) % 2;
        carry = (a[i] + b[i] + c[i] + carry) / 2;
    }

    printf("\nSum........");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d", sum1[i]);
    }

    if (carry == 1)
    {
        for (i = 0; i < n; i++)
        {
            p = (sum[i] + carry) % 2;
            carry = (sum[i] + carry) / 2;
            sum1[i] = p;
        }
    }
    printf("\nWrapped Sum.......");
    for (i = n - 1; i >= 0; i--)
    {
        chkr[i] = sum1[i];
        printf("%d", sum1[i]);
    }

    printf("\nChecksum......");
    temp = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (chkr[i] == 1)
            chkr[i] = 0;
        else
            chkr[i] = 1;
        temp = temp + chkr[i];
        printf("%d", chkr[i]);
    }
    if (temp != 0)
        printf("\n\rChecksum FAILED, Received data is corrupted. ");
    else
        printf("\n\rChecksum PASSED.");
}
#include <stdio.h>

void PrintBinaryFromDecimal(unsigned char decimal)
{
	unsigned char bitOffset = 7;
	constexpr unsigned char bitMask = 0b00000001;

	for (unsigned char i = 0; i < 8; ++i)
	{
		printf("%u", (decimal >> (bitOffset - i)) & bitMask);
	}
	printf("\n");
}

void ControlBitFlags()
{
	unsigned short bitFlags = 0;
	unsigned short offset = 0;
	unsigned char flags = 0;

	while (1)
	{
		printf("��Ʈ offset: ");
		scanf_s("%hd", &offset);
		printf("OFF/ON [0, 1]: ");
		scanf_s("%hhd", &flags);

		bitFlags |= (0b00000001 << offset);

		for (int offset = 15; offset > -1; --offset)
		{
			printf("offset %2d Bit: ", offset);
			if (bitFlags & (0b00000001 << offset))
			{
				printf("ON");
			}
			else
			{
				printf("OFF");
			}
			printf("\n");
		}
		printf("\n");
	}	
}

void ControlBitFlagsToByteUnit()
{
	unsigned int bitFlags = 0;
	unsigned char byteOffset = 0;
	unsigned char flags = 0;

	while (1)
	{
		printf("����Ʈ ���� offset: ");
		scanf_s("%hhd", &byteOffset);
		printf("�� [0~255]: ");
		scanf_s("%hhd", &flags);

		bitFlags &= (~(0x000000FF << (byteOffset * 8)));
		bitFlags |= (flags << (byteOffset * 8));

		for (int byteOffset = 0; byteOffset < sizeof(bitFlags); ++byteOffset)
		{
			printf("offset %d ����Ʈ ��: %d\n", byteOffset, bitFlags >> byteOffset * 8 & 0x000000FF);
		}

		printf("\n��ü 4����Ʈ ��: 0x%08x\n\n", bitFlags);
	}
}

int main(void)
{
	PrintBinaryFromDecimal(40);
	ControlBitFlags();
	ControlBitFlagsToByteUnit();
	return 0;
}
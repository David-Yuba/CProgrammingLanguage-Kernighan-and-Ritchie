#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void printBitWidths(){
	printf("-----------------------------BIT WIDTHS-----------------------------\n");
	printf("Bit width of char: %d\n"
			"Bit width of short: %d\n"
			"Bit width of int: %d\n"
			"Bit width of long: %d\n"
			"Bit width of long long: %d\n"
			"Bit width of float: %d\n"
			"Bit width of double: %d\n"
			"Bit width of long double: %d\n",
			CHAR_BIT, sizeof(short)*CHAR_BIT, sizeof(int)*CHAR_BIT, sizeof(long)*CHAR_BIT, sizeof(long long)*CHAR_BIT,sizeof(float)*CHAR_BIT,sizeof(double)*CHAR_BIT,sizeof(long double)*CHAR_BIT);
}

void printMinMaxSigned(){
	printf("-----------------------------MIN/MAX SIGNED VALUES-----------------------------\n");
	printf("Min/Max value of char: %d/%d\n"
			"Min/Max value of short: %d/%d\n"
			"Min/Max value of int: %d/%d\n"
			"Min/Max value of long: %ld/%ld\n"
			"Min/Max value of long long: %lld/%lld\n"
			"Min/Max value of float: %e/%e\n"
			"Min/Max value of double: %le/%le\n"
			"Min/Max value of long double: %Le/%Le\n",
			CHAR_MIN, CHAR_MAX,
			SHRT_MIN, SHRT_MAX,
			INT_MIN, INT_MAX,
			LONG_MIN, LONG_MAX,
			LLONG_MIN, LLONG_MAX,
			FLT_MIN, FLT_MAX,
			DBL_MIN, DBL_MAX,
			LDBL_MIN, LDBL_MAX);
}

void printMaxUnsigned(){
	printf("-----------------------------MIN/MAX UNSIGNED VALUES-----------------------------\n");
	printf("Max value of char: %d\n"
			"Max value of short: %d\n"
			"Max value of int: %u\n"
			"Max value of long: %lu\n"
			"Max value of long long: %llu\n",
			UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX);
}

long long int getMinValue(short numberOfBytes){
	long long int minValue = -(long long int)powl(2,numberOfBytes*8 - 1);
	return minValue;
}

long long int getMaxValue(short numberOfBytes){
	long long int maxValue = (long long int)powl(2,numberOfBytes*8 - 1) - 1;
	return maxValue;
}

void printComputedMinMaxSigned(){
	printf("-----------------------------MIN/MAX COMPUTED SIGNED VALUES-----------------------------\n");
	printf("Min/Max value of char: %d/%d\n"
			"Min/Max value of short: %d/%d\n"
			"Min/Max value of int: %d/%d\n"
			"Min/Max value of long: %ld/%ld\n"
			"Min/Max value of long long: %lld/%lld\n",
			getMinValue(sizeof(char)), getMaxValue(sizeof(char)),
			getMinValue(sizeof(short)), getMaxValue(sizeof(short)),
			getMinValue(sizeof(int)), getMaxValue(sizeof(int)),
			getMinValue(sizeof(long)), getMaxValue(sizeof(long)),
			getMinValue(sizeof(long long)), getMaxValue(sizeof(long long)));
}

unsigned long long getMaxUnsignedValue(short numberOfBytes){
	unsigned long long int maxValue = (unsigned long long int)powl(2,numberOfBytes*8) - 1;
	return maxValue;
}

void printComputedMaxUnsigned(){
	printf("-----------------------------MIN/MAX COMPUTED UNSIGNED VALUES-----------------------------\n");
	printf("Max value of char: %d\n"
			"Max value of short: %d\n"
			"Max value of int: %u\n"
			"Max value of long: %lu\n"
			"Max value of long long: %llu\n",
			getMaxUnsignedValue(sizeof(char)), getMaxUnsignedValue(sizeof(short)), getMaxUnsignedValue(sizeof(int)), getMaxUnsignedValue(sizeof(long)), getMaxUnsignedValue(sizeof(long long)));
}

unsigned long long sumOfDigits(unsigned int numOfDigits){
	unsigned long long sum = 0;
	for(int i=0 ; i<numOfDigits ; i++)
		sum += (unsigned long long)powl(FLT_RADIX, i);
	printf("sum = %lld\n", sum);
	return sum;
}

void printFloatInformation(){
	float minFloatNumber = (-1) * (float)sumOfDigits(FLT_MANT_DIG - 1) * pow(FLT_RADIX, FLT_MAX_EXP) / pow(FLT_RADIX,FLT_MANT_DIG - 1);
	float minPositiveFloatNumber = (1) * (float)sumOfDigits(1) * pow(FLT_RADIX, FLT_MIN_EXP - 1);
	float maxFloatNumber = (1) * (float)sumOfDigits(FLT_MANT_DIG - 1) * pow(FLT_RADIX, FLT_MAX_EXP) / pow(FLT_RADIX,FLT_MANT_DIG - 1);

	double minDoubleNumber = (double)(-1) * (double)sumOfDigits(DBL_MANT_DIG - 1) * powl(FLT_RADIX, DBL_MAX_EXP) / powl(FLT_RADIX,DBL_MANT_DIG - 1);
	double minPositiveDoubleNumber = (double)(1) * (double)sumOfDigits(1) * pow(FLT_RADIX, DBL_MIN_EXP - 1);
	double maxDoubleNumber = (double)(1) * (double)sumOfDigits(DBL_MANT_DIG - 1) * powl(FLT_RADIX, DBL_MAX_EXP) / powl(FLT_RADIX,DBL_MANT_DIG - 1);

	long double minLongDoubleNumber = (-1) * (long double)sumOfDigits(LDBL_MANT_DIG - 1) * powl(FLT_RADIX, LDBL_MAX_EXP - (LDBL_MANT_DIG - 1));
	long double minPositiveLongDoubleNumber = (1) * (long double)sumOfDigits(1) * powl(FLT_RADIX, LDBL_MIN_EXP - 1);
	long double maxLongDoubleNumber = (1)	* (long double)sumOfDigits(LDBL_MANT_DIG - 1) * powl(FLT_RADIX, LDBL_MAX_EXP - (LDBL_MANT_DIG - 1));

	printf("----------------------------Float encoding information----------------------------\n");
	printf(
		"Radix base = %d\n"
		"Sign bits = %d\n\n"
		"Float mantisse bits = %d\n"
		"Float exponent bits = %d\n"
		"Double mantisse bits = %d\n"
		"Double exponent bits = %d\n"
		"Long double mantisse bits = %d\n"
		"Long double exponent bits = %d\n\n"
		"Float min exponent = %d\n"
		"Float max exponent = %d\n"
		"Double min exponent = %d\n"
		"Double max exponent = %d\n"
		"Long double min exponent = %d\n"
		"Long double max exponent = %d\n\n"
		"Min float number = %e\n"
		"Min positive float number = %e\n"
		"Max float number = %e\n\n"
		"Min double number = %le\n"
		"Min positive double number = %le\n"
		"Max double number = %le\n\n"
		"Min long double number = %Le\n"
		"Min positve long double number = %Le\n"
		"Max long double number = %Le\n\n",
		FLT_RADIX, 1, 
		FLT_MANT_DIG - 1, sizeof(float)*CHAR_BIT - FLT_MANT_DIG,
		DBL_MANT_DIG - 1, sizeof(double)*CHAR_BIT - DBL_MANT_DIG,
		LDBL_MANT_DIG - 1, sizeof(long double)*CHAR_BIT - LDBL_MANT_DIG,
		FLT_MIN_EXP, FLT_MAX_EXP, 
		DBL_MIN_EXP, DBL_MAX_EXP, 
		LDBL_MIN_EXP, LDBL_MAX_EXP,
		minFloatNumber, minPositiveFloatNumber, maxFloatNumber,
		minDoubleNumber, minPositiveDoubleNumber, maxDoubleNumber,
		minLongDoubleNumber, minPositiveLongDoubleNumber, maxLongDoubleNumber
		);
	
}

double calculateFloatValue(int sign, int mantise, int exponent){
	return (sign == 1 ? -1 : 1) * ((double)mantise * pow((double)2, (double)exponent - 126)) / pow((double)FLT_RADIX, (double)(24 - 1));
}


void bitwiseOperators(){
	unsigned char a[4] = {-1, -1, -1, -1};
	a[3] = (unsigned char)(a[3] << 1 ) >> 1;

	a[2] = (unsigned char)(a[2] << 1) >> 1;

	unsigned int mantise = (((unsigned int *)(a))[0] << 9) >> 9;
	unsigned short exponent = ((((unsigned short *)(a))[1] >> 7) << 9) >> 9;
	unsigned char sign = a[3] >> 7;
	printf("----------------Bitwise operators----------------\n");
	printf("a hex = %x\t%x\t%x\t%x\n", a[0], a[1], a[2], a[3]);
	printf("mantise = %u\n"
		"exponent = %u\n"
		"sign = %s\n"
		"Max float value = %e\n"
		"Min float value = %e\n",
		mantise, exponent, sign == 1 ? "negative\n" : "positive\n",
		calculateFloatValue(sign, mantise, exponent),
		calculateFloatValue(1, mantise, 0));	
}

int main(){
	printBitWidths();
	printMinMaxSigned();
	printMaxUnsigned();
	printComputedMinMaxSigned();		
	printComputedMaxUnsigned();
	bitwiseOperators();
	printFloatInformation();

	return 0;
}
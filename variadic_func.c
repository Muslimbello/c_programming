#include <stdio.h>
#include <stdarg.h>

double cal_Average(int num, ...)
{
	va_list args;
	va_start(args, num);

	double sum = 0.0;
	for (int i = 0; i < num; i++)
	{
		sum += va_arg(args, double);
	}

	va_end(args);

	return sum / num;
}

int main()
{
	double result = calculateAverage(4, 10.5, 20.3, 30.8, 25.2);
	printf("Average: %lf\n", result);

	return 0;
}

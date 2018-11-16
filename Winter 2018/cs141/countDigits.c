unsigned int CountDigits(unsigned int n)
{
int counter;

	if (n / 10 < 0) 
	{
		return 1;
	}
	counter++;
	return 1 + CountDigits(n/10); 

//Create a function which can multiply two non negative numbers using only
//Assignement
//Bitwise operators
//equality checks and boolean combinations thereof

#include <iostream>

int Add(int a, int b)
{
	int tempA = a, tempB = b;
	int ans = 0;
	int cpt = 0;
	bool isCarry = false;
	while (tempA || tempB || isCarry)
	{
		bool LSBA = tempA & 1;
		bool LSBB = tempB & 1;
		ans |= (LSBA ^ LSBB ^ isCarry) << cpt;
		isCarry = (LSBA & LSBB) | (LSBA & isCarry) | (LSBB & isCarry);
		tempA >>= 1;
		tempB >>= 1;
		++cpt;
	}
	return ans;
}

int Multiplication(int a, int b)
{
	int ret = 0;
	int tempB = b;
	while (tempB)
	{
		int tempA = a;
		int tempOpr = tempB & ~(tempB - 1);
		while ((tempOpr & 1) == 0)
		{
			tempA <<= 1;
			tempOpr >>= 1;
		}
		ret = Add(ret, tempA);
		tempB = tempB & (tempB - 1);
	}
	return ret;
}

int main()
{
	std::cout << Multiplication(69, 420);
	return 0;
} 
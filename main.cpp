#include <iostream>
#include <random>
using namespace std;

void GetRandom(int min_value, int max_value)
{
    long * mass = new long[102];
    mass[101] = max_value;
	random_device _rand;
	mt19937 _srand(_rand());
	uniform_int_distribution<> _frand(min_value,max_value);
	for(int i = 0; i<= 99; i++)
	{
    	mass[i] = _frand(_srand);
    	if(mass[100] < mass[i]) mass[100] = mass[i];
    	if(mass[101] > mass[i]) mass[101] = mass[i];
    	mass[102] += mass[i];
    	cout<< "Mass["<<i+1<<"] = "<< mass[i]<<endl;
	}
	cout <<"mass Min = " << mass[101] << endl;
	cout <<"mass Max = " << mass[100] << endl;
	cout <<"mass Arithmetic mean = " << mass[102] << " / 100  = "<< mass[102] /100<< endl<< endl<< endl;

}
int main()
{
    cout << "Hello, team\n";
    char _case = 0;
    while (1)
    {
    	cout << "Input \"1\", for INT_MIN = -2147483648, INT_MAX = 2147483647;\nInput \"2\", for Min = 0, Max = 2147483647;\nInput \"3\", for min = 0, max = 10;\nInput \"0\", for exit\n# ";
    	cin >> _case;
    	if(_case == '0') break;
    	if(_case == '1') GetRandom(-2147483648,2147483647);
    	if(_case == '2') GetRandom(0,2147483647);
    	if(_case == '3') GetRandom(0,10);
    	else continue;
    }
    cout << "\nY.D.O.\n";
    return 0;
}


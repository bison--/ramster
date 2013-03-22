/****************
 *  RAMSTER     *
 *  1.0         *
 *  by bison    *
 *  GPL v2      *
 ****************/

#include<iostream>
#include<string>

// Check windows
#if _WIN32 || _WIN64
	#if _WIN64
		#define ENVIRONMENT 64
	#else
		#define ENVIRONMENT 32
	#endif
#endif

// Check GCC
#if __GNUC__
	#if __x86_64__ || __ppc64__
		#define ENVIRONMENT 64
	#else
		#define ENVIRONMENT 32
	#endif
#endif

using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		int *lock;
		string argTmp = argv[1];

		if (string(argv[1]) == "forever")
		{
			while(true)
			{ lock = new int; }
		}
		else
		{
			int limit = 0;
			int limitInput = atoi(argv[1]);
			bool isMalloc = (argv[2] != NULL && string(argv[2]) == "malloc");

			if (isMalloc)
			{
				limit = (limitInput * 1048576) / sizeof(int);

				lock = (int*)malloc(limit*sizeof(int));
				if (lock == NULL) exit (1);

				for (long long i = 0; i < limit; ++i)
				{ lock[i] = 1; }
			}
			else
			{
				// on 32bit, 16bit overhead
				limit = (limitInput * 1048576) / (ENVIRONMENT / 2);

				for (int i = 0; i < limit; ++i)
				{ lock = new int; }
			}
		}
	}
	else
	{
		cout << "\nRead\n The\n  F***ing\n   Readme\n     :P\n";
	}

	char tmp;
	cout << endl << "Press ENTER to free your ram!";
	cin.get(tmp);
}

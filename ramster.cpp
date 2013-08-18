/****************
 *  RAMSTER     *
 *  1.1         *
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
		size_t *lock;
		string argTmp = argv[1];

		if (string(argv[1]) == "forever")
		{
			while(true)
			{ lock = new size_t; }
		}
		else
		{
			size_t limit = 0;
			size_t limitInput = atoi(argv[1]);
			bool isMalloc = (argv[2] != NULL && string(argv[2]) == "malloc");

			if (isMalloc)
			{
				limit = (limitInput * 1048576) / sizeof(size_t);

				lock = (size_t*)malloc(limit*sizeof(size_t));
				if (lock == NULL) exit (1);

				for (size_t i = 0; i < limit; ++i)
				{ lock[i] = 1; }
			}
			else
			{
				// on 32bit, 16bit overhead
				limit = (limitInput * 1048576) / (ENVIRONMENT / 2);

				for (size_t i = 0; i < limit; ++i)
				{ lock = new size_t; }
			}
		}
	}
	else
	{
		cout << "\n";
		cout << "  q-p\n";
		cout << " /\\\"/\\\n";
		cout << "(`=*=')\n";
		cout << " ^---^`-._\n";
		cout << "\nRead\n The\n  F***ing\n   Readme\n     :P\n";
	}

	char tmp;
	cout << endl << "Press ENTER to free your ram!";
	cin.get(tmp);
}

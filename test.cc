#include <iostream>
#include <string>

using namespace std;

#define PI 3.14159

char a; //8 bits
char16_t b; //16 bits
char32_t c; //32 bits
wchar_t d; //largest char

signed char e; //same as char 8 bits
signed short int f; //16 bits
signed int g; //16 bits
signed long int h; //32 bits
signed long long int i; //64 bits

unsigned char j;
unsigned short int k;
unsigned int l;
unsigned long int m;
unsigned long long int n;

float o;
double p; //precise float
long double q; //precise double

bool r;
decltype(nullptr) t; //decltype gets the type of variable passed to it (ie typeof)
int* ptr = nullptr;

const int gravity = 9.8;
int x = sizeof (char); // >> outputs to following
//8 bits < 256 < (2^8) 1 byte
//16 bits < 65 536 < (2^16) 2 bytes
//32 bits < 4 294 967 296 < (2^32) 4 bytes
//64 bits < 18 446 744 073 709 551 616 < (2^64) 8 bytes

// \n newline
// \r return
// \t tab
// \b backspace
// \a alert
// \f form feed
// LITERALS - \' \'' \? \\

// & AND &&
// | OR ||
// ^ XOR
// ~ NOT !
// << SHL
// >> SHR
// new delete

inline string combine(const string& a, const string& b) {
  return a+b; //when compiled function is inserted directly rather than being looked up via a function call. Frequently used small utility functions are good for this. Most good compilers are clever enough to do this anyway so basically useless.
}

void func() {}; //not storage

int main() {
  a = (b=3,b+2);
  int aa;
  float bb = 3.14;
  aa = (int) bb;
  string test = "Hello \
World!"; //requires #include string
  cout << test << endl;
  cout << "enter something" << endl;
  string _teststr;
  getline (cin, _teststr);
  cout << " - " << _teststr << " - " << endl;
  int _idx = 0;
  for (char _c : _teststr ) { //like in
    cout << " - " << _c << " - " << endl;
    _idx++;
    if (_idx > 10) goto iamathing; //break; would work too while continue; skips to next iteration of loop.
  };
iamathing:
  return 0;
}

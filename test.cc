#include <iostream>
#include <string>

using namespace std;

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

//8 bits < 256 (2^8)
//16 buts < 65 536 (2^16)
//32 buts < 4 294 967 296 (2^32)
//64 buts < 18 446 744 073 709 551 616 (2^64)

// \n newline
// \r return
// \t tab
// \b backspace
// \a alert
// \f form feed
// LITERALS - \' \'' \? \\

int main() {
  a = 1;
  string test = "Hello World!"; //requires #include string
  cout << test << endl;
  return 0;
}

void func() {}; //not storage

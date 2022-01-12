//
// Created by priya on 10-01-2022.
//

#ifndef STRING_STR_H
#define STRING_STR_H
#ifndef _GLIBCXX_IOSTREAM
#include "iostream"
#endif

class str {
private:
    char* s;
public:
    str(char* s=""); // constructor
    explicit operator bool ();
    explicit operator char ();
    explicit operator unsigned char ();
    explicit operator short ();
    explicit operator unsigned short ();
    explicit operator int ();
    explicit operator unsigned int ();
    explicit operator long ();
    explicit operator unsigned long ();
    explicit operator long long ();
    explicit operator unsigned long long ();
    explicit operator float ();
    explicit operator double ();
    operator char* (); // return value of char* s

    
    int len(); // returns string length
    str rev(bool internal); // reverse string
    str operator +(str x); // concatenate  2 string and gives result in another string
    void operator +=(str x); // concatenate string on right side to left side
    void operator <<=(str x); // copys the content of right side to left side
    bool operator ==(str x);
    bool operator ==(char* x);
    str operator ()(int start,int end, int jump); // string slicing
    char operator [](int x);
    int countChar(char c); // count occurrence of c in string
    int firstIndexOf(char c); // returns 1st index of char c in string, if not present returns -1
    int lastIndexOf(char c); // returns last index of char c in string, if not present returns -1
    friend int len(str s);
    friend str rev(str s);
    friend void rev(str* s);
    friend int countChar(str s,char c);
    friend  int firstIndexOf(str s,char c);
    friend int lastIndexOf(str s,char c);
    friend std::istream & operator >>(std::istream &in, str &s);
    friend std::ostream & operator <<(std::ostream &ou, str const&s);
};
str::str(char *s):s{s} {
    this->s = new char [10];
    this->s=s;
}

int str::len() {
    int c=0;
    for(;*(s+c)!='\0';c++);
    return c;
}

int len(str s) {
    int c=0;
    for(;*(s+c)!='\0';c++);
    return c;
}

str str::operator+(str x) {
    str op = new char[::len(s)+x.len()+1];
    int i=0,j=0;
    for(;j<::len(s);j++){
        *(op+i)=*(s+j);
        i++;
    }
    for(j=0;j<x.len();j++){
        *(op+i)=*(x+j);
        i++;
    }
    *(op+i)='\0';
    return op;
}

void str::operator+=(str x) {
    str op = new char[::len(s)+x.len()+1];
    int i=0,j=0;
    for(;j<::len(s);j++){
        *(op+i)=*(s+j);
        i++;
    }
    for(j=0;j<x.len();j++){
        *(op+i)=*(x+j);
        i++;
    }
    *(op+i)='\0';
    s=op;
}

void str::operator<<=(str x) {
    str op = new char [x.len()];
    int i=0;
    for(i=0;i<x.len();i++){
        *(op+i)=*(x+i);
    }
    *(op+i)='\0';
    s=op;
}

str str::rev(bool internal= false) {
    str op = new char[::len(s)];
    int j = 0;
    for (int i = ::len(s) - 1; i >= 0; i--, j++) {
        *(op + j) = *(s + i);
    }
    *(op + j) = '\0';
    if(internal) {
       s=op;
    }
    return op;
}


str rev(str s) {
    str op = new char[::len(s)];
    int j = 0;
    for (int i = ::len(s) - 1; i >= 0; i--, j++) {
        *(op + j) = *(s + i);
    }
    *(op + j) = '\0';
    return op;
}

void rev(str *s) {
    str op = new char[::len(*s)];
    int j = 0;
    for (int i = ::len(*s) - 1; i >= 0; i--, j++) {
        *(op + j) = *(*s + i);
    }
    *(op + j) = '\0';
    *s = op;
}

str str::operator()(int start, int end, int jump=1) {
    str op= new char [((end-start+1)/jump)+1];
    int i,j=0;
    if(start<=end) {
        for (i = start; i <= end; i += jump) {
            *(op + j) = *(s + i);
            j++;
        }
    } else{
        for (i = start; i >= end; i += jump) {
            *(op + j) = *(s + i);
            j++;
        }
    }
    *(op+j)='\0';
    return op;
}

int str::countChar(char c) {
   int count=0;
   for(int i=0;i<::len(s);i++)
       count = *(s+i)==c ? count+1 : count+0;
    return count;
}

int countChar(str s, char c) {
    int count=0;
    for(int i=0;i<::len(s);i++)
        count = *(s+i)==c ? count+1 : count+0;
    return count;
}

int str::firstIndexOf(char c) {
    int index=-1;
    for(int i=0;i<::len(s);i++){
        if(*(s+i)==c){
            index = i;
            break;
        }
    }
    return index;
}

int str::lastIndexOf(char c) {
    int index=-1;
    for(int i=0;i<::len(s);i++)
        index = *(s+i)==c ? i : index;
    return index;
}

int firstIndexOf(str s, char c) {
    int index=-1;
    for(int i=0;i<::len(s);i++){
        if(*(s+i)==c){
            index = i;
            break;
        }
    }
    return index;
}

int lastIndexOf(str s, char c) {
    int index=-1;
    for(int i=0;i<::len(s);i++)
        index = *(s+i)==c ? i : index;
    return index;
}





char str::operator[](int x) {
    if(x<-1*::len(s) || x>::len(s)-1){
        //throw std::out_of_range("Index our of Range\n");
    }
    if(x>=0){
        return *(s+x);
    }
    else{
        return *(s+::len(s)+x);
    }
}

bool str::operator==(str x) {
    for(int i=0;i<::len(s);i++){
        if(*(s+i)!=*(x+i))
            return false;
    }
    return true;
}

bool str::operator==(char *x) {
    for(int i=0;i<::len(s);i++){
        if(*(s+i)!=*(x+i))
            return false;
    }
    return true;
}

str::operator bool() {
    if(s=="YES" || s=="yes" || s=="Yes" ||s=="true" || s=="TRUE" || s=="True" || s=="1")
        return true;
    else if(s=="NO" || s=="no" || s=="No" || s=="false" || s=="FALSE" || s=="False" || s=="0")
        return false;
    else throw std::invalid_argument("Cannot cast from str to bool");
}

str::operator char(){
    if(::len(s)!=1){
       throw std::invalid_argument("Cannot Cast String Literal to Char Type");
    }
    else{
        return *s;
    }
}


str::operator unsigned char(){
    if(::len(s)!=1){
        throw std::invalid_argument("Cannot Cast String Literal to Char Type");
    }
    else{
        return (unsigned char)*s;
    }
}

str::operator short() {
    short n=0,sign_factor = *(s)=='-' ? -1 : 1;
    int i= sign_factor == -1 || *s=='+' ? 1 : 0;
    for(;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(short)n*10L+(*(s+i)-'0');
        }
        else {
           throw std::invalid_argument("Cannot Cast non-numeric str to short type");
        }
    }
    return sign_factor*n;
}

str::operator unsigned short() {
    unsigned short n=0;
    int i = *s=='+' ? 1 : 0;
    for(;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(unsigned short)n*10L+(*(s+i)-'0');
        }
        else {
            throw std::invalid_argument("Cannot Cast non-numeric str or negative number to unsigned short type");
        }
    }
    return n;
}

str::operator int() {
    int n=0,sign_factor = *(s)=='-' ? -1 : 1;
    int i= sign_factor == -1 || *s=='+' ? 1 : 0;
    for(;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=n*10L+(*(s+i)-'0');
        }
        else {
           throw std::invalid_argument("Cannot Cast non-numeric str to int type");
        }
    }
    return sign_factor*n;
}

str::operator unsigned int() {
    unsigned int n=0;
    int i = *s=='+' ? 1 : 0;
    for(;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(unsigned int )n*10L+(*(s+i)-'0');
        }
        else {
           throw  std::invalid_argument("Cannot Cast non-numeric str or negative number to unsigned int type");
        }
    }
    return n;
}


str::operator long() {
    long n=0L,sign_factor = *(s)=='-' ? -1 : 1;
    int i= sign_factor == -1 || *s=='+' ? 1 : 0;
    for(int i=0;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(long)n*10L+(*(s+i)-'0');
        }
        else {
            throw std::invalid_argument("Cannot Cast non-numeric str to long type");
        }
    }
    return sign_factor*n;
}

str::operator unsigned long() {
    unsigned long n=0L;
    int i= *s=='+' ? 1 : 0;
    for(;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(unsigned long)n*10L+(*(s+i)-'0');
        }
        else {
            throw std::invalid_argument("Cannot Cast non-numeric str or negative number to unsigned long type");
        }
    }
    return n;
}

str::operator long long() {
    long long n=0L,sign_factor = *(s)=='-' ? -1 : 1;
    int i= sign_factor == -1 || *s=='+' ? 1 : 0;
    for(int i=0;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(long long)n*10LL+(*(s+i)-'0');
        }
        else {
           throw std::invalid_argument("Cannot Cast non-numeric str to long long type");
        }
    }
    return sign_factor*n;
}

str::operator unsigned long long() {
    unsigned long long n=0LL;
    int i= *s=='+' ? 1 : 0;
    for(int i=0;i<::len(s);i++){
        if(*(s+i)>='0' && *(s+i)<='9'){
            n=(unsigned long long)n*10LL+(*(s+i)-'0');
        }
        else {
           throw std::invalid_argument("Cannot Cast non-numeric str or negative number to unsigned long long type");
        }
    }
    return n;
}

str::operator float() {
    float rez = 0, fact = 1;
    int point_seen=0,i;
    if (*s == '-'){
        fact = -1;
    };
    i = *s == '-' || *s == '+' ? 1 : 0;
    for (; i<::len(s); i++){
        if (*(s+i) == '.'){
            point_seen = 1;
            continue;
        }
        int d = *(s+i) - '0';
        if (d >= 0 && d <= 9){
            if (point_seen) fact /= 10.0f;
            rez = rez * 10.0f + (float)d;
        } else{
            throw std::invalid_argument("Cannot Cast Non numeric str type to float type");
        }
    }
    return rez * fact;
}

str::operator double() {
    double rez = 0, fact = 1;
    int point_seen=0,i;
    if (*s == '-'){
        fact = -1;
    };
    i = *s == '-' || *s == '+' ? 1 : 0;
    for (; i<::len(s); i++){
        if (*(s+i) == '.'){
            point_seen = 1;
            continue;
        }
        int d = *(s+i) - '0';
        if (d >= 0 && d <= 9){
            if (point_seen) fact /= 10.0;
            rez = rez * 10.0 + (double )d;
        } else{
            throw std::invalid_argument("Cannot Cast Non numeric str type to double type");
        }
    }
    return rez * fact;
}

std::ostream &operator<<(std::ostream &ou, str const&s) {
    ou << s.s<<std::endl;
    return ou;
}

std::istream &operator>>(std::istream &in, str &x) {
    in >> *(x.s);
    return in;
}


str::operator char *() {
    return s;
}

#endif //STRING_STR_H

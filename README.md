
---
## How To Use The Header in  Project

```
#include "str"
```
---

## Examples

### Creating a string
```
str s01 = "Hello World 01";
str s02("Hello World 02);
```
### Input String
```
std::cin>>s01;
std::cin>>s02;
```
### Output string
```
std::cout<<s01;
std::cout<<s02;
```
### Calculate String Length
```
str s = "Hello World";
int len1 = s.len();
int len2 = len(s);
```
### Concatenation of 2 String (Without Modification of input string)
```
str s1 = "Hello ";
str s2 = "World";
str s3 = " Nice to see You";
str s4 = s1 + s2 + s3 + s4 + " Thankyou";
std::cout<<s4;
```
Output :
> Hello World Nice to see You Thankyou

### Concatenation of 2 String (With Modification of input [Left]string)
```
str a = "Hello ";
str b = "World";

std::cout<<"Before Concatenation"<<std::endl;
std::cout<<a<<std::endl<<b<<std::endl;

a+=b; /// Concatenation of 2 String (With Modification of input [Left]string)

std::cout<<"After Concatenation"<<std::endl;
std::cout<<a<<std::endl<<b<<std::endl;
```
Output :
```
 Before Concatenation
 Hello 
 World
 After Concatenation
 Hello World
 World
 
```

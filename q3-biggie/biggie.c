///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 
 
// ERROR_NO_INTEGRITY_STATEMENT 
//  
// Name: ERROR_NO_NAME 
// login ID: ERROR_NO_LOGIN 
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include "biggie.h"

/////////////////////////////////////////////////////////////////////////////
// DO NOT CHANGE THIS STRUCTURE
/////////////////////////////////////////////////////////////////////////////
struct biggie {
  bool negative;
  char *digits;
};
// notes: digits is a properly null-terminated dynamic string
//        digits contains the number reversed, so 1203 => "3021"
//        digits cannot have leading zeros, so 1203 cannot be "30210"
//        zero is stored as "0" and cannot be negative (negative is false)
/////////////////////////////////////////////////////////////////////////////

struct biggie *biggie_create(const char *s) {
  struct biggie *big = malloc(sizeof(struct biggie));
  int len = strlen(s);
  if(s[0] == '-' && s[1] == '0'){
    return NULL;
  }
  if(len == 0){
    return NULL;
  }
  if(s[0] == '0' && len != 1){
    return NULL;
  }
  if(s[0] == '-'){
    big->negative = true;
  }else{
    big->negative = false;
  }
  big->digits = malloc((len + 1) * sizeof(char));
  int i = len - 1;
  int j = 0;
  while(i>=0 &&  s[i] >= 48 && s[i]<= 57){
    big->digits[j] = s[i];
    j++;
    i--;
  }
  if(i == 0 && s[i] != '-'){
    return NULL;
  }else if(i !=0 || i != -1){
    return NULL;
  }else {
  }
  big->digits[j] = '\0';// maybe
  return big;
//WHAT I DID..........IT MIGHT NOT BE CORRECT BUT YAAAAAAAAAA!!
}

void biggie_destroy(struct biggie *big) {
}

void biggie_print(const struct biggie *big, bool newline) {
}

void biggie_add(struct biggie *n, const struct biggie *m) {
}

void biggie_sub(struct biggie *n, const struct biggie *m) {
}

void biggie_mult(struct biggie *n, const struct biggie *m) {
}

bool biggie_eq(const struct biggie *n, const struct biggie *m) {
  return false; // dummy value
}

bool biggie_gt(const struct biggie *n, const struct biggie *m) {
  return true; // dummy value
}

struct biggie *biggie_copy(const struct biggie *n) {
  return NULL; // dummy value
}

/////////////////////////////////////////////////////////////////////////////
// BONUS:
/////////////////////////////////////////////////////////////////////////////

void biggie_div(struct biggie *n, const struct biggie *m) {
}

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
  return NULL; // dummy value
}

void biggie_destroy(struct biggie *big) {
}

void biggie_print(const struct biggie *big, bool newline) {
}

void biggie_add(struct biggie *n, const struct biggie *m) {
 int lenn = strlen(n->digits);
  int lenm = strlen(m->digits);
  int max_length = lenn > lenm ? lenn : lenm;
  int carry = 0;
  int sum = 0;
  int digit;
  int borrow = 0;
  int calc = 0;
  int subfrom = 0;
  if(n->negative == false && m->negative == true){
    for (int i = 0; i<max_length; i++){
      int sub1 = n->digits[i] - '0';
      int sub2 = m->digits[i] - '0';
      subfrom = sub1 - borrow;
      calc = subfrom - sub2;
      if(calc < 0){
        subfrom = 10 + subfrom;
        calc = subfrom - sub2;
        borrow = 1;
      }
      n->digits[i] =calc + '0';


    }
  }

  else if(n->negative == true && m->negative == false){
    n->negative = false;
    biggie_sub(n, m);
    n->negative = true;

  }else{
    if (max_length > lenn) n->digits = realloc(n->digits, max_length * sizeof(char *));

    for ( int i = 0 ; i < max_length ; i++) {
      if ( lenn >= i && lenm >= i)
        sum = (n->digits[i] - '0') + (m->digits[i] - '0');
      else if (lenm >= i) 
        sum = m->digits[i] - '0';
      else
        sum = n->digits[i] - '0';
      sum = sum + carry;
      digit = sum % 10;
      carry = ( sum - carry ) / 10;
      n->digits[i] = digit + '0';
    }

    if (carry > 0) {
      n->digits[max_length] = carry + '0';
      n->digits= realloc(n->digits, (max_length + 2) * sizeof(char));
      n->digits[max_length] = '1';
      n->digits[max_length + 1] = '\0';
    }

  }
}
}

void biggie_sub(struct biggie *n, const struct biggie *m) {
 void biggie_sub(struct biggie *n, const struct biggie *m) {
  int len1= strlen(n->digits);
  int len2= strlen(m->digits);
  int max_length = max(len1, len2);
  int sub1 = 0;
  int sub2 = 0;
  int subfrom = 0;
  int borrow = 0;
  int calc = 0;
  if(n->negative == true && m->negative == false){
    n->negative = false;
    biggie_add(n, m);
   n->negative = true;
    
  }else if(n->negative == false && m->negative == true){
    struct biggie *big;
    big = biggie_copy(m);
    big->negative = false;
    
    biggie_add(n , big);
  }

  for (int i = 0; i<max_length; i++){
    sub1 = n->digits[i] - '0';
    sub2 = m->digits[i] - '0';
    subfrom = sub1 - borrow;
    calc = subfrom - sub2;
    if(calc < 0){
      subfrom = 10 + subfrom;
      calc = subfrom - sub2;
      borrow = 1;
    }
    n->digits[i] =calc + '0';


  }
}
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

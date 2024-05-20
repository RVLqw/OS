#include "fibb.h" // < >  /usr/include

int fibb(int n){
  if (n<=1){
    return n;
  } else {
    return fibb(n-1)+fibb(n-2);
  }
}

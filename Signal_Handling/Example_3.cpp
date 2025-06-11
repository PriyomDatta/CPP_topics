#include <iostream>
#include <csignal>
#include <unistd.h>  /*For sleep */

using namespace std;

void signalHandler( int signum ) {
   switch(signum){
      case SIGILL: cout << "Caught SIGILL: Erroneous arithmetic operation (e.g., divide by zero)!" << endl;
                     break;
      case SIGINT : cout << "Caught SIGINT: interrupt signal" << endl; 
                     break;
      default : cout << "Some other thing happened";
   }
   // cleanup and close up stuff here  
   // terminate program
   exit(EXIT_FAILURE);
}

int main () {
   int i = 0;
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);
   signal(SIGILL, signalHandler);

   while(++i) {
      cout << "Going to sleep...." << endl;
      if( i == 10 ) {
         raise( SIGINT);   //Will not work use ctrl+c to create interrupt
      }
      else if(i==5){
         cout << "Triggering illegal instruction..." << endl;
         __asm__ __volatile__ (".byte 0x0F, 0x0B");  // UD2 instruction: guaranteed to cause SIGILL
         /*Such errors are hard to create as they are related to instruction sets avilable with the mechine*/
      }
      sleep(1);
   }

   return 0;
}
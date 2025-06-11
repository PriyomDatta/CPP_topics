#include <iostream>
#include <csignal>
#include <unistd.h>  /*For sleep */

using namespace std;

void signalHandler( int signum ) {
   switch(signum){
      case SIGABRT: cout << "Caught SIGABRT: Abnormal termination !!!" << endl;
                     break;
      case SIGINT : cout << "Caught SIGINT: interrupt signal !!!" << endl; 
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
   signal(SIGABRT, signalHandler);

   while(++i) {
      cout << "Going to sleep...." << endl;
      if( i == 10 ) {
         raise( SIGINT);   //Will not work use ctrl+c to create interrupt
      }
      else if(i==5){
        cout << "Program will abort using abort function()..." << endl;
        abort();
      }
      sleep(1);
   }

   return 0;
}
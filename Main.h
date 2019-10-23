#ifndef _main_h_
#define _main_h_

#include "API.h"
#include "UserInclude.h"


extern int PD0 ;
extern int PD1 ;
extern int PD2 ;
extern int PD3 ;
extern int PD4 ;
extern int PD5 ;
extern int PD6 ;
extern int PD7 ;
extern int PD_sum ;
extern int max_val ;
extern int max_no ;
extern int freq ;
extern int ambient_level ;
extern int slow_level ;
extern int stop_level ;
extern int expose_time ;
extern int steer_sensitivity ;
extern int forward_speed ;
extern int slow_speed ;
extern int spin_speed ;

void Read_PD ( void ) ;
int expose_and_read ( void ) ;
void find_max ( void ) ;
int limit_pwm ( int temp ) ;
void move ( void ) ;

#endif // _main_h_


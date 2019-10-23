#include "Main.h"

void main ( void )
{
      char CloudLimit = 0; 
      int LimitSwitch = 0; 
      unsigned int Dist = 0; 
      int i; 
      int MaxDist = 0; 
      int CurrentDist; 
      int LeftBumper; 
      int RightBumper; 
      int BackBumper; 

      freq=0; // 0=1khz (red), 1=10kHz(green beacon)
      ambient_level = 60; // esed in 'move'
      slow_level = 5000; // used in 'move'
      stop_level = 6000; // used in 'move'
      expose_time = 3; // used in expose_and_read
      steer_sensitivity = 20; // used in 'move'
      forward_speed = 80; // forward speed, used in 'move'
      slow_speed = 50; // slow speed, used in 'move'
      spin_speed = 75; // spin speed (for searching mode), used in 'move'
      SetDigitalOutput ( 10 , freq ) ; // turn to 1kHz (red beacon)
      //SetServo ( 9 , -127 ) ;
      //Wait ( 2000 ) ;
      SetServo ( 9 , 127 ) ;
      StartUltrasonic ( 3 , 5 ) ;
      PrintToScreen ( "ready\n" ) ;
      //Wait ( 3000 ) ;
      //PrintToScreen ( "Go\n" ) ;
      //Wait ( 5000 ) ;
      while ( 1==1 )
      {
            Read_PD (   ) ;
            find_max ( ) ;
            move ( ) ;
            CloudLimit = GetDigitalInput ( 1 ) ;
            //PrintToScreen ( "%d\n" , Dist ) ;
            PrintToScreen ( "%d\n" , PD_sum ) ;
            if ( CloudLimit == 0 && freq == 0 )
            {
                  Wait ( 1000 ) ;
                  SetMotor ( 2 , 0 ) ;
                  SetMotor ( 3 , 0 ) ;
                  Wait ( 1000 ) ;
                  SetServo ( 9 , -127 ) ;
                  Wait ( 2000 ) ;
                  SetServo ( 9 , 127 ) ;
                  LimitSwitch = 1;
                  Wait ( 500 ) ;
                  Wait ( 1000 ) ;
                  //SetMotor ( 2 , 127 ) ;
                  //SetMotor ( 3 , -127 ) ;
                  Wait ( 1000 ) ;
                  SetMotor ( 2 , 0 ) ;
                  SetMotor ( 3 , 0 ) ;
            }
            if ( LimitSwitch == 1 && PD_sum <= 100 )
            {
                  freq=1; // 0=1khz (red), 1=10kHz(green beacon)
                  SetDigitalOutput ( 10 , freq ) ; // turn to 10kHz (green beacon)
                  spin_speed = 35; // spin speed (for searching mode), used in 'move'
            }
            LeftBumper = GetDigitalInput ( 2 ) ;
            RightBumper = GetDigitalInput ( 3 ) ;
            BackBumper = GetDigitalInput ( 4 ) ;
            if ( LeftBumper == 0 )
            {
                  //SetMotor ( 2 , 50 ) ;
                  //SetMotor ( 3 , -127 ) ;
                  //Wait ( 1000 ) ;
            }
            if ( RightBumper == 0 )
            {
                  //SetMotor ( 2 , 127 ) ;
                  //SetMotor ( 3 , -50 ) ;
                  //Wait ( 1000 ) ;
            }
            if ( BackBumper == 0 )
            {
                  //SetMotor ( 2 , 50 ) ;
                  //SetMotor ( 3 , -50 ) ;
                  //Wait ( 1000 ) ;
            }
            if ( freq ==1 && PD_sum > 65 && CloudLimit ==0 )
            {
                  Wait ( 1000 ) ;
                  SetMotor ( 2 , 0 ) ;
                  SetMotor ( 3 , 0 ) ;
                  Wait ( 1000 ) ;
                  SetServo ( 9 , -127 ) ; // // Claw green beacon
                  Wait ( 1000 ) ;
                  break ;
            }
      }
      while ( 1 == 1 )
      {
            SetMotor ( 2 , -127 ) ;
            SetMotor ( 3 , 127 ) ;
            LeftBumper = GetDigitalInput ( 2 ) ;
            RightBumper = GetDigitalInput ( 3 ) ;
            BackBumper = GetDigitalInput ( 4 ) ;
            if ( LeftBumper == 0 )
            {
                  SetMotor ( 2 , 50 ) ;
                  SetMotor ( 3 , -127 ) ;
                  Wait ( 1000 ) ;
                  while ( 1==1 )
                  {
                        BackBumper = GetDigitalInput ( 4 ) ;
                        if ( BackBumper == 0 )
                        {
                              SetMotor ( 2 , 0 ) ;
                              SetMotor ( 3 , 0 ) ;
                              Wait ( 1000 ) ;
                              break ;
                        }
                  }
            }
            if ( RightBumper == 0 )
            {
                  SetMotor ( 2 , 127 ) ;
                  SetMotor ( 3 , -50 ) ;
                  Wait ( 1000 ) ;
                  while ( 1==1 )
                  {
                        BackBumper = GetDigitalInput ( 4 ) ;
                        if ( BackBumper == 0 )
                        {
                              SetMotor ( 2 , 0 ) ;
                              SetMotor ( 3 , 0 ) ;
                              Wait ( 1000 ) ;
                              break ;
                        }
                  }
            }
            if ( BackBumper == 0 )
            {
                  SetMotor ( 2 , -50 ) ;
                  SetMotor ( 3 , 50 ) ;
                  Wait ( 1000 ) ;
            }
      }
}

#include <Servo.h>                        
 
int right = 3;
int left = 5;
int footr = 6;
int footl = 9;
Servo r;
Servo l;
Servo fr;
Servo fl; 
int x = 1; 

// Setup function
void setup() {                                
  fr.attach(footr); //attach the servoes to specified arduino pins                 
  l.attach(left);
  r.attach(right);
  fl.attach(footl);
}

void loop() {                                    
  r.write(90); //set to initial position (all servoes at 90 degrees                                     
  l.write(90);                                                  
  fr.write(90);                                       
  fl.write(90);  

  while (x==1){ //always true => infinite loop => robot is always in continuous motion
  
    r.write (60);
    delay(200);
    fr.write (150);
    delay(200);
    r.write (90);
    delay(200);
    fr.write (30);
    delay(200);

    l.write (120);
    delay(200);
    fl.write (30);
    delay(200);
    l.write (90);
    delay(200);
    fl.write (150);
    delay(200);
}

                             
                    
  


}

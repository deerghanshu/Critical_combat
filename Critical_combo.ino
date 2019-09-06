
//Project::Critical Combat

//Define the pins and fingers
int pin0=A0;//finger 4
int pin1=A1;//finger 2
int pin2=A2;//finger 3
int pin3=A3;//finger 5
int pin4=A4;//finger 1


int wait=10;

int load=0;

int loop_rank=0;

void setup() {
  Serial.begin(38400);
}//main setup

float flex1_train=0.0;//wait 25 seconds to train the data set
float flex2_train=0.0;
float flex3_train=0.0;
float flex4_train=0.0;
float flex5_train=0.0;



void loop() {//.............................................................................................


  
  if(loop_rank==wait){
    Serial.println("Reloading the commands........ !!");
    Serial.println("You can now give commands!!");
  }//..........................................................AT 30SECS

 

//scan the flex sensors
float flex1=analogRead(pin4);//thumb
float flex2=analogRead(pin1);//point finger
float flex3=analogRead(pin2);//middle finger
float flex4=analogRead(pin0);//ring finger
float flex5=analogRead(pin3);//little finger

//scaling the voltages
flex1=(flex1*5/1032)*100+50.0;
flex2=(flex2*5/1032)*100+40.0;
flex3=(flex3*5/1032)*100+30.0;
flex4=(flex4*5/1032)*100+20.0;
flex5=(flex5*5/1032)*100+10.0;

 //correction for finger 2
  

  if(loop_rank<wait){//..............................................LESS THAN 30  SECONDS
    Serial.println("Wait commands loading.....");
    flex1_train=flex1;
    flex2_train=flex2;
    flex3_train=flex3;
    flex4_train=flex4;
    flex5_train=flex5;
  }//train the data set at first//................................

if(loop_rank>wait){
//Printing the Plots

/*
Serial.print(flex1);
Serial.print(" ");
Serial.print(flex2);
Serial.print(" ");
Serial.print(flex3);
Serial.print(" ");
Serial.print(flex4);
Serial.print(" ");
Serial.println(flex5);*/



//TESTING THE NEW DATA *****************************************************
      float f1_dev=flex1_train-flex1;
      float f2_dev=flex2_train-flex2;
      float f3_dev=flex3_train-flex3;
      float f4_dev=flex4_train-flex4;
      float f5_dev=flex5_train-flex5;//calculate the mean deviation
     //AFFIRMATIVE!!

     
    
     if(f1_dev >= 5 && f2_dev >=6 && f3_dev >= 9 && f4_dev >=7 && f5_dev>=8)//......................................SNIPER AHEAD
     {
      
      Serial.println("SNIPER AHEAD!!");
      //Reload the data set
      loop_rank=0;
     }
     else if(f1_dev >= 8.0 && f2_dev >= 6.0 && f3_dev <= 8.0 && f4_dev <=4.0 && f5_dev<=5){//...............................AFFIRMATIVE
     
     Serial.println("AFFIRMATIVE!!");
     //Reload the dataset.
     loop_rank=0;
     }
     else if(f1_dev <=10 && f2_dev <= 4 && f3_dev <= 4 && f4_dev >=15  && f5_dev >=12 ){//.............................STORM THE FRONT
    
     Serial.println("STORM THE FRONT!!");
     //Reload the dataset.
     loop_rank=0;
     }
     else if(f1_dev >= 15 && f2_dev <=5 && f3_dev <= 4 && f4_dev >=15 && f5_dev >=6 ){//.....................................AREA CLEAR
     Serial.println("AREA CLEAR!!");
     loop_rank=0;
     }

     else if(f2_dev >= 25){
      loop_rank=-5;
     }

     else{// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Purge the noisy waves..
      float dist_1=flex1_train-flex1;
      float dist_2=flex2_train-flex2;
      float dist_3=flex3_train-flex3;
      float dist_4=flex4_train-flex4;
      float dist_5=flex5_train-flex5;

        /*if(abs(dist_1) > 4.0 || abs(dist_2) > 4.0 || abs(dist_3) > 4.0 || abs(dist_4) > 4.0||abs(dist_5) > 4.0){
        //Reload the dataset
        purge=purge+1;
        if(purge > 5){
        purge=0;
        Serial.println("Wrong signals!!");
        loop_rank=3;
        }
      }*/
      
     }

//TESTING THE NEW DATA *****************************************************
}//............................GREATER THAN 30  SECONDS
loop_rank=loop_rank+1;
load=load+1;
if(load%3==0)
Serial.println("...");
if(load%3==1)
Serial.println(".....");
if(load%3==2)
Serial.println(".......");
delay(1000);//delay of 1 seconds in the loop
}

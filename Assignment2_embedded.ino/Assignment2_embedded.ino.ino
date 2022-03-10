//stting up the pins for the buttons and LED's
const int ledRed =21;
const int ledGreen = 15;
const int leftButt =22;
const int rightButt =23;
//setting the pins for the inputted signals for tasks 3 and 4
int task3Signal=2;
int task4Signal=0;
//initialising and setting temporary values to various variables used in the code
int pulseState =0;
long frequency=0;
int freq=0;
long input4 = 0;
int avAnalog=0;
int error_code=2;
int error=2;
int T=0;
int buttonState=0;
int i=0;
int task5Array[]={0,0,0,0};
int t4Signal=0;
const int testPin=4;

//adding the ticker library
#include <Ticker.h>
#include <stdio.h>

//initialising the cyclic exectutive method
void cycle();

//creating the ticker object used for the cyclic exectutive
Ticker ticker;
//this counter is used to recall how many cycles have passed
int counter=0;


void setup() { 
  Serial.begin(9600);
  delay(100);
  //setting up the pins for the LEDs, buttons and input signals as either inputs or outputs
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(leftButt,INPUT);
  pinMode(rightButt,INPUT);
  pinMode(task3Signal, INPUT); 
  pinMode(task4Signal,INPUT);
  pinMode(testPin,OUTPUT);
  //setting the ticker that was created before, set it to call the cycle method every 2ms
  ticker.attach_ms(4,cycle);
}

//this method is the cyclic exectutive, it calls all of the task methods which are later in the code.
//it calls all of the tasks at thier specified rate, which is done by taking the modulus of the
//counter and a number and that tasks number. This number is calculated using the rate in the
//assignment specification.
void cycle(){
  //incrementing the counter by one everytime the method is called
  counter++;
  test1();

  //this task is run every 100 ticks of the ticker. Since the ticker ticks every 2ms this means
  //this method is called every 200ms, which gives it a rate of 5Hz which is this tasks
  //specified rate
  if (counter %25 == 0){
    //buttonState=test2();
  }
  if (counter %125 ==0){
    digitalWrite(ledGreen,HIGH);
    freq=test3();
    digitalWrite(ledGreen,LOW);
  }
  if (counter %5 ==0){
    //t4Signal=test4();
  }
  //this task takes in the signal data that task 4 returned and it calcultes the average signal data
  //then returns that data for other tasks to use.
  if (counter %5 ==1){
    //avAnalog=test5(t4Signal);
  }
  if (counter %13 ==0){
    test6();
  }
  if (counter %42 ==0){
    //error=test7(avAnalog);
  }
  if (counter %42 ==1){
    //test8(error);
  }
  if (counter %625 ==0){
    //test9(buttonState,freq,avAnalog);
  }
}

//this task turns the red LED off and on every tick for 50 micro seconds
void test1(){
  digitalWrite(ledRed,HIGH);
  delayMicroseconds(50);
  digitalWrite(ledRed,LOW);
}
//checks whether the button is being pressed and returns either a 1 or a 0 for each state
int test2(){
  
  pulseState=digitalRead(leftButt);
  if(pulseState==HIGH){
    Serial.println("task 2 button is being pressed");
    return 1;
  }
  else{
    Serial.println("task 2 button is not being pressed");
    return 0;
  }
 
}
//calcultes the frequency of the inputted signal. It measures the signal peroid witht eh pulseIn() function
int test3(){
  T=pulseIn(task3Signal,LOW);
  frequency=1/(2*(T*pow(10,-6)));
  //Serial.println(frequency);
  return frequency;
}
//takes in the signal and returns the voltage data
int test4(){
  input4 = analogRead(task4Signal);
  //Serial.println(input4);
  return input4;
}
//takes in the voltage signal data from task4, with this data it adds it a four element array while
//rewriting the oldest data entry. It then calculates the average of all of the elements in the array
int test5(int t4Input){
  task5Array[counter%4]=t4Input;
  int average=0;
  for (int j=0;j<=4;j++){
    average=average+task5Array[j];
  return average;
  }
  average=average/4;
  //Serial.println(average);
  
  
}
//calls __asm__ __volatile__ ("nop") 1000 times every time this method is called.
void test6(){
  for( int i =0; i<1000;i++){
    __asm__ __volatile__ ("nop");
  }
}
//takes the data returned by task 5 and checks whether it is greater than half of the maximum range for
//an analog input, this task will output a either a 1 or a 0 depening on the outcome.
int test7(int avAnalIn){
  if(avAnalIn > 4095/2){
    error_code=1;
  }
  else{
    error_code=0;
  }
  return error_code;
  //Serial.println(error_code);
  //Serial.println(avAnalIn);
  
}
//turns on the green LED depending on the outcome of task 7 
void test8(int error){
  //Serial.println(error);
  if (error==1){
    digitalWrite(ledGreen,HIGH);
  }
  else{
    digitalWrite(ledGreen,LOW);
  }
}
//this code will print the results of tasks 2, 3, 5 in the for of a csv file into the serial monitor 
void test9(int buttonState, int freq, int average){
  Serial.print(buttonState);
  Serial.print(", ");
  Serial.print(freq);
  Serial.print(", ");
  Serial.println(average);
} 
//}
void loop() {
}

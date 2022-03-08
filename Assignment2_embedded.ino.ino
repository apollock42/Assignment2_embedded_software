const int ledRed =21;
const int ledGreen = 15;
const int leftButt =22;
const int rightButt =23;
int pulseState =0;
int task3Signal=2;
int task4Signal=0;
long frequency=0;
long input4 = 0;
int *task4Data;
int test=0;
int T=0;
//#include <Ticker.h>
#include <stdio.h>
int i=0;
int task5Array[]={0,0,0,0};

void cycle();
//Ticker ticker;
int counter=0;
//void test1();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(leftButt,INPUT);
  pinMode(rightButt,INPUT);
  pinMode(task3Signal, INPUT); 
  pinMode(task4Signal,INPUT);
//  ticker.attach_ms(2,cycle);
}
void cycle(){
  counter++;
  // 24 120 5 5 12 40 40 600
  test1();
  if (counter %100 == 0){
    //test2();
  }
  if (counter %500 ==0){
    //test3();
  }
  if (counter %21 ==0){
    int t4Signal=test4();
    task4Data=&t4Signal;
  }
  if (counter %21 ==1){
    test5(*task4Data);
  }
  if (counter %50 ==0){
    //test6();
  }
  if (counter %167 ==0){
    //test7();
  }
  if (counter %167 ==1){
    //test8();
  }
  if (counter %2500 ==0){
    //test9();
  }
}

void test1(){
  digitalWrite(ledRed,HIGH);
  delayMicroseconds(50);
  digitalWrite(ledRed,LOW);
}
void test2(){
  pulseState=digitalRead(leftButt);
  if(pulseState==HIGH){
    Serial.println("task 2 button is being pressed");
  }
  else{
    Serial.println("task 2 button is not being pressed");
  }
}
void test3(){
  T=pulseIn(task3Signal,LOW);
  frequency=1/(2*(T*pow(10,-6)));
  Serial.println(frequency);
}
int test4(){
  input4 = analogRead(task4Signal);
  Serial.println(input4);
  return input4;
}
void test5(int t4Input){
  task5Array[i]=t4Input;
  int average=0;
  for (int j=0;j<=4;j++){
    average=average+task5Array[j];
  }
  average=average/4;
  Serial.println(average);
  if (i==3){
    i=0;
  }
  else{
  i++;
  //utdyrdyrddy  
  }
  
}
void test6(){
  for( int i =0; i<1000;i++){
    __asm__ __volatile__ ("nop");
  }
}
void test7(){
  Serial.println("c");
}
void test8(){
  Serial.println("c");
}
void test9(){
  Serial.println("c");
} 
//}
void loop() {
}

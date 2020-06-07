#include <SPI.h>
#include <MFRC522.h>
#include<SoftwareSerial.h>
SoftwareSerial firstSerial(22,24);//RX/TX
//#include <GSMSim.h>
//#define RX 
//#define TX 
#define SS_PIN 10
#define RST_PIN 9

#define r 170    //   1__,2__,3__    

#include<LiquidCrystal.h>
int odonil= 67;   //           1__
int kyring =10;  //  10/-      0__   
int pen=50;     //             2__

//GSMSim gsm;
MFRC522 mfrc522(SS_PIN, RST_PIN);

const int rs = 7, en = 5, d4 = 6, d5 = 2, d6 = 3, d7 = 4;
LiquidCrystal lcd(7, 5, 6, 2, 3, 4);
int state=0,ky=0,od=0,pe=0;
int stat=0,a[3],i,T=0,b,ba[3],c,A=0,pi=1,ci=1,mi=1;
void setup() {
 // noTone(8);
 firstSerial.begin(38400);
  Serial.begin(38400);   
  lcd.begin(20, 4);
  lcd.setCursor(3, 0);
  lcd.print("SMART Billing");
 delay(1000);

  SPI.begin();    
  mfrc522.PCD_Init();
  //gsm.start();
  //gsm.smsTextMode(true);

  
  //lcd.setCursor(2, 1);
 // lcd.print("SMART Billing");
  //lcd.setCursor(0, 2);
 // lcd.print("Total = ");
  //delay(500);
  // lcd.clear();




  
}
//char* number = "9536921271";

//int yo=6,ton=1;
void loop() {

if(Serial.available()>0)
  //digital(Write(led,HIGH);
  switch(Serial.read());

  
//  if(ton==1)
  //{
 // noTone(8);
 // ton=2;
 // }
  // lcd.begin(20, 4);
  
  Serial.write(r);
  c=r;
  b=c%100;
   for(i=0;i<=2;i++)
     {
        ba[i]= c%10;
        c=c/10;
     }
     if(ba[2]==2)
     {
      pen=b;
      c=r;
      
     } 
     if(ba[2]==1)
     {
      odonil=b;
      c=r;
     }
     if(ba[2]==0)
     {
      kyring=b;
      c=r;
     }
  
  if (Serial.available() > 0) 
  {
   
    stat = Serial.read(); 
   // Serial.write(stat);
   
   for (i=0;i<=2;i++)
      {
        a[i]=stat%10;
        stat=stat/10;
      }
  }
   
   if(a[0]==2)
    {
      lcd.setCursor(0, 1);
      lcd.print("key ring= ");
      lcd.print(kyring);
      lcd.print("  /-");  
       ky=2;
    }

   if(a[0]==1)
    {
      lcd.setCursor(0, 1);
      lcd.print("kyring= ");
      lcd.print("00");
      lcd.print("  /-");
      if(ky==2)
      ky=1;
    }

   if(a[1]==2)
    {
      lcd.setCursor(0, 2);
      lcd.print("odonil= ");
      lcd.print(odonil);
      lcd.print("  /-");
      od=2;
    }

   if(a[1]==1)
    {
      lcd.setCursor(0, 2);
      lcd.print("odonil= ");
      lcd.print("00");
      lcd.print("  /-");
      od=1;
    }

   if(a[2]==2)
    {
      lcd.setCursor(0, 3);
      lcd.print("pens=");
      lcd.print(pen);
      lcd.print("  /-");
      pe=2;
    }

   if(a[2]==1)
    {
      lcd.setCursor(0, 3);
      lcd.print("pens=");
      lcd.print("00");
      lcd.print("  /-");
      pe=1;
    }
      
///%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if(a[0]==2)
  {
    if(pi==1)
      {
        A=A+kyring;
        T=A;
        pi=2;
      }
  }
if(a[0]==1)
  {
    if(pi==2)
      {
        A=A-kyring;
        T=A;
        pi=1;
      }
  }

  if(a[1]==2)
  {
    if(mi==1)
      {
        A=A+odonil;
        T=A;
        mi=2;
      }
  }
if(a[1]==1)
  {
    if(mi==2)
      {
        A=A-odonil;
        T=A;
        mi=1;
      }
  }

  if(a[2]==2)
  {
    if(ci==1)
      {
        A=A+pen;
        T=A;
        ci=2;
      }
  }
if(a[2]==1)
  {
    if(ci==2)
      {
        A=A-pen;
        T=A;
        ci=1;
      }
  }




      
    lcd.setCursor(12, 3);
    lcd.print("TT.=");
    
      lcd.print(T);
      lcd.print("/-");
    //lcd.print(a[0]);
   // lcd.print("/-");
   // lcd.print(a[1]);
   // lcd.print("/-");
   // lcd.print(a[2]);
   // lcd.print("/-");
    //lcd.setCursor(0, 3);
    //lcd.print("TROLLEY NUMBER = 01");
//-----------------------------------------------------------------------------------------------//

if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {

     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }


 content.toUpperCase();
  if (content.substring(1) == "90 D3 23 D9")
    {
      ky=1;
      if(ky==a[0])
    {
      if(ky==1)
      {
      tone(8, 5000, 600);
      ky=0;
      }
    }
    }

  else if (content.substring(1) == "96 16 3C 9A")
    {
      od=1;
      if(od==a[1])
    {
      if(od==1)
      {
      tone(8, 5000, 600);
      od=0;
      }
    }
    }
     
  else if (content.substring(1) == "ED 0F 24 D9")
    {
      pe=1;
      if(pe==a[2])
    {
      if(pe==1)
      {
      tone(8, 5000, 600);
      pe=0;
      }
    }
    } 


   /* else if (content.substring(1) == "56 5B 05 9A")
      {
        if(yo==6)
        {
      char* message = "hi sir thanks for coming in SBS";
      yo=(gsm.smsSend(number, message));
      }
      }*/

    
    
    
    
  }
  void sndmsg()
{
  firstSerial.println("AT=CMGF=1");
  delay(1000);
  firstSerial.println("AT=CMGS=\"+917060528595\"\r");
  delay(1000);
  firstSerial.println("sms messagers sender");
  delay(100);
  firstSerial.println((char)23);
  delay(1000);
 
}
  
//}

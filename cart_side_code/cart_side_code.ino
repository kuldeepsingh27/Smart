#include <SPI.h>
#include <MFRC522.h>
#include<LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
int pen=50; 
int odonil= 67; 
int kyring =10;
int pears =76;
int AD =100;
unsigned long long int r;
//#define SW1 A0
//#define SW1 A1

MFRC522 mfrc522(SS_PIN, RST_PIN);
const int rs = 7, en = 5, d4 = 6, d5 = 2, d6 = 3, d7 = 4;
LiquidCrystal lcd(7, 5, 6, 2, 3, 4);
void setup() 
{
//  pinMode(SW0,INPUT_PULLUP);
  //pinMode(SW1,INPUT_PULLUP);
  //Serial.begin(9600);
  Serial.begin(38400);   
  SPI.begin();    
  mfrc522.PCD_Init();
  //Serial.println("Approximate your card to the reader...");
  //Serial.println();

}
unsigned int A=0,T=0,k=1,l=1,m=1,n=1,o=2,sum=0,ac=500,P=1,a[3],i=0,b,q;
unsigned long int x=0;
char mystg[5];
void loop()  
{

  if (o==2)
  {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("WELCOME IN");
  lcd.setCursor(2, 2);
  lcd.print("SMART TROLLEY");
  delay(3000);
  o--; 
  }
   lcd.clear();
   lcd.begin(16, 2);
   lcd.print("SCAN THE PRODUCT");
   lcd.setCursor(0, 2);
    lcd.print("TOTAL= ");
    lcd.setCursor(7,2);
    lcd.print(T);
    lcd.print("/-"); 
   // if (p==1)
   // {


     if (Serial.available() > 0) 
   {
    q = Serial.read(); 
   
   b=q%100;
    for(i=0;i<=2;i++)
     {
        a[i]= q%10;
        q=q/10;
     }
     if(a[2]==2)
     {
      pen=b;
     } 
     if(a[2]==1)
     {
      odonil=b;
     }
     if(a[2]==0)
     {
      kyring=b;
     }
   }
    //  pears=a[3];
    x=l;
    x=(m*10)+x;
    x=(n*100)+x;
    Serial.write(x);


   
 //}
 //   Serial.write(T);
  // Serial.write(k);
 //  Serial.write(l);
 //  Serial.write(m);
 //  Serial.write(n);
    
    
   








   
  
  // delay(3000);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
   //  Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
   //  Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  //Serial.println();
  //Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "05 4A 97 1E") 
  {
    //Serial.println("ID = 100/-");
    //Serial.println();
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("Pears = ");
    lcd.print(pears);
    lcd.print("/-");
    tone(8, 10000, 600);
    if (k==1)
    {
     A=A+pears;
     T=A;
     k++;
    } 
    else if (k==2)
    {
     A=A-pears;
     T=A;
     k--;
    } 
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.setCursor(8, 2);
    lcd.print(T);
    lcd.print("/-");
    delay(4000);
    P=1;
   
    
  }
  else if (content.substring(1) == "90 D3 23 D9")
  {
    //Serial.println("key ring = 10/-");
    //Serial.println();
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("Key ring = ");
    lcd.print(kyring);
    lcd.print("/-");
    tone(8, 10000, 600);
    if (l==1)
    {
     A=A+kyring;
     T=A;
     l++;
    } 
    else if (l==2)
    {
     A=A-kyring;
     T=A;
     l--;
    }
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.setCursor(8, 2);
    lcd.print(T);
    lcd.print("/-");
    delay(4000);
    P=1;
  
  }
 else if (content.substring(1) == "96 16 3C 9A") 
  {
    //Serial.println("Protector = 05/-");
    //Serial.println();
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("Odonil = ");
    lcd.print(odonil);
    lcd.print("/-");
    tone(8, 10000, 600);
    if (m==1)
    {
     A=A+odonil;
     T=A;
     m++;
    } 
    else if (m==2)
    {
     A=A-odonil;
     T=A;
     m--;
    }
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.setCursor(8, 2);
    lcd.print(T);
    lcd.print("/-");
    delay(4000);
    P=1;
   
  }
  else if (content.substring(1) == "ED 0F 24 D9") 
  {
   // Serial.println("Pen = 50/-");
    //Serial.println();
    lcd.clear();
    lcd.begin(6,2);
    lcd.print("Pens = ");
    lcd.print(pen);
    lcd.print("/-");
    tone(8, 10000, 600);
    if (n==1)
    {
     A=A+pen;
     T=A;
     n++;
    } 
    else if (n==2)
    {
     A=A-pen;
     T=A;
     n--;
    }
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.setCursor(8, 2);
    lcd.print(T);
    lcd.print("/-");
    delay(4000);
    P=1;
  }
  else if (content.substring(1) == "56 5B 05 9A") 
  {
    //Serial.println("Protector = 05/-");
    //Serial.println();
   // if(q=0)
    //{
    if (ac>=T)
    {
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("YOGI bal.= ");
    lcd.print(ac);
    lcd.print("/-");
    sum=ac-T;
    ac=sum;
    //tone(9, 10000, 600);
    //q++;
    //delay(4000);
    //}
   // if (q==1)
    //{
      lcd.setCursor(0, 2);
      lcd.print("Rem. Bal.= ");
    lcd.print(sum);
    lcd.print("/-");
      tone(8, 10000, 600);
    delay(4000);
 //   tone(9, 10000, 600);
    //q=0;
    //}
     //A=A+odonil;
     //T=A;
     //m++;
   // } 
    //else if (m==2)
    //{
    // A=A-odonil;
    // T=A;
    // m--;
   
    //}
    //lcd.setCursor(0, 1);
    //lcd.print("Total = ");
    //lcd.setCursor(8, 2);
    //lcd.print(T);
  //lcd.print("/-");
   T=0;
   A=0;
    //delay(4000);
 
        // -------------------------------------------------------------------------------------------
        if(k==2)
        {
         k=0;
        } 
        if(l==2)
        {  
         l=0;
        }
        if(m==2)
        { 
         m=0;
        }
        if(n==2)
        {
         n=0;
        }
        
  
         
  if (P==2)
    {
      ac=ac+AD;
      lcd.clear();
    lcd.begin(16, 2);
    lcd.print(AD);
    lcd.print("/- ADDED TO ");
    lcd.setCursor(0, 2);
    lcd.print("YOUR ACCOUNT");
    P=1;
    delay(6000);
      }
   
    }
    else 
    {
      lcd.clear();
    lcd.begin(16, 2);
    lcd.print("  INSUFFICIENT  ");
    lcd.setCursor(0, 2);
    lcd.print("ACCOUNT BALANCE");
    
       tone(8, 10000, 1000);
    delay(6000);
     if (P==2)
    {
      ac=ac+AD;
      lcd.clear();
    lcd.begin(16, 2);
    lcd.print(AD);
    lcd.print("/- ADDED TO ");
    lcd.setCursor(0, 2);
    lcd.print("YOUR ACCOUNT");
    P=1;
    delay(6000);
      }
 
    
      }
//k--;l--;m--;n--;
  }
  else if (content.substring(1) == "05 84 9A 1E") 
  {
   // ac=ac+AD;
      lcd.clear();
    lcd.begin(16, 2);
    //lcd.print(AD);
    lcd.print("FOR ADD MONEY");
    lcd.setCursor(0, 2);
    lcd.print("SCAN ");
    //lcd.setCursor(0, 2);
    lcd.print("YOUR CARD");
    P=2;
    
       tone(8, 10000, 1000);
    delay(6000);
  }
 
 else   
 {
    //Serial.println(" Access denied");
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("Not Valid");
    tone(8, 10000, 1000);
    delay(6000);
 }
    
    
    //delay (5000);
 }

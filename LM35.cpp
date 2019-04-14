/*ในส่วนของ resource กันเลย (ใน .cpp นั่นแหละ) 
    สิ่งแรกที่เราจะทำเลยก็คือทำการ include header file 
    ที่พึ่งเขียนเสร็จไปเมื่อซักครู่เข้ามาอยู่ในโปรแกรม*/
#include "LM35.h"

/* เมื่อ #include มาเสร็จแล้วก็ทำการ Coding พวก function ที่เราประกาศไว้ซะ
    โดยเอาโค้ดจาก .h เอามาเปรียบเทียบกัน
    มาดูที่ฟังชั่นแรกเลยแล้วกัน นั่นก็คือ 
    LM35(int pin); 
    ที่เราตั้งไว้ คือให้มีการรับค่า pin เข้ามาเป็น integer หรือตัวแปรที่เป็นตัวเลขด้วย*/

/*วิธีการสร้าง function ก็จะเป็นดังนี้
    ชนิดการรีเทิร์น ชื่อคลาส::ชื่อฟังชั่น(ค่าอากิวเม้นต์);
    ใน function แรกจะประกาศแค่ LM35::LM35(int pin){ ... } 
    ฟังชั่นนี้ไม่มีการรีเทิร์นค่า ก็ไม่ต้องใส่ชนิดการรีเทิร์น จริง ๆ พวก constructor 
    จะไม่สามารถรีเทิร์นค่ากลับมาได้อยู่แล้วที่เหลือก็น่าจะเดากันออก 
    ก็คือพวก attribute ต่าง ๆ ที่เรากำหนดไว้ที่ header ไฟล์ยังไม่ถูกกำหนดค่าให้กับตัวแปร 
    ดังนั้นเราจึงต้องกำหนดในฟังชั่นนี้ เพื่อจะได้สามารถเรียกใช้ตัวแปรได้อย่างถูกต้อง*/
LM35::LM35(int pin)
{
    pinMode(pin,INPUT);
    this->tempC=0.0;
    this->tempF=0.0;
    this->temp=pin;
    original=0;  
}

/*สร้าง function นั้นจะต้องมี 
    returnType  ClassName::functionName(argument);
ถ้าเกิดฟังชั่นไหนใส่ returnType ด้วยละก็อย่าลืม return ค่าละกันเดี๋ยว error 
การคำนวณต่าง ๆ ก็จะเป็นไปตามรูปนั่นแหละครับ*/
float LM35::getTempC()
{
    tempC=(5.0*analogRead(temp)*100/1024.0);
    return tempC;
}

float LM35::getTempF()
{
    tempF=((9*getTempC())/5)+32;
    return tempF;
}

int LM35::getOriginalTemp()
{
    original=analogRead(temp);
    return original;
}
#include "Arduino.h"

/*
Stranger Things (Netflix - All Rights Reserved) Project

This project aims to build a luminous panel showing words similar 
to what is on the wall of the living room of 
Stranger Things (Netflix - All Rights Reserved) TV series.

Author: Samir Trajano Feitosa
License: Apache 2.0
----------------------------------------
-----| https://github.com/samirtf |-----
----------------------------------------
*/
 
int const DELAY = 2000; //delay 74HC595

// First Shift Register 74HC595
int const clockSR1 = 2; // clock
int const latchSR1 = 3; // latch
int const dataSR1  = 4; // data

// Second Shift Register 74HC595
int const clockSR2 = 5; // clock
int const latchSR2 = 6; // latch
int const dataSR2  = 7; // data

// Third Shift Register 74HC595
int const clockSR3 = 8; // clock
int const latchSR3 = 9; // latch
int const dataSR3  = 10; // data

// letters Y & Z - pins
int const letterY  = 11; // setted to pin 11
int const letterZ  = 12; // setted to pin 12

 
void setup() {
  // setting pins as output
  pinMode(clockSR1,OUTPUT);
  pinMode(latchSR1,OUTPUT);
  pinMode(dataSR1, OUTPUT);
  pinMode(clockSR2,OUTPUT);
  pinMode(latchSR2,OUTPUT);
  pinMode(dataSR2, OUTPUT);
  pinMode(clockSR3,OUTPUT);
  pinMode(latchSR3,OUTPUT);
  pinMode(dataSR3, OUTPUT);
  pinMode(letterY, OUTPUT);
  pinMode(letterZ, OUTPUT);
}

// Clear all shift registers and Y & Z pins.
void clearAll() {
  clearSR(1);
  clearSR(2);
  clearSR(3);
  digitalWrite(letterY, LOW); 
  digitalWrite(letterZ, LOW);
}

// Clear a shiftRegister
void clearSR(int shiftRegister) {
  led(shiftRegister, 0, 0);
}

// Set a value to a shift register and a delay
void led(int shiftRegister, int value, int aDelay) {
    if( shiftRegister == 1 ) {
      
        // allow data flow 
        digitalWrite(latchSR1,LOW); 
        
        for (int x = 0; x <= 7; x++) {
 
            // ready to get the bit
            digitalWrite(clockSR1,LOW); 
       
            if (value & (1 << x)) {
                digitalWrite(dataSR1,HIGH);
            } else {
                digitalWrite(dataSR1,LOW);
            }
       
            // store the received bit
            digitalWrite(clockSR1,HIGH); 
        }   
     
        // close the data flow and send the 8 bits
        digitalWrite(latchSR1,HIGH);
        
    } else if (shiftRegister == 2) {
      
        // allow data flow     
        digitalWrite(latchSR2,LOW); 
        
        for (int x = 0; x <= 7; x++) {
 
            // ready to get the bit
            digitalWrite(clockSR2,LOW); 
       
            if (value & (1 << x)) {
                digitalWrite(dataSR2,HIGH);
            } else {
                digitalWrite(dataSR2,LOW);
            }
       
            // store the received bit
            digitalWrite(clockSR2,HIGH); 
        }   
     
        // close the data flow and send the 8 bits
        digitalWrite(latchSR2,HIGH);
        
    } else if (shiftRegister == 3) {
      
        // allow data flow   
        digitalWrite(latchSR3,LOW); 
        
        for (int x = 0; x <= 7; x++) {
 
            // ready to get the bit
            digitalWrite(clockSR3,LOW); 
       
            if (value & (1 << x)) {
                digitalWrite(dataSR3,HIGH);
            } else {
                digitalWrite(dataSR3,LOW);
            }
       
            // store the received bit
            digitalWrite(clockSR3,HIGH); 
        }   
     
        // close the data flow and send the 8 bits
        digitalWrite(latchSR3,HIGH); 
        
    } else { /* do nothing */ }
    delay(aDelay);
}

// SR1 = [a:1, b:2, c:3, d:4, e:5, f:6, g:7, h:8]
void a() {
    led(1, 1, DELAY);
}
void b() {
    led(1, 2, DELAY);
}
void c() {
    led(1, 4, DELAY);
}
void d() {
    led(1, 8, DELAY);
}
void e() {
    led(1, 16, DELAY);
}
void f() {
    led(1, 32, DELAY);
}
void g() {
    led(1, 64, DELAY);
}
void h() {
    led(1, 128, DELAY);
}


// SR2 = [i:1, j:2, k:3, l:4, m:5, n:6, o:7, p:8]
void i() {
    led(2, 1, DELAY);
}
void j() {
    led(2, 2, DELAY);
}
void k() {
    led(2, 4, DELAY);
}
void l() {
    led(2, 8, DELAY);
}
void m() {
    led(2, 16, DELAY);
}
void n() {
    led(2, 32, DELAY);
}
void o() {
    led(2, 34, DELAY);
}
void p() {
    led(2, 128, DELAY);
}

// SR3 = [q:1, r:2, s:3, t:4, u:5, v:6, w:7, x:8]
void q() {
    led(3, 1, DELAY);
}
void r() {
    led(3, 2, DELAY);
}
void s() {
    led(3, 4, DELAY);
}
void t() {
    led(3, 8, DELAY);
}
void u() {
    led(3, 16, DELAY);
}
void v() {
    led(3, 32, DELAY);
}
void w() {
    led(3, 34, DELAY);
}
void x() {
    led(3, 128, DELAY);
}

// IO = [y, z]
void y() {
    digitalWrite(letterY, HIGH);
}
void z() { 
    digitalWrite(letterZ, HIGH);
}

void testSR1() {
    a();
    clearAll();
    b();
    clearAll();
    c();
    clearAll();
    d();
    clearAll();  
    e();
    clearAll();  
    f();
    clearAll();  
    g();
    clearAll();  
    h();
    clearAll();  
}

void testSR2() {
    i();
    clearAll();
    j();
    clearAll();
    k();
    clearAll();
    l();
    clearAll();  
    m();
    clearAll();  
    n();
    clearAll();  
    o();
    clearAll();  
    p();
    clearAll();  
}

void testSR3() {
    q();
    clearAll();
    r();
    clearAll();
    s();
    clearAll();
    t();
    clearAll();  
    u();
    clearAll();  
    v();
    clearAll();  
    w();
    clearAll();  
    x();
    clearAll();  
}

void foraTemer() {
    
    f();
    clearAll();
    o();
    clearAll();
    r();
    clearAll();
    a();
    clearAll();
    
    clearAll();
    
    t();
    clearAll();
    e();
    clearAll();
    m();
    clearAll();
    e();
    clearAll();
    r();
    clearAll();
    
    clearAll();
    
}

void run() {
    
    r();
    clearAll();
    u();
    clearAll();
    n();
    clearAll();
    
    clearAll();
    
}

void masoq() {
    m();
    clearAll();
    a();
    clearAll();
    s();
    clearAll();
    o();
    clearAll();
    q();
    clearAll();
    
    clearAll();
}

void mebeija() {
    m();
    clearAll();
    e();
    clearAll();
    
    clearAll();
    
    b();
    clearAll();
    e();
    clearAll();
    i();
    clearAll();
    j();
    clearAll();
    a();
    clearAll();
    
    clearAll();
}

void showText(int index) {
    if (index == 0 ) {
        testSR1();
        testSR2();
        testSR3();
        y();
        clearAll();
        z();
        clearAll();
        
    } else if (index == 1) {
        foraTemer();
    } else if (index == 2) {
        run();
    } else if (index == 3) {
        masoq();
    } else if (index == 4) {
        mebeija();
    }
}

 
void loop() {

    clearAll();
    // wait time between a char and other.
    delay(1000);
    
    showText(0);
    clearAll();
    
    delay(1000);
     
}

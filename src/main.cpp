#include <Arduino.h>

boolean durum0=false;
boolean durum1=false;
void setup() {
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
  cli();
  //timer 0 2 kHz ayarlanıyor
  TCCR0A=0;
  TCCR0B=0;
  TCNT0=0;
  //OCRxA karşılaştırma registeri 2 kHz için ayarlanıyor
  //16 MHz osilatör 2 kHz timerın çalışma frekası 64 bit prescaler
  OCR0A=124;
  //CTC mod açılıyor
  TCCR0A|=(1<<WGM01);
  //CS01 ve CS00 bitleri 64 prescaler için ayarlanıyor
  TCCR0B|=((1<<CS01)|(1<<CS00));
  //timer karşılaştırma interruptı aktifleştiriliyor
  TIMSK0=(1<<OCIE0A);
  // timer 1 interrupt 1 Hze kuruluyor
  TCCR1A=0;
  TCCR1B=0;
  TCNT1=0;
  OCR1A=15624;
  TCCR1B|=(1<<WGM12);
  TCCR1B|=((1<<CS10)|(1<<CS12));
  TIMSK1|=(1<<OCIE1A);
  sei();
}
ISR(TIMER0_COMPA_vect){
  if (durum0)
  {
    digitalWrite(8,HIGH);
    durum0=0;
  }
  else{
    digitalWrite(8,LOW);
    durum0=1;
  }  

}
ISR(TIMER1_COMPA_vect){
    if (durum1)
    {
      digitalWrite(13, HIGH);
      durum1 = 0;
    }
    else
    { digitalWrite(13, HIGH);
      durum1 = 1;
    }


}

void loop() {
  // put your main code here, to run repeatedly:
}
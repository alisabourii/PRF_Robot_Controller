#include <Enrf24.h>
#include <nRF24L01.h>
#include <SPI.h>

Enrf24 nRF(9, 10, 8);  // CE , CSN/CS/SS , IRQ bacaklarının Arduino ile bağlantıları tanımlandı

// verici adresi tanımlandı aynı adres alıcıda da tanımlanmalıdır
const byte verici_adresi[] = { 0xDE, 0xAD, 0xBE, 0x0F, 0x01 };

void setup() {
  Serial.begin(9600);
  SPI.begin(); // SPI başlat
  SPI.setDataMode(SPI_MODE0); // SPI MODE0 seçildi, nrf24l01 MODE0 ile iletişim kurmaktadır
  SPI.setBitOrder(MSBFIRST); // bit sıralaması MSB'den LSB'ye doğru ayarlandı
  nRF.begin(1000000,124);  
  nRF.setTXaddress(verici_adresi); // verici adresi ayarlandı
  for(int i=2; i<=5; i++)
    pinMode(i, INPUT_PULLUP);
}    

void loop() {
  if(digitalRead(3) == 0){
    Serial.println("A");
    nRF.print("A"); 
    nRF.flush();}

  if(digitalRead(4) == 0){
    Serial.println("B");
    nRF.print("B"); 
    nRF.flush();}

  if(digitalRead(5) == 0){
    Serial.println("C");
    nRF.print("C"); 
    nRF.flush();}

   if(digitalRead(6) == 0){
    Serial.println("D");
    nRF.print("D"); 
    nRF.flush();}

}

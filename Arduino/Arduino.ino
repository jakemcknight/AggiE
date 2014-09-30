double accel[3], gyro[3], mag[3];
const int SD_CS = 20;
#include <SdFat.h>
SdFat sd;
SdFile myFile;

void setup(){
  Serial.begin(57600);
  Serial1 .begin(9600);        //GPS
  Serial2.begin(57600);       //IMU
  
  if (!sd.begin(SD_CS, SPI_HALF_SPEED))
    Serial.println("SD Error!");
}

void loop(){
  readIMU();
  Serial.print(accel[0]); Serial.print(",");
  Serial.print(accel[1]); Serial.print(",");
  Serial.print(accel[2]); Serial.print(",");
  Serial.print(gyro[0]); Serial.print(",");
  Serial.print(gyro[1]); Serial.print(",");
  Serial.print(gyro[2]); Serial.print(",");
  Serial.print(mag[0]); Serial.print(",");
  Serial.print(mag[1]); Serial.print(",");
  Serial.print(mag[2]); Serial.println("");
  if (!myFile.open("data.txt", O_RDWR | O_CREAT | O_AT_END)) {
    Serial.println("File error!");
  }
  else{
    myFile.print(accel[0]); myFile.print(",");
    myFile.print(accel[1]); myFile.print(",");
    myFile.print(accel[2]); myFile.print(",");
    myFile.print(gyro[0]); myFile.print(",");
    myFile.print(gyro[1]); myFile.print(",");
    myFile.print(gyro[2]); myFile.print(",");
    myFile.print(mag[0]); myFile.print(",");
    myFile.print(mag[1]); myFile.print(",");
    myFile.print(mag[2]); myFile.println("");
    myFile.close();   
  }
  delay(200);
}

void readIMU(){
  Serial2.print("#j");
  delayMicroseconds(20);
  accel[0] = Serial2.parseFloat();
  accel[2] = Serial2.parseFloat();
  accel[3] = Serial2.parseFloat();
  gyro[0] = Serial2.parseFloat();
  gyro[2] = Serial2.parseFloat();
  gyro[3] = Serial2.parseFloat();
  mag[0] = Serial2.parseFloat();
  mag[2] = Serial2.parseFloat();
  mag[3] = Serial2.parseFloat();
}

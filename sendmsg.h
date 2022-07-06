// set 'sendto' and 'msg' variables before calling this function

void SendMessage()
{
  msg="Set Water level reached. SIREN ON";
    Serial.println(msg);
    
    for (i=0;i<5;i++)  // looping to send SMS to all the receipients
    {
      
  //Serial.println(" started sending");
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  replyfrommodem="OK";
  ModemResponse();
  //dlytime=10000;  
  //Dly();
  //delay(1000);  // Delay of 1000 milli seconds or 1 second

  sendto=recipientNumber[i];
      
  //mySerial.println("AT+CMGS=\"+919611839500\"\r"); // Replace x with mobile number
  mySerial.println("AT+CMGS=\""+sendto+"\"\r");  
  replyfrommodem="+CMGS";
  ModemResponse();
//dlytime=10000;  
  //Dly();  
  //delay(1000);
  //mySerial.println("sim900a sms");// The SMS text you want to send
  mySerial.println(msg);
  //dlytime=1000;  
  //Dly();
  delay(100);
  
  mySerial.println((char)26);// ASCII code of CTRL+Z
  //dlytime=10000;  
  //Dly();
  delay(1000);
  
}
}

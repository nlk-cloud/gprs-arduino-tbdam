

void ModemResponse()
{
  String collect = "";
  long prev = millis();
  int tst=0;
//long now=millis();
 Serial.println(millis()-prev);
while((tst==0)&&((millis()-prev) < 20000))
{
  //Serial.println("entered while");
  //Serial.println(millis()-prev);
//if((millis()-prev) < 20000)
//{
  //Serial.println("entered first if");
  collect=mySerial.readString();
  //Serial.println(collect);
    if ( collect.indexOf(replyfrommodem) >= 0 ) 
    {  // full response obtained
      tst=1;
    }
  else { continue;}
   
//}
}
  if ( collect.indexOf(replyfrommodem) == -1 ) 
    {  
      Serial.println("No response from network");
    }

    Serial.println(collect);
}

/*while( 1 ) {
delay(1);  // slow things down a  bit
//char c = (char) sim800l.read();
//collect += c;
collect=mySerial.readString();
if ( millis() - prev > 2000 ) {  // get out if no response in 2 secs
Serial.println("No response from network");
break;
}

if ( collect.indexOf(replyfrommodem) >= 0 ) {  // full response obtained
break;
}
}
*/

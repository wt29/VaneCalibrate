int vane, aMax=0, aMin=2000, vTrue, vAbs, vOffset;
float perDegree; 

void setup() {
   Serial.begin(115200);     // baud rate
}

void loop() {
 vane = analogRead(A0);   // reads the actual value from the Analog 
 if (vane < aMin) {aMin=vane;}  // Calc the actual analog max /min
 if (vane > aMax) {aMax=vane;}
 perDegree = (aMax-aMin)/360.0;   // Scales the max / min to degrees
 Serial.print( "vane " );
 Serial.println( vane );
 Serial.print( "Max " );
 Serial.println( aMax );
 Serial.print( "Min " );
 Serial.println( aMin );
 vane -= aMin;       // delete the offset value of the VR
 vAbs = vane/perDegree;  // how many degrees are we rotates
 Serial.print( "perDegree " );
 Serial.println( perDegree );
 Serial.print( "vane / PerDegree " );
 Serial.println( vAbs );
 vOffset = 70;            // this is actually a combination of the "zeropoint" on the VR and its actual compass orientation
 vTrue = vAbs + vOffset;  // Calculate the offset and figure out the true compass
 if (vTrue > 360 ) {vTrue -= 360;}
 Serial.print( "True " );   
 Serial.println( vTrue );
 delay( 250 );
 
}

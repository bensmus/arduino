/* program checks when the button was clicked 
 * a click is defined as a press and then a release  
 * but this has to happen within half a second
 */
int state = 0;

// will be implemented circularly
int times[2] = {0, 0};

void add_circularly(int pair[], int val) {
  int first = pair[0];
  pair[0] = val;
  pair[1] = first;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  // update state
  if (state == 0) {
    if (digitalRead(2) == HIGH) {
      state = 1;
      add_circularly(times, millis());
    }
  }
  if (state == 1) {
    if (digitalRead(2) == LOW) {
      state = 0;
      add_circularly(times, millis());

      // check if click occured
      if ((times[0] - times[1]) < 500) {
        Serial.print("click at ");
        Serial.print(times[0]);
        Serial.println();
      }
    }
  }  
}

// Used with DigiSpark's RGB LED shield
// Used from DigiStump Oak

unsigned rounds = 0;
char publishString[40];

int r_value = random(256);
int g_value = random(256);
int b_value = random(256);

void setup() {
    // Initialize the LED pins as outputs
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    
    analogWrite(0, r_value);   // Turn the red LED off
    analogWrite(1, g_value);   // Turn the green LED off
    analogWrite(2, b_value);   // Turn the blue LED off

    //Particle.variable("rounds", rounds);
}


 
void loop() {
    int r_old = r_value;
    int g_old = g_value;
    int b_old = b_value;
    r_value = random(256);
    g_value = random(256);
    b_value = random(256);
    //sprintf(publishString, "old: %d", r_old);
    //Particle.publish("old", publishString);
    //sprintf(publishString, "new: %d", r_value);
    //Particle.publish("new", publishString);

    int duration = 2000;
    float segments = 50.0;
    float subsegments = segments * 3.0;
    for (int i = 0; i < segments; i++) {
      float tmp_r = ((((float)r_value - (float)r_old)/segments)*i) + (float)r_old;
      float tmp_g = ((((float)g_value - (float)g_old)/segments)*i) + (float)g_old;
      float tmp_b = ((((float)b_value - (float)b_old)/segments)*i) + (float)b_old;
      analogWrite(0, tmp_r);
      delay(duration/subsegments);
      analogWrite(1, tmp_g);
      delay(duration/subsegments);
      analogWrite(2, tmp_b);
      delay(duration/subsegments);
    }
    

    //delay(1000);            // Wait for a second
    //rounds = rounds + 1;
    //sprintf(publishString, "%u", rounds);
    //Particle.publish("round completed", publishString);
}

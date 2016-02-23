// Used with DigiSpark's RGB LED shield
// Used from DigiStump Oak

unsigned rounds = 0;
char publishString[40];

int r_new = 0;
int g_new = 0;
int b_new = 0;

void setup() {
    // Initialize the LED pins as outputs
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    
    analogWrite(0, r_new);   // Turn the red LED off
    analogWrite(1, g_new);   // Turn the green LED off
    analogWrite(2, b_new);   // Turn the blue LED off

    //Particle.variable("rounds", rounds);
}

void blend(int r1, int g1, int b1, int r2, int g2, int b2, int duration, int intSegments) {
    float segments = (float) intSegments;
    float subsegments = segments * 3.0;
    for (int i = 0; i < segments; i++) {
      float tmp_r = ((((float)r2 - (float)r1)/segments)*i) + (float)r1;
      float tmp_g = ((((float)g2 - (float)g1)/segments)*i) + (float)g1;
      float tmp_b = ((((float)b2 - (float)b2)/segments)*i) + (float)b2;
      analogWrite(0, tmp_r);
      delay(duration/subsegments);
      analogWrite(1, tmp_g);
      delay(duration/subsegments);
      analogWrite(2, tmp_b);
      delay(duration/subsegments);
    }
}


 
void loop() {
    int r_old = r_new;
    int g_old = g_new;
    int b_old = b_new;
    r_new = random(256);
    g_new = random(256);
    b_new = random(256);

    blend(r_old, g_old, b_old, r_new, g_new, b_new, 500, 50);
    //sprintf(publishString, "old: %d", r_old);
    //Particle.publish("old", publishString);
    //sprintf(publishString, "new: %d", r_value);
    //Particle.publish("new", publishString);
}

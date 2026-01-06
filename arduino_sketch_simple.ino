/*
 * SIMPLIFIED UNIVERSAL ULTRASONIC DISTANCE SENSOR
 * Works with BOTH Python scripts simultaneously:
 * - Distance_custom_audio.py (listens for "PLAY_AUDIO")
 * - Distance_GUI.py (reads distance values)
 * 
 * No mode selection needed - just upload and run!
 */

#define TRIG 9        // TRIG pin of HC-SR04 -> D9 of Arduino 
#define ECHO 10       // ECHO pin of HC-SR04 -> D10 of Arduino 
#define LED 3         // LED -> D3 of Arduino 

// Distance thresholds for trigger
#define MIN_DISTANCE 10
#define MAX_DISTANCE 40

// Debounce delay to prevent audio spam
#define DEBOUNCE_DELAY 1500

unsigned long lastTriggerTime = 0;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, LOW);
  Serial.begin(9600);
  
  delay(500);  // Startup delay
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo with timeout
  long duration = pulseIn(ECHO, HIGH, 30000);
  float distance = duration * 0.0343 / 2;  // Convert to centimeters
  
  // Validate reading
  if (distance <= 0 || distance > 400) {
    distance = 0;
  }
  
  // Always output distance (for GUI script)
  Serial.println(distance);
  
  // Check if object is in danger zone
  if (distance > MIN_DISTANCE && distance < MAX_DISTANCE) {
    unsigned long currentTime = millis();
    
    // Send audio trigger if cooldown expired
    if (currentTime - lastTriggerTime > DEBOUNCE_DELAY) {
      digitalWrite(LED, HIGH);
      Serial.println("PLAY_AUDIO");  // For audio script
      lastTriggerTime = currentTime;
    }
  } else {
    digitalWrite(LED, LOW);
  }
  
  delay(100);  // 10 Hz sampling rate
}

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

const char* ssid = "your_wifi_name";
const char* password = "your_wifi_password";

WebServer server(80);

void handleRoot() {
  // Send the HTML form to the client
  String html = "<!DOCTYPE html><html><head><title>Send Text to ESP32-S3</title></head><body><h1>Send Text to ESP32-S3</h1><form method='post' action='/sendtext'><label for='text'>Enter text:</label><input type='text' name='text' id='text' required><br><button type='submit'>Send</button></form></body></html>";
  server.send(200, "text/html", html);
}

void handleText() {
  if (server.method() == HTTP_POST) {
    String text = server.arg("text");
    Serial.println("Received text: " + text);

    // Send a response back to the client
    server.send(200, "text/html", "<h1>Text received</h1><p>You entered: " + text + "</p>");
  } else {
    server.send(405, "text/html", "<h1>Method Not Allowed</h1>");
  }
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Set up the routes for handling HTTP requests
  server.on("/", handleRoot);
  server.on("/sendtext", handleText);

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Handle incoming HTTP requests
  server.handleClient();
}

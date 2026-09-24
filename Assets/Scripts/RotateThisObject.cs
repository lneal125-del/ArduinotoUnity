using UnityEngine;

public class RotateThisObject : MonoBehaviour
{
    // Reference to the SerialSensorData script
    public GetArduinoData sensorData;
    // Reference the potentiometer value from the SerialSensorData script
    public int potentiometerValue;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (sensorData != null)
        {
            // Get the potentiometer value from the SerialSensorData script
            potentiometerValue = sensorData.potentiometerValue;

            // Map the potentiometer value to a rotation angle (0 to 360 degrees)
            float rotationAngle = Mathf.Lerp(0f, 360f, potentiometerValue / 1023f);

            // Rotate the object around the Y-axis based on the potentiometer value
            transform.rotation = Quaternion.Euler(0f, rotationAngle, 0f);
        }
    }
}

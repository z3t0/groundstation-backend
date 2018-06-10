#include <stdint.h>

#pragma pack(1)
struct telemetry_frame {
    uint32_t mission_time;
    
    /*** ADC Data and Flags ***/
    
    // ADC0
    uint16_t state:3;
    uint16_t flag_ematch_1_present:1;
    uint16_t flag_ematch_2_present:1;
    uint16_t flag_parachute_deployed:1;
    uint16_t adc_cap_voltage:10;        // Multiply by 0.02625071131 to get value in volts
    // ADC1
    uint16_t flag_gps_data_valid:1;
    uint16_t flag_7:1;
    uint16_t flag_8:1;
    uint16_t flag_9:1;
    uint16_t flag_10:1;
    uint16_t flag_11:1;
    uint16_t adc_temp_1:10;             // Multiply by 0.00322265625 to get value in degrees celsius
    // ADC2
    uint16_t flag_12:1;
    uint16_t flag_13:1;
    uint16_t flag_14:1;
    uint16_t flag_15:1;
    uint16_t flag_16:1;
    uint16_t flag_17:1;
    uint16_t adc_temp_2:10;             // Multiply by 0.00322265625 to get value in degrees celsius
    // ADC3
    uint16_t flag_18:1;
    uint16_t flag_19:1;
    uint16_t flag_20:1;
    uint16_t flag_21:1;
    uint16_t flag_22:1;
    uint16_t flag_23:1;
    uint16_t adc_3:10;
    // ADC4
    uint16_t flag_24:1;
    uint16_t flag_25:1;
    uint16_t flag_26:1;
    uint16_t flag_27:1;
    uint16_t flag_28:1;
    uint16_t flag_29:1;
    uint16_t adc_4:10;
    // ADC5
    uint16_t flag_30:1;
    uint16_t flag_31:1;
    uint16_t flag_32:1;
    uint16_t flag_33:1;
    uint16_t flag_34:1;
    uint16_t flag_35:1;
    uint16_t adc_5:10;
    // ADC6
    uint16_t flag_36:1;
    uint16_t flag_37:1;
    uint16_t flag_38:1;
    uint16_t flag_39:1;
    uint16_t flag_40:1;
    uint16_t flag_41:1;
    uint16_t adc_6:10;
    // ADC7
    uint16_t flag_42:1;
    uint16_t flag_43:1;
    uint16_t flag_44:1;
    uint16_t flag_45:1;
    uint16_t flag_46:1;
    uint16_t flag_47:1;
    uint16_t adc_batt_voltage:10;           // Multiply by 0.01434657506 to get value in volts
    
    
    /*** Accelerometer ***/
    int16_t acceleration_x;
    int16_t acceleration_y;
    int16_t acceleration_z;
    
    
    /*** Gyroscope ***/
    int16_t pitch_rate;
    int16_t roll_rate;
    int16_t yaw_rate;
    int8_t  gyro_temp;
    
    
    /*** Altimiter ***/
    uint8_t altitude_lsb;
    uint8_t altitude_csb;
    uint8_t altitude_msb;
    uint8_t alt_temp_lsb;
    uint8_t alt_temp_msb;
    
    
    /*** Gyroscope ***/
    uint32_t gps_time;
    int32_t lattitude;
    int32_t longitude;
    uint16_t ground_speed;
    uint16_t course_over_ground;
    uint32_t gps_sample_time;
} __attribute__((packed));

// Not when using these structures, source_address, destintation_address and payload_type should be cast to and from their
// respective enum types.

#pragma pack(1)
struct telemetry_api_frame {
    uint8_t start_delimiter;            // 0x52
    
    uint8_t source_address;
    uint8_t destination_address;
    
    uint8_t payload_type;
    
    uint16_t length:15;
    uint16_t crc_present:1;
    
    struct telemetry_frame payload;
    
    uint8_t end_delimiter;              // 0xCC
};

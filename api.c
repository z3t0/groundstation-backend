#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api.h"

#define LENGTH 64

struct telemetry_api_frame* parse_frame (char* data) {
  return (struct telemetry_api_frame *) data;
}

void hex_to_bytes (char* src, char* out) {

  char *pos = src;
  unsigned char val[LENGTH];

  /* WARNING: no sanitization or error-checking whatsoever */
  for (size_t count = 0; count < LENGTH; count++) {
    sscanf(pos, "%2hhx", &out[count]);
    pos += 2;
  }

  printf("0x");
  for(size_t count = 0; count < LENGTH; count++)
    printf("%02x", out[count]);
  printf("\n");

}

void frame_to_binary (struct telemetry_api_frame* frame) {
  char* buffer = (char *) frame;

  for (int i = 0; i < LENGTH; i++) {
    printf("%2hhx", buffer[i]);
  }

  printf("\n");
}

void print_frame(struct telemetry_api_frame* frame) {
  printf("%d\n", frame->source_address);
  printf("%d\n", frame->destination_address);
  printf("%d\n", frame->payload_type);
  printf("%d\n", frame->length);
  printf("%d\n", frame->crc_present);

  // Payload
  
  printf("%d\n", frame->payload.mission_time);
  printf("%d\n", frame->payload.state);
  printf("%d\n", frame->payload.flag_ematch_1_present);
  printf("%d\n", frame->payload.flag_ematch_2_present);
  printf("%d\n", frame->payload.flag_parachute_deployed);
  printf("%d\n", frame->payload.adc_cap_voltage);
  printf("%d\n", frame->payload.flag_gps_data_valid);
  printf("%d\n", frame->payload.flag_7);
  printf("%d\n", frame->payload.flag_8);
  printf("%d\n", frame->payload.flag_9);
  printf("%d\n", frame->payload.flag_10);
  printf("%d\n", frame->payload.flag_11);
  printf("%d\n", frame->payload.adc_temp_1);
  printf("%d\n", frame->payload.flag_12);
  printf("%d\n", frame->payload.flag_13);
  printf("%d\n", frame->payload.flag_14);
  printf("%d\n", frame->payload.flag_15);
  printf("%d\n", frame->payload.flag_16);
  printf("%d\n", frame->payload.flag_17);
  printf("%d\n", frame->payload.adc_temp_2);
  printf("%d\n", frame->payload.flag_18);
  printf("%d\n", frame->payload.flag_19);
  printf("%d\n", frame->payload.flag_20);
  printf("%d\n", frame->payload.flag_21);
  printf("%d\n", frame->payload.flag_22);
  printf("%d\n", frame->payload.flag_23);
  printf("%d\n", frame->payload.adc_3);
  printf("%d\n", frame->payload.flag_24);
  printf("%d\n", frame->payload.flag_25);
  printf("%d\n", frame->payload.flag_26);
  printf("%d\n", frame->payload.flag_27);
  printf("%d\n", frame->payload.flag_28);
  printf("%d\n", frame->payload.flag_29);
  printf("%d\n", frame->payload.adc_4);
  printf("%d\n", frame->payload.flag_30);
  printf("%d\n", frame->payload.flag_31);
  printf("%d\n", frame->payload.flag_32);
  printf("%d\n", frame->payload.flag_33);
  printf("%d\n", frame->payload.flag_34);
  printf("%d\n", frame->payload.flag_35);
  printf("%d\n", frame->payload.adc_5);
  printf("%d\n", frame->payload.flag_36);
  printf("%d\n", frame->payload.flag_37);
  printf("%d\n", frame->payload.flag_38);
  printf("%d\n", frame->payload.flag_39);
  printf("%d\n", frame->payload.flag_40);
  printf("%d\n", frame->payload.flag_41);
  printf("%d\n", frame->payload.adc_6);
  printf("%d\n", frame->payload.flag_42);
  printf("%d\n", frame->payload.flag_43);
  printf("%d\n", frame->payload.flag_44);
  printf("%d\n", frame->payload.flag_45);
  printf("%d\n", frame->payload.flag_46);
  printf("%d\n", frame->payload.flag_47);
  printf("%d\n", frame->payload.adc_batt_voltage);
  printf("%d\n", frame->payload.acceleration_x);
  printf("%d\n", frame->payload.acceleration_y);
  printf("%d\n", frame->payload.acceleration_z);
  printf("%d\n", frame->payload.pitch_rate);
  printf("%d\n", frame->payload.roll_rate);
  printf("%d\n", frame->payload.yaw_rate);
  printf("%d\n", frame->payload.gyro_temp);
  printf("%d\n", frame->payload.altitude_lsb);
  printf("%d\n", frame->payload.altitude_csb);
  printf("%d\n", frame->payload.altitude_msb);
  printf("%d\n", frame->payload.alt_temp_lsb);
  printf("%d\n", frame->payload.alt_temp_msb);
  printf("%d\n", frame->payload.gps_time);
  printf("%d\n", frame->payload.lattitude);
  printf("%d\n", frame->payload.longitude);
  printf("%d\n", frame->payload.ground_speed);
  printf("%d\n", frame->payload.course_over_ground);
  printf("%d\n", frame->payload.gps_sample_time);

  printf("%d\n", frame->crc);
}

int main(int argc, char* argv[]) {
  unsigned char data[LENGTH]; 
  hex_to_bytes(argv[1], &data); 

  struct telemetry_api_frame* frame = parse_frame(data);
  print_frame(frame);
}

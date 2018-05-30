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

  /* printf("0x"); */
  /* for(size_t count = 0; count < LENGTH; count++) */
  /*   printf("%02x", out[count]); */
  /* printf("\n"); */

}

void frame_to_binary (struct telemetry_api_frame* frame) {
  char* buffer = (char *) frame;

  for (int i = 0; i < LENGTH; i++) {
    printf("%2hhx", buffer[i]);
  }

  printf("\n");
}

void print_elem (char* key, int val, int last) {
  printf("\"%s\": %d", key, val);
  if (!last)
    printf(",\n");
  else
    printf("\n}\n");
}

void print_frame(struct telemetry_api_frame* frame) {
  printf("{");
  print_elem("source_address", frame->source_address, 0);
  print_elem("destination_address", frame->destination_address, 0);
  print_elem("payload_type", frame->payload_type, 0);
  print_elem("length", frame->length, 0);
  print_elem("crc_present", frame->crc_present, 0);

  // Payload
  printf("\"payload\": {");
  print_elem("mission_time", frame->payload.mission_time, 0);
  print_elem("state", frame->payload.state, 0);
  print_elem("flag_ematch_1_present", frame->payload.flag_ematch_1_present, 0);
  print_elem("flag_ematch_2_present", frame->payload.flag_ematch_2_present, 0);
  print_elem("flag_parachute_deployed", frame->payload.flag_parachute_deployed, 0);
  print_elem("adc_cap_voltage", frame->payload.adc_cap_voltage, 0);
  print_elem("flag_gps_data_valid", frame->payload.flag_gps_data_valid, 0);
  print_elem("flag_7", frame->payload.flag_7, 0);
  print_elem("flag_8", frame->payload.flag_8, 0);
  print_elem("flag_9", frame->payload.flag_9, 0);
  print_elem("flag_10", frame->payload.flag_10, 0);
  print_elem("flag_11", frame->payload.flag_11, 0);
  print_elem("adc_temp_1", frame->payload.adc_temp_1, 0);
  print_elem("flag_12", frame->payload.flag_12, 0);
  print_elem("flag_13", frame->payload.flag_13, 0);
  print_elem("flag_14", frame->payload.flag_14, 0);
  print_elem("flag_15", frame->payload.flag_15, 0);
  print_elem("flag_16", frame->payload.flag_16, 0);
  print_elem("flag_17", frame->payload.flag_17, 0);
  print_elem("adc_temp_2", frame->payload.adc_temp_2, 0);
  print_elem("flag_18", frame->payload.flag_18, 0);
  print_elem("flag_19", frame->payload.flag_19, 0);
  print_elem("flag_20", frame->payload.flag_20, 0);
  print_elem("flag_21", frame->payload.flag_21, 0);
  print_elem("flag_22", frame->payload.flag_22, 0);
  print_elem("flag_23", frame->payload.flag_23, 0);
  print_elem("adc_3", frame->payload.adc_3, 0);
  print_elem("flag_24", frame->payload.flag_24, 0);
  print_elem("flag_25", frame->payload.flag_25, 0);
  print_elem("flag_26", frame->payload.flag_26, 0);
  print_elem("flag_27", frame->payload.flag_27, 0);
  print_elem("flag_28", frame->payload.flag_28, 0);
  print_elem("flag_29", frame->payload.flag_29, 0);
  print_elem("adc_4", frame->payload.adc_4, 0);
  print_elem("flag_30", frame->payload.flag_30, 0);
  print_elem("flag_31", frame->payload.flag_31, 0);
  print_elem("flag_32", frame->payload.flag_32, 0);
  print_elem("flag_33", frame->payload.flag_33, 0);
  print_elem("flag_34", frame->payload.flag_34, 0);
  print_elem("flag_35", frame->payload.flag_35, 0);
  print_elem("adc_5", frame->payload.adc_5, 0);
  print_elem("flag_36", frame->payload.flag_36, 0);
  print_elem("flag_37", frame->payload.flag_37, 0);
  print_elem("flag_38", frame->payload.flag_38, 0);
  print_elem("flag_39", frame->payload.flag_39, 0);
  print_elem("flag_40", frame->payload.flag_40, 0);
  print_elem("flag_41", frame->payload.flag_41, 0);
  print_elem("adc_6", frame->payload.adc_6, 0);
  print_elem("flag_42", frame->payload.flag_42, 0);
  print_elem("flag_43", frame->payload.flag_43, 0);
  print_elem("flag_44", frame->payload.flag_44, 0);
  print_elem("flag_45", frame->payload.flag_45, 0);
  print_elem("flag_46", frame->payload.flag_46, 0);
  print_elem("flag_47", frame->payload.flag_47, 0);
  print_elem("adc_batt_voltage", frame->payload.adc_batt_voltage, 0);
  print_elem("acceleration_x", frame->payload.acceleration_x, 0);
  print_elem("acceleration_y", frame->payload.acceleration_y, 0);
  print_elem("acceleration_z", frame->payload.acceleration_z, 0);
  print_elem("pitch_rate", frame->payload.pitch_rate, 0);
  print_elem("roll_rate", frame->payload.roll_rate, 0);
  print_elem("yaw_rate", frame->payload.yaw_rate, 0);
  print_elem("gyro_temp", frame->payload.gyro_temp, 0);
  print_elem("altitude_lsb", frame->payload.altitude_lsb, 0);
  print_elem("altitude_csb", frame->payload.altitude_csb, 0);
  print_elem("altitude_msb", frame->payload.altitude_msb, 0);
  print_elem("alt_temp_lsb", frame->payload.alt_temp_lsb, 0);
  print_elem("alt_temp_msb", frame->payload.alt_temp_msb, 0);
  print_elem("gps_time", frame->payload.gps_time, 0);
  print_elem("lattitude", frame->payload.lattitude, 0);
  print_elem("longitude", frame->payload.longitude, 0);
  print_elem("ground_speed", frame->payload.ground_speed, 0);
  print_elem("course_over_ground", frame->payload.course_over_ground, 0);
  print_elem("gps_sample_time", frame->payload.gps_sample_time, 1);
  printf(",\n");

  print_elem("crc" ,frame->crc, 1);
}

int main(int argc, char* argv[]) {
  unsigned char data[LENGTH]; 
  hex_to_bytes(argv[1], &data); 

  struct telemetry_api_frame* frame = parse_frame(data);
  print_frame(frame);
}

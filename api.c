#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "api.h"

#define LENGTH 64

struct telemetry_api_frame* parse_frame (char* data) {
  return (struct telemetry_api_frame *) data;
}

int main(int argc, char* argv[]) {

  for (int i = 1; i < argc; i++) {
    printf("%s", argv[i]);
  }

  char* raw[LENGTH];
  memcpy(buffer, argv[1], length);

  printf("\n");

  struct telemetry_api_frame* frame = malloc(sizeof(struct telemetry_api_frame));

  frame->source_address = 1;
  frame->destination_address = 1;
  frame->payload_type = 0;
  frame->length = 20;
  frame->crc_present = 1;
  
  int length = sizeof(*frame);
  
  char buffer[length];
  memcpy(buffer, frame, length);

  printf("Length: %d\n",  length);

  for (int i = 0; i < length; i++) {
    printf("%x", buffer[i]);
  }

  printf("\n");
}

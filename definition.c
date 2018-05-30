struct telemetry_frame;
struct telemetry_api_frame;
struct telemetry_api_frame* make_frame(char* data);

uint16_t get_length (struct telemetry_api_frame* frame);

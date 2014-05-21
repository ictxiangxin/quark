#ifndef _VIDEO_CHARACTER_H_
#define _VIDEO_CHARACTER_H_

void initialize_video_character();

void set_start_location(u32 start);
u32 get_start_location();
void set_cursor_location(u32 cursor);
u32 get_cursor_location();
void write_character(u16 data, u32 location);

#endif

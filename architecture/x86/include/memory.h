#ifndef _MEMORY_H_
#define _MEMORY_H_

void physical_memory_copy(void* source, void* destination, u32 size);
void physical_memory_fill(void* address, u32 size, u8 data);

#endif

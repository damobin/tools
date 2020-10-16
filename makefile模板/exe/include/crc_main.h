#ifndef CRC_MAIN_H
#define CRC_MAIN_H
#include <public.h>
#include <crc_table.h>
uint __fastcall crc_16(byte *buf,int len);
void ExcStrToBytes(byte *Obj,byte *Src);
#endif
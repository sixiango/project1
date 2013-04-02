				{
					static const char lfnunicode_offset_table[13]={0x01,0x03,0x05,0x07,0x09,0x0E,0x10,0x12,0x14,0x16,0x18,0x1C,0x1E}; 
					for (i = 0; i < 13; i++) {
						u16 b0=((u8*)&lfn)[(int)(lfnunicode_offset_table[i])+0];
						u16 b1=((u8*)&lfn)[(int)(lfnunicode_offset_table[i])+1];
						lfnNameUnicode[lfnPos + i] = (b1<<8) | b0;
					}
				}

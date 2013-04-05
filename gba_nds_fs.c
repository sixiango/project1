/*
 ============================================================================
 Name        : gba_nds_fs.c
 Author      : liang.zhou
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "gba_nds_fat.h"

int console_server();
static unsigned char buff_seq[678] = {0};
int main(int argc, char *argv[]) {
	//fs init
	int i = 0;
	char new_file_name[256] = {0};
	FAT_FILE *pfile_rand_new = NULL;
		
	if (argc < 2)
	{
		printf("syntax:gba_nds_fs img_file\n");
		return 0;
	}

	disc_io_set_image(argv[1]);
	FAT_InitFiles();

	//FAT_mkdir("xxxx");

	for (i = 0; i < sizeof(buff_seq);i++)
	{
		buff_seq[i] = i%256;
	}
	srand(time(NULL));
	sprintf(new_file_name, "new_%d", rand()%10000);
	if ( pfile_rand_new = FAT_fopen(new_file_name, "wb+"))
	{
		ftk_logi("%s opend\n", new_file_name);
		//FAT_fwrite(buff_seq, 32, sizeof(buff_seq)/32, new_file_name);
//		FAT_fwrite(buff_seq, 32, 1, pfile_rand_new);

		FAT_fclose(pfile_rand_new);
	}
	else
	{
		ftk_logi("%s open faied\n", new_file_name);
	}


	//console server startup

	console_server();

	FAT_FreeFiles();
	disc_Shutdown();


	return EXIT_SUCCESS;
}

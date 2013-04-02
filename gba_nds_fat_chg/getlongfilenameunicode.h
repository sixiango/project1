/*-----------------------------------------------------------------
FAT_GetLongFilenameUnicode
Get the long name of the last file or directory retrived with 
	GetDirEntry. Also works for FindFirstFile and FindNextFile
char* filename: OUT will be filled with the filename, should be at
	least 256 bytes long
bool return OUT: return true if successful
-----------------------------------------------------------------*/
bool FAT_GetLongFilenameUnicode (Tunicode* filename)
{
	int i;
	if (filename == NULL)
		return false;
	for (i =0; (i < MAX_FILENAME_LENGTH - 1) && (lfnNameUnicode[i] != 0); i++)
	{
		filename[i] = lfnNameUnicode[i];
	}
	filename[i] = 0;
	if (!lfnExists)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string getNextAvailableFilename(const string prefix) {
	string result = prefix;
	string asterix = '*';

	strcat(prefix,asterix);

	TFileHandle fhandle;
    TFileIOResult IOResult;
    string resFileName = "";
    int resFileSize = 0;

    FindFirstFile(fhandle, IOResult, prefix, resFileName, resFileSize);

    if(resFileSize == 0) {
    	string one = '1';
    	strcat(result,one)
    } else {
    	string result = 'unknown';
    }

    return result;
}

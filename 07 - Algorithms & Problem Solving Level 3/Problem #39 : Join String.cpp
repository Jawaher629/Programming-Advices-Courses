string JoinString(vector <string> vWords, string Delim)
{
	string Sent1 = "";
	for (string& s : vWords)
	{
		Sent1 += s + Delim;
	}
	return Sent1.substr(0, Sent1.length() - Delim.length());
	
}

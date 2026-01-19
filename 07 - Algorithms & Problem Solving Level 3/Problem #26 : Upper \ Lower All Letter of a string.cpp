string UpperCaseAllString(string Sentence1)
{
	for (short i = 0; i < Sentence1.length(); i++)
	{
		Sentence1[i] = toupper(Sentence1[i]);
	}
	return Sentence1;
}


string LowerCaseAllString(string Sentence1)
{
	for (short i = 0; i < Sentence1.length(); i++)
	{
		Sentence1[i] = tolower(Sentence1[i]);
	}
	return Sentence1;
}

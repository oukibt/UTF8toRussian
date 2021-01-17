// UTF-8 to Russian by oukibt

native decode(string[], len = sizeof string);
native encode(string[], len = sizeof string);

/*
example
{
	new string[100] = "Р_С_РёР_РчС', Р_РёС_!";
	decode(string);
	printf("%s", string); // "Привет, Мир!"
	
	encode(string);
	printf("%s", string); // "Р_С_РёР_РчС', Р_РёС_!"
}
*/
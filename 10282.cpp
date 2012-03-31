#include <iostream>

using std::cin;
using std::endl;
using std::cout;

main()
{
	char **dictionary[26];
	char **data[26];
	char temp2[10];
	char temp[10];
	int position[26];
	int i,j;
	int judge;
	for (i=0;i<26;i++)
		dictionary[i]=new char*[10000],data[i]=new char*[10000],position[i]=0;
	for (i=0;i<26;i++)
		for (j=0;j<10000;j++)
			dictionary[i][j]=new char[10],data[i][j]=new char[10];
	while (1)
	{
		temp[0]=cin.get();
		if (temp[0]=='\n') break;
		for (i=1;;i++)
		{
			temp[i]=cin.get();
			if (temp[i]==' ')
			{
				temp[i]='\0';
				strcpy(temp2,temp);
				break;
			}
			if (temp[i]=='\n')
			{
				temp[i]='\0';
				strcpy(dictionary[temp[0]-'a'][position[temp[0]-'a']],temp);
				strcpy(data[temp[0]-'a'][position[temp[0]-'a']++],temp2);
				break;
			}
		}
	}
	while (cin>>temp)
	{
		judge=1;
		for (i=0;i<position[temp[0]-'a'];i++)
			if (strcmp(dictionary[temp[0]-'a'][i],temp)==0) 
			{
				cout<<data[temp[0]-'a'][i]<<endl;
				judge=0;
				break;
			}
		if (judge) cout<<"eh"<<endl;
	}
	return 0;
}





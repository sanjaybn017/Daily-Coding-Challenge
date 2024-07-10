/*doc
Name : Sanjay B N
Date : 10-07-2024
Description : Reverse the middle word of a string
Sample input : hi hello how are you
Sample output : hi hello woh are you
doc*/

#include<stdio.h>
#include<string.h>

//Function to reverse a string
void reverse_word(char *begin, char* end)
{
    while( begin <= end )
    {
	char temp = *begin;
	*begin++ = *end;
	*end-- = temp;
    }
}

int main()
{
    //read input string
    char inp_string[50];
    printf("Enter a string with odd number of words\n");
    scanf("%[^\n]",inp_string);

    //count the number of words
    int word_count = 0;
    int len = strlen(inp_string);

    for(int i = 0; i < len; i++)
    {

	if( i < len-1 && inp_string[i] != ' ' && inp_string[i+1] == ' ' )
	{
	    word_count++;
	}
    }
    if( inp_string[len-1] != ' '){ 
    	word_count++;
    }

    //find the staring and end index of the middle string
    int start,end, i = 0,count = 0;
    if( inp_string[0] == ' '){
	count--;
    }
    while( count <= (word_count/2) )
    {
	//move till middle word i.e word_count/2 
	if( inp_string[i] == ' ' && inp_string[i+1] != ' ' )
	{
	    count++;
	}
	if( count == word_count/2 )
	{
	    start = ++i;
	    //move the i pointer till it reaches next ' ' character
	    while( inp_string[i] != ' '){
		i++;
	    }
	    end = i-1;
	    reverse_word(&inp_string[start],&inp_string[end]);
	    break;
	}
	i++;
    }

    printf("Final o/p: %s\n",inp_string);


    return 0;
}



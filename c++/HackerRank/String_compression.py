/*The problem given to us is to compress a string in which if a character is reperated in a charater then it s next index should contain
no of cosecutive repitetion.
	ex:	passaasssaaaassst
	ans:	pas2a2s3a4s3t
*/

//approach using vector

void stringCompression(char input[])
{
 
    int n=strlen(input);
    if(n==1||n==0)
    {
    	return;    
    }
    vector<char> ans;
    for(int i=0;i<n;i++)
    {
    
        char element=input[i];
        int count=1;
        ans.push_back(element);
        for(int j=i+1;j<n;j++)
        {
            if(input[j]==element)
            {
                	count++;
            }
            if(input[j]!=element)
            {	if(count>1)
                    {	char countchar=count+'0';
                        ans.push_back(countchar);
                    }
             i=j-1;          
             break;
            }
        }

    }
    int j;
    for(j=0;j<ans.size();j++)
    {
        input[j]=ans[j];
    }
    for(;j<n;j++)
    {
        input[j]='\0';
    }

}




//intutive approach 

void stringCompression(char input[]) {
int count = 1;
char currentChar = input[0];
int i, nextIndex = 1;
for(i = 1; input[i] != '\0'; i++) {
// Count the occurrence of consecutive duplicate character
if(input[i] == currentChar) {
count++;
}
else {
// Append the count with string
	if(count > 1) {
	input[nextIndex] = char(count + 48);
	nextIndex++;
	}
	currentChar = input[i];
	input[nextIndex] = input[i];
	nextIndex++;
	count = 1;
	}
}
if(count > 1) {
input[nextIndex] = char(count + 48);
nextIndex++;
}
input[nextIndex] = '\0';
}

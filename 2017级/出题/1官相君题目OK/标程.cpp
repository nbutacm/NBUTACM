#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int match(string& target,string& pattern)
{
    int target_length = target.size();
    int pattern_length = pattern.size();
    int target_index = 0;
    int pattern_index = 0;
    while(target_index < target_length && pattern_index < pattern_length)
    {
        if(target[target_index]==pattern[pattern_index])
        {
            ++target_index;
            ++pattern_index;
        }
        else
        {
            target_index -= (pattern_index-1); 
            pattern_index = 0;
        }
    }
    if(pattern_index == pattern_length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
	string a,b;
	int r;
	
	cin>>r;
	while(r--)
	{
		cin>>a>>b;
		reverse(b.begin(),b.end());
		
		if(match(a,b))
		{
			cout<<"Y"<<endl;
		}else
		{
			cout<<"N"<<endl;
		}
	}
    
    return 0;
}

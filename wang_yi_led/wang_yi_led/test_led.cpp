#include<iostream>
#include<string>
#include<vector>

using namespace std;
char numbs[10]={0x77,0x24,0x5D,0x6D,0x2E,0x6B,0x7B,0x25,0x7F,0x6F};

void finder(vector<char> a,vector<char> &result)
{
	//vector<char> tmp; 
	int a_size=a.size();
	int map[10]={0,0,0,0,0,0,0,0,0,0};
	for(auto flag:a)
	{
		for (char i=0;i<10;i++)
		{
			if((1<<flag-1)&numbs[i])
			{
				map[i]++;
			}
		}
	}
	for (int i=0;i<10;i++)
	{
		if(map[i]==a_size)
		{
			result.push_back(i);
		}
	}
	
}

int main()
{
	int ts_n;
	//string ts_ns;
	//getline(cin,ts_ns);
	//ts_n=ts_ns[0]-48;
	cout<<"ts_n:"<<endl;
	cin>>ts_n;
	int ts_flag=0;
	
	while(ts_flag<ts_n){
		string row_Ns;
		vector<string> str_result;
		int row,N;
		vector<int> tmp_N;
		
		//getline(cin,row_Ns);
		//row=row_Ns[0]-48;
		//N=row_Ns[1]-48;
		cout<<"row and N:"<<endl;
		cin>>row>>N;
		while(N)
		{
			tmp_N.push_back(N%10);
			N=N/10;
		}
		cout<<endl;
		string tmp_str;
		int row_flag=0;
		string tmp="";
		getline(cin,tmp_str);
		while(row_flag<row){
			cout<<"please input tmp_str"<<endl;
			getline(cin,tmp_str);
			vector<char> light_led;
			vector<char> led;
			
			for(auto c:tmp_str)
			{
				if(c!=' ')
				{
					light_led.push_back(c-48);
				}
			}
			finder(light_led,led);
			if (row_flag==0&&tmp_N.size()<row){
					tmp="0";
				}
			else{
			for(auto c:led)
			{
				//cout<<c<<endl;
				
				tmp=tmp+(char)(c+48);
			//	if(c*pow(10,row-1-row_flag)>N)
					
			}
			}
			str_result.push_back(tmp);
			tmp="";
			row_flag++;
		}
		for(auto s:str_result)
		cout<<s<<endl;
		
		ts_flag++;
	}
	
	return 0;
}
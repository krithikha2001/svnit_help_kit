#include<bits/stdc++.h>
using namespace std;
struct initial{ 
	int x;
	int y;
	int h;
};
struct skyline{ 
int x;
int h;
int f; //flag if 1 then start of building if 0 then end of building
};
struct initial c[]={ //input
					{31, 41, 5},
					{4, 9, 21},
					{30, 36, 9},
					{14, 18, 11},
					{2, 12, 14},
					{34, 43, 19},
					{23, 25, 8},
					{14, 21, 16},
					{32, 37, 12},
					{7, 16, 7},
					{24, 27, 10}
				};
vector<struct skyline> in;
vector<struct skyline> out;
int size=0;
void make_input(vector<struct skyline> &in);
void sort(int n);
void make_output(vector<struct skyline> &out); 
int main()
{
	int i;
	make_input(in);
	sort(in.size());
	cout<<"\n\nBuilding coords (Sorted input)are : "<<endl;
	for(i=0;i<in.size();i++)
	{
	cout<<"( "<<in[i].x<<" , "<<in[i].h<<" )"<<"\t";
	}
	make_output(out); //skyline function
}
void make_input(vector<struct skyline> &in) 
{
	int i;
	cout<<"\n\nEntered input  was : "<<endl;
	for(i=0;i<11;i++)
	{
		cout<<"( "<<c[i].x<<" , "<<c[i].h<<" , "<<c[i].y<<" ) "<<"\t";
	}
	struct skyline s;
	for(i=0;i<11;i++)
	{
		s.x=c[i].x;
		s.h=c[i].h;
		s.f=1;
		in.push_back(s);
		s.x=c[i].y;
		s.h=c[i].h;
		s.f=0;
		in.push_back(s);
	}
		cout<<"\n\nNow modified input  is : "<<endl;
	for(i=0;i<in.size();i++)
	{
		cout<<"( "<<in[i].x<<" , "<<in[i].h<<" ) "<<"\t";
	}
}
void sort(int n) //for sorting
{
	int i;
	for(int i = 0 ; i < in.size() ; i++)
	{
		bool swap = false;
		for (int j = 0 ; j < in.size()-i-1 ; j++)
		{
			if(in[j].x > in[j+1].x)
			{
				int x1, h1, f1;				//swapping both
				x1 = in[j].x;
				h1 = in[j].h;
				f1 = in[j].f;
				in[j].x = in[j+1].x;
				in[j].h = in[j+1].h;
				in[j].f = in[j+1].f;
				in[j+1].x = x1;
				in[j+1].h = h1;
				in[j+1].f = f1;
				swap = true;
			}
		}
		if(!swap)
			break;
	}
}
void make_output(vector<struct skyline> &out) 								//skyline function
{
	vector<int> height; //height vector is made such that it is sorted in descending order
	int temp,prev=0,max;
	struct skyline s1,s2,s3;
	int i,j,l;
	for(i=0;i<in.size();i++)
	{
		temp=in[i].h;
		if(in[i].f==1) //start of building
		{
			if(height.empty()==true) //no height in the vector
			{
				if(i!=0) //to append the points when a skyline starts
				{
					s1.x=in[i-1].x;
					s1.h=0;
					s1.f=0; //flags not relavent
					out.push_back(s1);
					size++;
				}
				else
				{ 						//for first case initalise x and h with 0
					s1.x=0;
					s1.h=0;
					s1.f=1; 
					out.push_back(s1);
					size++;
				}
					height.push_back(temp); 
			}
			else //height vector not empty
			{
				for(j=0;j<height.size();j++) 
				{
					if(temp>=height[j])
						break;
				}
				height.push_back(0);
				for(l=height.size()-1; l>j; l--) //shifting right
				{
					height[l]=height[l-1];
				}
					height[j]=temp; //height added to vector
			}
			max=height[0]; //since its  in desc order max is in start of height vector
		}
		else //f==0 i.e. end of building
		{
			auto k=find(height.begin(),height.end(),temp); 
			height.erase(k);
			max=height[0];
		}
	
		if(prev!=max)
		{
			s3.x=in[i].x;
			s3.h=max;
			s3.f=1;
			if(size!=0) //size here is size of out
			{
				s2.x=out[size-1].x;
				s2.h=out[size-1].h;
				s2.f=out[size-1].f;
				if(s2.x==s3.x)
				{
					if(s2.h<s3.h)
					{
					out.pop_back(); //to remove repeated pts
					out.push_back(s3); 
					}
				}
				else
				{
					out.push_back(s3); 
				}
			}
			else
			{
				out.push_back(s1); //appending the original point
			}
			size++;
			prev=max; //changing previous max height
		}
	}
	s3.x=in[i-1].x; //appending the last point 
	s3.h=0;
	s3.f=1;
	out.push_back(s3);
	
	cout<<"\n\nSkyline output is : "<<endl;
	for(i=1;i<out.size();i++)
	{
		cout<<"( "<<out[i].x<<" , "<<out[i].h<<" ) "<<endl;
	}
}


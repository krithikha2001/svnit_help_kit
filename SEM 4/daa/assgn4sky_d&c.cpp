#include <bits/stdc++.h>
using namespace std;
struct input{ 
	int x;
	int y;
	int h;
};
struct sky{ 
	int x;
	int y;
};
vector<struct input> in{ 
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
vector<struct sky> out; 
vector<struct sky> mergesky(vector<sky> sky_l,vector<struct sky> sky_h);
vector<struct sky> skyline(int l, int h,vector<struct input> sky1);

int main()
{
	out=skyline(0,in.size()-1,in);
	out.insert(out.begin(),{0,0});
	int i;
	cout<<"Skyline output for Divide and Conquer method!\n";
	for(i=1;i<out.size();i++) 
	{
		if(out[i].x!=-1)				//we made it to remove redundant pts
		{
			cout<<"( "<<out[i].x<<" , "<<out[i].y<<" ) ";
			cout<<endl;
		}
	}
	return 0;
}
vector<struct sky> merge(vector<struct sky> sky_l,vector<struct sky> sky_h)
{
	int h_l=0, h_h=0;
	int ind=0;
	int i=0,j=0;
	vector<struct sky> merged_sky; 
	while(i < sky_l.size() && j<sky_h.size())
	{
		if(sky_l.empty() || sky_h.empty())
		{
			break;
		}
		struct sky temp;
		if(sky_l[i].x < sky_h[j].x) 
		{
			temp.x=sky_l[i].x;
			temp.y=sky_l[i].y;
		//if the height of selected coordinate is less than previous height of other skyline then update height of the coordinate of point to be inserted 
			if(sky_l[i].y < h_h)
			{
				temp.y=h_h;
			}
			h_l=sky_l[i].y; //changing h_l which is previous height of sky_l vector
			i++; 
		}
		else if(sky_l[i].x > sky_h[j].x) //similar with sky_h vector
		{
			temp.x=sky_h[j].x;
			temp.y=sky_h[j].y;
			if(sky_h[j].y < h_l)
			{
				temp.y=h_l;
			}
			h_h = sky_h[j].y;
			j++;
		}
		else 					//if both are equal then point would be the x coordinate of either one y would be max height
		{ 				
			temp.x = sky_h[j].x;
			temp.y = max(sky_l[i].y,sky_h[j].y);
			h_l = sky_l[i].y;
			h_h = sky_h[j].y;
			i++;
			j++;
		}
		merged_sky.push_back(temp);
	}
	if(i>= sky_l.size()) //adding the remaining points of sky_l
	{
		while(j< sky_h.size())
		{
			merged_sky.push_back(sky_h[j]);
			j++;
		}
	}
	if(j>= sky_h.size()) //adding the remaining points of sky_h
	{
		while(i< sky_l.size())
		{
			merged_sky.push_back(sky_l[i]);
			i++;
		}
	}
	int inx = 1;
	vector<int> redundant;
	redundant.push_back(0);
	while(inx < merged_sky.size()) 
	{
		if(merged_sky[inx].y == merged_sky[inx-1].y)
		{
			redundant.push_back(1);
		}
		else
		{
		redundant.push_back(0);
		}
		inx++;
	}
	for(i=0;i<redundant.size();i++)
	{
		if(redundant[i]==1)
		{
			merged_sky[i].x=-1;
		}
	}
	return merged_sky;
}
vector<struct sky> skyline(int l,int h,vector<struct input> sky1)
{
	vector<struct sky> sky_line;
	if(l > h) 
	{
		return sky_line;
	}
	else if(l==h)
	{
		struct sky p={sky1[l].x,sky1[l].h};
		sky_line.push_back(p);
		p.x=sky1[l].y;
		p.y=0;
		sky_line.push_back(p);
		return sky_line;
	}
	else 
	{
		int mid=l+((h-l)/2);
		vector<struct sky> sky_l=skyline(l,mid,sky1);
		vector<struct sky> sky_h=skyline(mid+1,h,sky1);
		return merge(sky_l,sky_h);
	}
}


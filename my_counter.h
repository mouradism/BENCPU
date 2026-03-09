#pragma once
class my_counter
{
private:
	bool Enable,load,edg=0,clk=0;
	int data=0;
public:
	void updateState(bool Enable, bool load, int data,bool clk);
	int loadData(bool &Enable,bool&load, int &data);
	int count(bool&clk,bool&Enable,bool&load);


};
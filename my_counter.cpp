#include "my_counter.h"


void my_counter::updateState(bool Enable, bool load, int data, bool clk)
{
	if (clk > this->clk)edg = 1;
	if (clk < this->clk)edg = 0;
	this->clk = clk;
	this->data = data;
	this->Enable = Enable;
	this->load = load;
}

int my_counter::loadData(bool& Enable, bool& load, int& data)
{
	if (!Enable || !load)
		return this->data;
	if (Enable && load) {
		this->data = data;
		return this->data;
	}
}

int my_counter::count(bool& clk, bool& Enable, bool& load)
{
	if (!Enable || !load || !edg)
		return this->data;
	if (Enable && load) {
		this->data = data;
		return this->data;
	}
}
